#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void func1(char*a,char*b);
void func2(char*a,char*b);
void func3(char*a,char*b);
void func4(char*a,char*b);
int main(int argc, char const *argv[])
{  if(argc!=4)
   {
       fprintf(stderr,"please input enough data to %s:\n",argv[0]);
       exit(EXIT_FAILURE);
   }
   char ch;
   ch=argv[3][0];
   switch(ch)
   {
       case '1':func1(argv[2],argv[3]);
       break;
       case '2':func2(argv[2],argv[3]);
       break;
       case '3':func3(argv[2],argv[3]);
       break;
       case '4':func4(argv[2],argv[3]);
       break;
   }
    
    return 0;
}
void func1(char*a,char*b)
{
    putchar('\n');
    while(*a&&*b)
    {
        int x=((*a)-'0')&((*b)-'0');
        putchar(x+'0');
        a++;
        b++;
    }
    putchar('\n');

}
void func2(char*a,char*b)
{
    putchar('\n');
    while(*a&&*b)
    {
        int x=((*a)-'0')|((*b)-'0');
        putchar(x+'0');
        a++;
        b++;
    }
    putchar('\n');

}
void func3(char*a,char*b)
{
    putchar('\n');
    while(*a&&*b)
    {
        int x=((*a)-'0')^((*b)-'0');
        putchar(x+'0');
        a++;
        b++;
    }
    putchar('\n');

}
void func4(char*a,char*b)
{
    putchar('\n');
    while(*a)
    {
        int x=(((*a)-'0')+1)%2;
        putchar(x+'0');
        a++;
    }
    putchar('\n');
    while(*b)
    {
        int x=(((*b)-'0')+1)%2;
        putchar(x+'0');
        b++;
    }
  putchar('\n');
}