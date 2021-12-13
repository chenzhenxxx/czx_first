#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char * s_gets(char * st,int n);
int main(int argc, char const *argv[])
{
    FILE*p1,*p2;
    char *tem="tem.txt";
    char a[81];
    printf("please input filename:\n");
    s_gets(a,81);
    if((p1=fopen(a,"r+"))==NULL)
    {
        fprintf(stderr,"the %s can't open\n",a);
        exit(EXIT_FAILURE);

    }
    if((p2=fopen(tem,"w+"))==NULL)
    {
        fprintf(stderr,"the %s can't be write\n",tem);
        exit(EXIT_FAILURE);
    }
    int ch;
    while((ch=getc(p1))!=EOF)
       putc(toupper(ch),p2);
       rewind(p1);
       rewind(p2);
       while((ch=getc(p2))!=EOF)
       putc(ch,p1);
       if(fclose(p1)!=0||fclose(p2)!=0)
       {
           fprintf(stderr,"the files can't be closed\n");
           exit(EXIT_FAILURE);
       }

       remove(tem);
    

    /* code */
    return 0;
}
char * s_gets(char * st,int n)
{
    char  *p;
    int i=0;
    p=fgets(st,n,stdin);
    if(p)
    {
        while(st[i]!='\n'&&st[i]!='\0')
        i++;
        if(st[i]=='\n')
        st[i]='\0';
        else
        while(getchar()!='\n')
        continue;

    }
    return p;
}

