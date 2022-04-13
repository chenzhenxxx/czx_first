#include<stdio.h>
#include<errno.h>
#include<linux/limits.h>
#include<sys/stat.h>
#include<dirent.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include"mshell.h"
int cnt=1;
char *arglist[256];
char cdform[100][100]; //用来 cd -
int cd_cnt=0;
int main(int argc,char **argv)
{   
    strcpy(cdform[0],"/home/chenzhenxin/");
    char **arg=NULL;
  signal(SIGINT, SIG_IGN);  //屏蔽信号
    while(1)
    { 
      cnt=0;
      print_prompt();
      char *buf=readline("\001\002MYshell $:");
      read_history(NULL);
      add_history(buf);
      get_cmd(buf,arglist);

     if( strcmp(arglist[0], "exit") == 0 || strcmp(arglist[0], "logout") == 0)
     {
         break;
     }
     if(strcmp(arglist[0],"cd")==0)
     {
         cmd_cd(arglist);
         continue;
     }

     cnt--;
     do_cmd(cnt);
     free(buf);
    }

    
     exit(0);
}

void print_prompt()
{
    char hostname[50];
    gethostname(hostname,50);
    struct passwd* username;
    username=getpwuid(getuid());
    char path[256];
    getcwd(path,256);
    int x;
    char m;
    x=geteuid();
    if(x==0)
    m='#';
    else
    m='$';
    char colorhost[100];
    char colorusername[PATH_MAX];
    char  colorpath[PATH_MAX];
    sprintf(colorhost,"\033[%dm%s\033[0m",32,hostname);
    sprintf(colorusername,"\033[%dm%s\033[0m",33,username->pw_name);
    sprintf(colorpath,"\033[%dm%s\033[0m",31,path);
    printf("%s@%s:%s%c",colorhost,colorusername,colorpath,m);
}



void get_cmd(char *buf,char *arglist[256])
{    cnt=0;
    char *p;
    char *delim=" ";
    p=strtok(buf,delim);
    arglist[cnt++]=p;
    while(p!=NULL)
     {
        p=strtok(NULL,delim);
        arglist[cnt++]=p;
     }
     arglist[cnt]=NULL;
     return;
     
}

int find_cmd(char *command)
{
DIR *dp;
    struct dirent *dirp;
    char *path[] = {"./", "/bin", "/usr/bin", NULL};
    if( strncmp(command, "./", 2) == 0 )
    {
       command = command + 2;
    }
    

    
    int i = 0;
    while(path[i] != NULL)
    {
        if( (dp= opendir(path[i])) ==NULL )
        {
            printf("can not open /bin \n");
        }
        while( (dirp = readdir(dp)) != NULL )
        {
            if(strcmp(dirp->d_name, command) == 0)
            {
                closedir(dp);
                return 1;
            }
        }
        closedir(dp);
        i++;
    }
    return 0;

}

