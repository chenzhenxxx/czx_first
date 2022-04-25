#include<bits/stdc++.h>
int mp[500][500],dis[500],book[500],peo[500],people[500],pathnum[500],path[500];
int n,m,s,d;
#define inf 1000000
void dijistra(int s)
{  for(int i=0;i<n;i++)
     dis[i]=inf;
   people[s]=peo[s];
   path[s]=s;
   pathnum[s]=1;
   book[s]=1;
   dis[s]=0;

	 for(int i=0;i<n;i++)
	  {
		  if(mp[s][i]!=inf&&i!=s)
		   {
			   dis[i]=mp[s][i];
			   people[i]=people[s]+peo[i];
			   pathnum[i]=1;
			   path[i]=s;
			   
		   }
	  }

	    for(int i=0;i<n;i++)
               {
				   int min=inf;
				   int index=s;
				   for(int j=0;j<n;j++)
				    {
						if(dis[j]<min&&!book[j])
						 {
							 min=dis[j];
							 index=j;
						 }
					}
                   book[index]=1;
				    
					for(int j=0;j<n;j++)
                     {
						 if(!book[j])
						   {
							   if(dis[j]>dis[index]+mp[index][j])
							     {
									 dis[j]=dis[index]+mp[index][j];
									 people[j]=people[index]+peo[j];
									 pathnum[j]=pathnum[index];
									 path[j]=index;
								 }
								 else if(dis[j]==dis[index]+mp[index][j])
								  {    pathnum[j]+=pathnum[index];
									  if(people[j]<people[index]+peo[j])
									   {
										   people[j]=people[index]+peo[j];
										   path[j]=index;
									   }
								  }
						   }
					 }

			   }
 
 }
using namespace std;
int main()
{
	 int print[500];
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++)
	  cin>>peo[i];

	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	  mp[i][j]=inf;
  
    for(int j=0;j<m;j++)
	 {
		 int x,y,w;
		 cin>>x>>y>>w;
		 w=min(mp[x][y],w);
		 mp[x][y]=w;
		 mp[y][x]=w;
	 }
	 dijistra(s);
	 printf("%d %d\n",pathnum[d],people[d]);
	 int x=d,cnt=0;
	 while(x!=s)
	 {
        print[cnt++]=x;
		x=path[x];
	 }
	 printf("%d",s);
	 for(int i=cnt-1;i>=0;i--)
	 printf(" %d",print[i]);

	
}