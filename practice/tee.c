#include <stdio.h>
#include <readline/readline.h>
#include<readline/history.h>
#include "tlpi_hdr.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_READ 1024   

int readline (int fd,char *buf,int size)
{
        int count=0,byte=0;
        char *str;
        str=buf;
        while(count<size)
         {
                 byte=read(fd,buf,1);
                 if(byte==-1)
                 errExit("read");
                 if(byte==0)
                   break;
                 if(*str=='\n')
                   break;
                   str++;

         }
        return count;
}

int main (int argc,char **argv)
{
          int opt,flags,fd,byte;
          char buf[MAX_READ+1],*file;

          if(argc>3)
          {
                  usageErr("%s [-a] <file>\n",argv[0]);

          }
          opt=getopt(argc,argv,"a:");
          if(opt==':'||opt=='?')
           usageErr("%s [-a] <file>\n",argv[0]);
           switch(opt)
           {
                   case 'a':
                       flags=O_APPEND | O_WRONLY | O_CREAT;
                       file=optarg;
                       break;
                   default:
                       flags= O_WRONLY |O_TRUNC |O_CREAT;
                       file=argv[1];
                       break;
           }
           if(file==NULL)
           fd=STDOUT_FILENO;
           else
            fd=open(file,flags,0644);

            while(1)
            {
                     if(fd==-1)
                     errExit("write");
                     byte=readline(STDIN_FILENO,buf,MAX_READ);
                     buf[byte]='\0';
                     if(write(fd,buf,byte)==-1)
                     errExit("write");
                     if(write(fd,"\n",1)==-1)
                     errExit("write");

            }
      
          close(fd);
          exit(EXIT_SUCCESS);
           
}
