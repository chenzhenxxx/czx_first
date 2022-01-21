#include <stdio.h>
main()
{   int terminator; 
      int i;
      char p[10][30]={0};
    int count=0;
    char str[]="\0ZZ\0\0  123 345  Z  3123  Z 3123  ";
    int len=33;
    char ch='Z';
    int flag=0;
    char result[100];
    int k=0;
    for(i=0;i<len;i++)
    {
        if(flag==0&&str[i]==ch)
        continue;
        else if(flag==0&&str[i]!=ch)
        {
            result[k]=str[i];
            k++;
            flag=1;
        }
        else if(flag==1&&str[i]==ch)
        {
           for(int m=0;m<k;m++)
           p[count][m]=result[m];
           for(int j=0;j<100;j++)
           result[j]='\0';
            flag=0;
            count++;
            k=0;
        }
        else if(flag==1&&str[i]!=ch)
        result[k++]=str[i];
    }
     for(i=0;i<count;i++)
     {
         for(int j=0;j<20;j++)
     {
         printf("%c",p[i][j]);
     }
     printf("\n");
     }

}
    int count=0;
      int i;
     struct strbuf **p;
      p=(struct strbuf**)malloc(sizeof(struct strbuf*));
      char q[2]; 
      q[0]=(char)terminator;
      q[1]='\0';
       char s[len+1];
       for(i=0;i<=len;i++)
       s[i]=str[i];
       //strcpy(s,str);
       struct strbuf *k;
       for(i=0;i<len;i++)
       {
           if(s[i]=='\0')
           s[i]=(char)terminator;

       }
      char*r=strtok(s,q);//分割字符串函数。
      while(r!=NULL&&count<max)
      {

          k=(struct strbuf*)malloc(sizeof(struct strbuf));
         {
          strbuf_init(k,strlen(r)+1); //'\0'
          strbuf_addstr(k,r);
         }
          p[count]=k;
           count++;
          p=(struct strbuf**)realloc(p,sizeof(struct strbuf*)*(count+1));
          r=strtok(NULL,q);

      }
      p[count]= NULL;
      return p;