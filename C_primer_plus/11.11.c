#include <ctype.h>
#include <stdio.h>
#include <string.h>
void input(char *p[]);
void ASCII_input(char *p[]);
void len_input(char *p[]);
void first_input(char *p[]);
void menu(char *p);
int first(char *a, char *b);
main()
{
    int i = 0;
    char a[10][20];
    char *p[10];
    for (i = 0; i < 10; i++)
    {
        fgets(a[i], 20, stdin);
        p[i] = a[i];
    }
    menu(p);
    return 0;
}
void input(char *p[])
{
    int i = 0;
    for (i = 0; i < 10; i++)
        puts(p[i]);
}
void ASCII_input(char *p[])
{
    char *t;
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = i + 1; j < 10; j++)
            if (strcmp(p[i], p[j]) > 0)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
    input(p);
}
void len_input(char *p[])
{
    int i, j;
    char *t;
    for (i = 0; i < 10; i++)
        for (j = i + 1; j < 10; j++)
            if (strlen(p[i]) > strlen(p[j]))
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
    input(p);
}
void first_input(char *p[])
{
    int i, j;
    char *t;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            if (first(p[i], p[j]))
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
    input(p);
}

int first(char *a, char *b)
{
    int l1 = 0, l2 = 0, i = 0, j = 0;
    while (a[i] && isspace(a[i]))
        i++;
    while (*a && !isspace(a[i]))
    {
        i++;
        l1++;
    }
     while (b[j] && isspace(b[j]))
        j++;
    while (*b&& !isspace(b[j]))
    {
        j++;
        l2++;
    }
    if (l1 > l2)
        return 1;
    else
        return 0;
}
void menu(char *p)
{
    int n;
    puts("input from 1 to 5 to select from the followed options:");
    puts("1)print      2)ASCII");
    puts("3)Length     4)FWLength");
    puts("5)quit");

    while (scanf("%d", &n) && n != 5)
    {
        switch (n)
        {
        case 1:
            input(p);
            break;
        case 2:
            ASCII_input(p);
            break;
        case 3:
            len_input(p);
            break;
        case 4:
            first_input(p);
            break;
        default:
            break;
        }
    }
}
