#include<stdio.h>
#include<math.h>
main()
{
    int l,n,cnt=0;
    int ans[11];
    scanf("%d %d",&l,&n);
    int pos=pow(26,l)-n;
    while(l--)
    {   ans[cnt++]=pos%26;
        pos=pos/26;
        
    }
    for(int i=cnt-1;i>=0;i--)
    {
        printf("%c",'a'+ans[i]);
    }
}