#include<stdio.h>
#include<linux/limits.h>
#include<sys/stat.h>
#include<dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#define normal 0
#define out_readirect 1 //>
#define in_readirect 2  //<
#define outt_readirect 3 //>>
#define pipe 4    // |
void print_prompt()
{
    char hostname[50];
    gethostname(hostname,50);
    struct passwd* username;
    username=getpwuid(getuid());
    char path[PATH_MAX+1];
    getcwd(path,PATH_MAX+1);
    int x;
    char m;
    x=geteuid();
    if(x==0)
    m='#';
    else
    m='$';
    char colorhost[50];
    char colorusername[PATH_MAX];
    char  colorpath[PATH_MAX];
    sprintf(colorhost,"\033[%dm%s\033[0m",32,hostname);
    sprintf(colorusername,"\033[%dm%s\033[0m",33,username->pw_name);
    sprintf(colorpath,"\033[%dm%s\033[0m",31,path);
    printf("%s@%s:%s%c",colorhost,colorusername,colorpath,m);
}
void get_cmd(char *buf)
{
      int len=0;
      int  ch;
      ch=getchar();
      while(ch!='\n'&&len<256)
       {
           buf[len++]=ch;
           ch=getchar();
       }
       if(len==256)
        {
            printf("command is too long\n");
            exit(-1);
        }
        buf[len]='\n';
        len++;
        buf[len]='\0';

}
void explain_cmd(char *buf,int *cnt,char (*arglist)[256])
{
    char *p = buf;
    char *q = buf;
    int number = 0;
    int i;
    while(1)
    {
        if(p[0] == '\n')
        {
            break;
        }

        if(p[0] == ' ')
        {
            p++;
        }
        else 
        {
            q = p;
            number = 0;
            while((q[0] != ' ') && (q[0] != '\n'))
            {
                if(q[0] == 92)
                {
                    q[0] = ' ';
                    q[1] = q[2];
                    for(i = 2; ; i++)
                    {
                        q[i] = q[i+1];
                        if((q[i] == ' ') || (q[i] == '\n'))
                        break;
                    }
                }
                number++;
                q++;
            }
            strncpy(arglist[*cnt], p, number + 1);
            arglist[*cnt][number] = '\0';
            *cnt=*cnt+1;
            p = q;
        }
    }
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
void do_cmd(int cnt,char (*arglist)[256])
{   int i,flag=0,how=0,m=0;
    int background=0;
    int status,status2;
    char *arg[cnt+1];
    char *argnext[cnt+1];
    char *file;
    pid_t pid,pid2;
    int fd;
    for(i=0;i<cnt;i++)
     arg[i]=(char*)arglist[i];
     arg[cnt]=NULL;
    for(i=0;i<cnt;i++)
     {
         if(strncmp(arg[i],"&",1)==0)
          {
              if(i==cnt-1)
               {
                   background=1;
                   arg[cnt-1]=NULL;
                   break;
               }
              else 
              {
                  printf("& position is wrong \n");
                  return ;
              }
          }
     }

     for(int i=0;arg[i]!=NULL;i++)
      {
          if(strcmp(arg[i],">")==0)
           {
               flag=1;
               how=out_readirect;
               if(arg[i+1]==NULL)
                {
                    flag++;
                }
                
           }
           if(strcmp(arg[i],">>")==0)
           {
               flag=1;
               how=outt_readirect;
               if(arg[i+1]==NULL)
                {
                    flag++;
                }
                
           }
           if(strcmp(arg[i],"<")==0)
           {
               flag=1;
               how=in_readirect;
               if(i==0)
                {
                    flag++;
                }
                
           }
           if(strcmp(arg[i],"|")==0)
           {
               flag=1;
               how=pipe;
               if(arg[i+1]==NULL)
                {
                    flag++;
                }
                if(i==0)
                {
                    flag++;
                }
           }
      }

       if(flag>1)
       {
           printf("the command is wrong \n");
           return ;
       }

       if(how==out_readirect)
        {
            for(int i=0;arg[i]!=NULL;i++)
             {
                 if(strcmp(arg[i],">")==0)
                  {   file=arg[i+1];
                      arg[i]=NULL;
                      
                  }
             }
        }
         if(how==outt_readirect)
        {
            for(int i=0;arg[i]!=NULL;i++)
             {
                 if(strcmp(arg[i],">>")==0)
                  {   file=arg[i+1];
                      arg[i]=NULL;
                  }
             }
        }
         if(how==in_readirect)
        {
            for(int i=0;arg[i]!=NULL;i++)
             {
                 if(strcmp(arg[i],"<")==0)
                  {   file=arg[i+1];
                      arg[i]=NULL;
                      break;
                  }
             }
        }
         if(how==pipe)
        {
            for(int i=0;arg[i]!=NULL;i++)
             {  int j;
                 if(strcmp(arg[i],"|")==0)
                  {   
                      arg[i]=NULL;
                      for( j=i+1;arg[j]!=NULL;j++)
                       argnext[j-i-1]=arg[j];
                       
                       argnext[j-i-1]=arg[j];
                      break;
                  }
             }
        }
         if((arg[0]!=NULL)&&(strcmp(arg[0],"cd")==0))
         {
             if(arg[1]==NULL)
             {
                 return ;

             }
             if(strcmp(arg[1],"~")==0)
              {
                    strcpy(arg[1],"/home/chenzhenxin");
              }
              if(chdir(arg[1])==-1)
               {
                   perror("cd");
               }
               return ;
         }

         if((pid=fork())<0)
          {
              printf("fork error\n");
              return ;
          }
          switch(how)
           {   case 0 : 
               if(pid==0)
                {    
                             
                              if(!(find_cmd(arg[0])))
                                   {   
                                 printf("%s :command not found 301\n",arg[0]);
                                    exit(0);
                                   }
                    execvp(arg[0],arg);
                    exit(0);
                }
                break;

                case 1:  //>
                 if(pid==0)
                  {
                      
                         
                   if(!(find_cmd(arg[0])))
                      {
                          printf("%s :command not found 316\n",arg[0]);
                          exit(0);
                      }
                            fd=open(file,O_RDWR|O_CREAT|O_TRUNC,0644);
                            dup2(fd,1);
                            execvp(arg[0],arg);
                            exit(0);
                       
                  }
                  break;
                   case 2:   //<
                 if(pid==0)
                  {
                              
                  if(!(find_cmd(arg[0])))
                      {
                          printf("%s :command not found 332\n",arg[0]);
                          exit(0);
                      }
                            fd=open(file,O_RDONLY,0644);
                            dup2(fd,0);
                            execvp(arg[0],arg);
                            exit(0);
                       
                  }
                  break;
                   case 3:      //|
                 if(pid==0)
                  {
                       if(pid2=fork()<0)
                        {
                            printf("fork() error\n");
                            return ;
                        }
                        if(pid2==0)
                          {      
                   if(!(find_cmd(arg[0])))
                      {
                          printf("%s :command not found 354\n",arg[0]);
                          exit(0);
                      }
                              fd=open("/home/chenzhenxin/1.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
                              dup2(fd,1);
                              execvp(arg[0],arg);
                              exit(0);
                          }
                          if(waitpid(pid2,&status2,0)==-1)
                           {
                               printf("wait for child process error\n");
                           }

                           if( !(find_cmd(argnext[0])) )
                         {
                           printf("%s : command not found 369\n", argnext[0]);
                           exit(0);
                         }

                         fd=open("/home/chenzhenxin/1.txt",O_RDONLY,0644);
                              dup2(fd,0);
                              execvp(argnext[0],argnext);
                              exit(0);

                  }
                  break;
                   
                  case 4:    //>>
                 if(pid==0)
                  {
                            
                        if(!(find_cmd(arg[0])))
                      {
                          printf("%s :command not found 387\n",arg[0]);
                          exit(0);
                      }
                           
                            fd=open(file,O_RDWR | O_CREAT | O_APPEND,0644);
                            dup2(fd,1);
                            execvp(arg[0],arg);
                            exit(0);
                       
                  }
                  break;

                  default: break;

           }


           if(background==1)
           {   printf("process id %d \n", pid);
               return ;
           }

           if(waitpid(pid,&status,0)==-1)
            {
                printf("wait for child process error\n");
            }
}

int main(int argc,char **argv)
{   
    char *buf=NULL;
    int cnt=0;
    char arglist[100][256];
    char **arg=NULL;
    buf=(char *)malloc(sizeof(char)*256);
    if(buf==NULL)
     {
         printf("malloc failed\n");
         exit(-1);
     }
    while(1)
    { memset(buf,0,256);
      cnt=0;
      fflush(stdin);
      
      print_prompt();
 
      get_cmd(buf);

     if( strcmp(buf, "exit\n") == 0 || strcmp(buf, "logout\n") == 0)
     {
         break;
     }
     
    for(int i=0;i<100;i++)
      {
         arglist[i][0]='\0';
      }
    explain_cmd(buf,&cnt,arglist);
 
    do_cmd(cnt,arglist);
   
    }

    if(buf!=NULL)
    {
        
        free(buf);
    }
     exit(0);
}