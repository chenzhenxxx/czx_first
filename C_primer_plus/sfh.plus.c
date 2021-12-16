#include<stdio.h>
#include<string.h>
main()
{   int len,flag=0,count=0;
	char a[500001];
	char *p[250000];
	gets(a);
	len=strlen(a);
	 for(int i=0;i<len;i++)
	 {  if(a[i]==' ')
	    {  if(flag==1)
		    {
			  flag=0;
		      a[i]='\0';
			}

	    }
		else
		{
			if(flag==0)
			{
				p[count++]=&a[i];
				flag=1;
			}
		}

	 }

	 for(int i=count-1;i>0;i--)
	 {
		 printf("%s ",p[i]);
	 }
	 if(p[0]!=NULL)
	 printf("%s",p[0]);

}