#include <stdio.h>
#include <ctype.h>
main()
{   int word=0,big=0,small=0,digit=0,punct=0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        if(isalpha(ch))
        word++;
        if(isupper(ch))
        big++;
        if(islower(ch))
        small++;
        if(ispunct(ch))
        punct++;
        if(isdigit(ch))
        digit++;

    }
    printf("word=%d big=%d small=%d punct=%d digit=%d",word,big,small,punct,digit);
}