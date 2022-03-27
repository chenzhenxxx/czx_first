#include<stdio.h>
#include<linux/limits.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
int cnt=1;
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
void get_cmd(char buf[256][256])
{   int i = 0;
    cnt=0;
	char *p;
    char tmp[100];
    gets(tmp);
	char delims[] = " ";
	
	strcpy(buf[0],strtok(tmp,delims));
	while(p = strtok(NULL,delims)){
		strcpy(buf[cnt++],p);
		
	}
    buf[cnt][0]=NULL;
    
}
int find_cmd()
void do_cmd();

main()
{   char buf[256][256];
    signal(SIGINT,SIG_IGN);
    while(1)
    { memset(buf,0,sizeof(buf));

    print_prompt();

    get_cmd(buf);
    if(strcmp(buf[0],"exit")==0||strcmp(buf[0],"logout")==0)
    break;

    do_cmd(buf);

    }

    if(buf!=NULL)
    {
        for(int i=0;i<256;i++)
        free(buf[i]);
        free(buf);
    }
     exit(0);
}