#include <stdio.h>
main()
{    int n;
     char ch;
     while((ch=getchar())!="#")
     { n++;
     switch(ch)
     {
      case '.':
         printf("!");break;
      case '!':
         printf("!!");break;
      default:
         putchar(ch);
     }
}
}
    