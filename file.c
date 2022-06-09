#include<stdio.h>
int main()
{
    FILE* fp;
    fp=fopen("1.txt","a+");
    fprintf(fp,"hello");
    fclose(fp);


}