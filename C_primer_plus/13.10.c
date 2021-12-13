#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Size 100
int main(int argc, char const *argv[])
{

    long  n;
    FILE *p1;
    char a[Size];
    printf("please input filename:\n");
    scanf("%s",a);
    if ((p1 = fopen(a, "r")) == NULL)
    {
        fprintf(stderr, "the %s file can't read\n",a);
        exit(EXIT_FAILURE);
    }
    printf("please input location:\n");
    while (scanf("%ld", &n) == 1 && n > 0)
    {
        char ch;
        fseek(p1, n, SEEK_SET);
        while ((ch = getc(p1)) != '\n')
            putchar(ch);
            printf("\n");
            rewind(p1);
        printf("please input location:\n");
    }
    if (fclose(p1) != 0)
    {
        fprintf(stderr, "the %s file can't be closed\n", a);
        exit(EXIT_FAILURE);
    }
    return 0;

    /* code */
    
}
