#include<stdio.h>
int people[100001];
main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	  	int k;
	  	scanf("%d",&k);
	  	 for(int m=0;m<k;m++)
	  	  {  int l;
	  	  	scanf("%d",&l);
	  	  	people[l]++;
	  	  	
			}
	  }
	  int t,flag=0,cnt=0;
	  scanf("%d",&t);
	  for(int i=0;i<t;i++)
	   { int l;
	      scanf("%d",&l);
	   	if(people[l]==0)
	   	 {  
	   	 	flag=1;
	   	 	if(cnt==0)
	   	 	 {
				 printf("%d",l);
				  cnt++;
			}
			else
			printf(" %d",l);
			people[l]=1;
		}
	   }
	   if(flag==0)
	    printf("No one is handsome\n");
}
