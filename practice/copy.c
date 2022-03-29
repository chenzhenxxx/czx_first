#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char  *argv[])
{
        int fd1,fd2,size,byte;
        struct stat st;
        char ch;

        if(argc!=3)
          usageErr("%s <source file> <des file> \n",argv[0]);
         fd1=open(argv[1],O_RDONLY);
          if (fd1==-1)
           errExit("open 1");
           fd2=open(argv[2],O_WRONLY |O_CREAT |O_TRUNC,0644);
           if(fd2==-1)
           errExit("open 2");
           if(stat(argv[1],&st)==-1)      //把信息载入到结构体
            errExit("stat st");

           size=st.st_size;
           for(int i=0;i<size;i++)
           {
                   lseek (fd1,i,SEEK_SET);
                   lseek(fd2,i,SEEK_SET);
                   byte=read (fd1,&ch,sizeof(ch));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                   if(byte==-1)                                                                                                                                                                                                                                    
                   errExit("read fd1");
                   if(byte==0)
                   continue;
                   byte=write(fd2,&ch,sizeof(ch));
                   if(byte==-1)
                   errExit("write fd2");

           }
           exit(EXIT_SUCCESS);

}
