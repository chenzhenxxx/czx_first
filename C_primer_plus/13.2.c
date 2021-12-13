#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{   char ch;
    FILE *p1,*p2;
    if(argc!=3)
    {
        printf("Usage: %s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if(p1=fopen("argv[1]","r")!=0)
    {
        printf("Can't open the file\n");
        exit(EXIT_FAILURE);
    }
    if(p2=fopen("argv[2]","w")!=0)
    {
        printf("Can't write the file\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(p1))!=EOF)
    putc(ch,p2);
    if(fclose(p1)!=0||fclose(p2)!=0)
    printf("Can't close the file\n");
    return 0;
}
