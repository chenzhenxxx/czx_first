#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<limits.h>
const int size=CHAR_BIT *sizeof(int);
int returnnum(int n)
{
    int sum=0,m=1;
    for(int i=0;i<size;i++)
    {
    if(m&n)
    {
        sum++;
    }
     m<<=1;
    }
    return sum;
}
int main(int argc,char**argv)
{
    int n;
    scanf("%d",&n);
    printf("%d",returnnum(n));

}