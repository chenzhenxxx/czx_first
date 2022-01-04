#include <stdio.h>
#include <stdlib.h>
main()
{  char*p;
   p=(char*)malloc(sizeof(char)*5);
    memcpy(p, "xiyou", 5);
    char *q;
    q=(char*)malloc(sizeof(char)*(4));
    strcpy(q,&p[1]);

    p[1]='\0';
    strcat(p,"aaa");
    strcat(p,q);
    puts(p);
}