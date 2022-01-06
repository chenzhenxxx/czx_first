#include<stdio.h>
#include <math.h>
int a[21][2];
int ds,n;
int min=1000000000;
int book[21];
void dfs(int step,int x,int y)
{  int tx=1,ty=0;
    if(step==n)
	return;

	for(int i=0;i<n;i++)
	{   if(book[i]==0)
		{   book[i]=1;
			tx=x*a[i][0];
		   ty=y+a[i][1];
		  ds=tx-ty;
		if(fabs(ds)<min)
		min=fabs(ds);
		dfs(step+1,tx,ty);
		book[i]=0;
		}
	}
	return;


}
main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d %d",&a[i][0],&a[i][1]);
	dfs(0,1,0);
	printf("%d",min);

}