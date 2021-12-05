#include <stdio.h>
int main(int argc, char const *argv[])
{   int n;
char a[20];
    fgets(a,20,stdin);
    if(argv[1][1] == 'p' || argc == 1)
    {
        puts(a);
    }
    else if(argv[1][1] == 'u')
    {
        toupper(a);
        puts(a);
    }
    else if(argv[1][1] == 'l')
            {
                tolower(a);
                puts(a);
            }
    return 0;
}