int cmd_cdx(int left,int right)
{    
   int endindex=right;
   int flag=0; 
     int outnum=0,innum=0,ooutnum=0;
     char *infile=NULL,*outfile=NULL,*ooutfile=NULL;
     if (!find_cmd(arglist[left])) 
		return -1;
		
    for(int i=left;i<right;i++)
     {
         if(strcmp(arglist[i],">")==0)
          {
              outnum++;
               if(endindex==right)  //记录第一次
                 endindex=i;
                 if(i+1<right)
                  { 
                   outfile=arglist[i+1]; 
                  }
          }
          if(strcmp(arglist[i],">>")==0)
          {
              ooutnum++;
              
               if(endindex==right)  //记录第一次
                 endindex=i;
                 if(i+1<right)
                  ooutfile=arglist[i+1]; 
          }

           if(strcmp(arglist[i],"<")==0)
          {
              innum++;
               if(endindex==right)  //记录第一次
                 endindex=i;
                 if(i+1<right)
                  infile=arglist[i+1];
          }
          if(strcmp(arglist[i],"&")==0)
           {
               if(i+1!=right)
               {
                   printf("the & position is wrong.\n");

               }
               else
                flag=1; //后台运行

           }
          
     }
         if(innum>1)
          {   
              printf("< is too \n");
              return -1;
          }
          else if(outnum>1)
           {   
               printf("> is too\n");
               return -1;
           }
           else if(ooutnum>1)
           {   
               printf(">> is too\n");
               return -1;
           }
           else
            {   
                if(innum==1)
                {   
                   int fd=open(infile,O_RDONLY);
                     if(fd<0)
                      {
                          printf("the infile is not exit\n");
                          return -1;
                      }
                      close(fd);
                }
                
                pid_t pid;
                pid=vfork();

                if(pid==-1)
                {
                    printf("vfork error\n");
                    return -1;
                }
                else if(pid==0)
                 {
                     if(innum==1)
                      {   
                         
                          freopen(infile, "r", stdin);

                      }
                      if(outnum==1)
                      {   
                           freopen(outfile, "w", stdout);
                      }
                      if(ooutnum==1)
                      {   
                          freopen(ooutfile, "a+", stdout); //追加
                      }

                      char *command[100];
                      
                      for( int i=left;i<endindex;i++)
                        {
                            command[i]=arglist[i];
                        }
                        command[endindex]=NULL;
                        execvp(command[left],command+left);
                        exit(0);
                 }
                 else 
                 {
                     int status;
                     if(flag!=1)  //没有后台运行符
		             waitpid(pid, &status, 0);
                     
                 }
            }
             return 1;
}

int cmd_pipe(int left,int right)
{  
    if(left>=right)
    return 0;
	int pipeindex=-1;
    
    for(int i=left;i<right;i++)
     {
         if(strcmp(arglist[i],"|")==0)
          {
              pipeindex=i;
              break;
          }
     }
     
     if(pipeindex==-1)
     {   
         cmd_cdx(left,right);
         return 1;
     }
     if(pipeindex+1==right)
      {
          printf("behind the | need a command\n");
          return -1;
      }
      int fd[2];
      if(pipe(fd)==-1)
      {    
          printf("pipe error\n");
          return -1;
      }

      pid_t pid;
      pid=vfork();
      if(pid==-1)
      {
          printf("pid error\n");
          return -1;
      }
       else if(pid==0)
        {
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
            close(fd[1]);
            cmd_cdx(left,pipeindex);
            exit(0);
        }
        else 
         {   int status;
             waitpid(pid,&status,0);

           
              if(pipeindex+1<right)
               {    close(fd[1]);
                    dup2(fd[0],STDIN_FILENO);
                    close(fd[0]);
                  cmd_pipe(pipeindex+1,right);
               }
         }
         return 1;

}

void do_cmd(int cnt)
{ 
          pid_t pid=vfork();
          if(pid==-1)
          {
              printf("vfork error\n");
               return ;
          }
          else if(pid==0)
           {
               int inFd=dup(0);
               int outFd=dup(1);
               
               cmd_pipe(0,cnt);

               dup2(inFd, STDIN_FILENO);
		       dup2(outFd, STDOUT_FILENO);
               exit(0);
           }
           else
           {
               int status;
               waitpid(pid,&status,0);
           }

}
void cmd_cd(char *arglist[256])
{    
    if(arglist[1]==NULL)
    {
        return;
    }

    if(strcmp(arglist[1],"-")!=0&&strcmp(arglist[1],"~")!=0) 
    {     char buf[100];
          getcwd(buf,sizeof(buf));
          strcpy(cdform[++cd_cnt],buf);
    }

     if(strcmp(arglist[1],"~")==0)
    {
        strcpy(arglist[1], "/home/chenzhenxin/");
    }

     else if(strcmp(arglist[1],"-")==0)
    {   if(cd_cnt>0)
        {
        strcpy(arglist[1],cdform[cd_cnt]);
        }
        else 
        strcpy(arglist[1],cdform[0]);
        cd_cnt--;
    }
    
    if(chdir(arglist[1])==-1)
    {
        printf("chdir error\n");
    }
   
    return;
}

