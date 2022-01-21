#include <strbuf.h>
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};
struct strbuf sbuf[101];

//AAAA

void strbuf_init(struct strbuf *sb,size_t alloc)
{   sb->len=0;
    sb->alloc=alloc;
    sb->buf=(char*)malloc(sizeof(char)*(sb->alloc)); 
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
    sb->len=len;
    sb->alloc=alloc;
    while(sb->len>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->buf=realloc(sb->buf,sizeof(char)*(sb->alloc));
    strcat(sb->buf,(char*)str);
}

void strbuf_release(struct strbuf *sb)
{
    free(sb->buf);
    sb->buf=NULL;
}

void strbuf_swap(struct strbuf *a, struct strbuf *b)
{
    struct strbuf t;
    t=*a;
    *a=*b;
    *b=t;
}

char *strbuf_detach(struct strbuf *sb, size_t *sz)
{   
    *sz=sb->len;
    return sb->buf;
}


int strbuf_cmp(const struct strbuf *first, const struct strbuf *second)
{   
    if(first->alloc>second->alloc)
     return 1;
     else if(first->alloc==second->alloc)
     return 0;
     else
     return -1;
}


void strbuf_reset(struct strbuf *sb)

{
    sb->buf=NULL;
    sb->len=0;
}



// BBBBBB

void strbuf_grow(struct strbuf *sb, size_t extra)
{
    while(sb->len+extra>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->len+=extra;
    sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->alloc));

}

void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    sb->len+=len;
    while(sb->len>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->alloc));
    strcat((sb->buf),(char*)data);

}

void strbuf_addch(struct strbuf *sb, int c)
{
    sb->len+=1;
    while(sb->len>sb->alloc)
    {  sb->alloc*=2;
     
    }
    sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
    sb->buf[sb->len+1]=c;
}

void strbuf_addstr(struct strbuf *sb, const char *s)
{
    strbuf_add(sb, s, strlen(s));

}

void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2)
{
    sb->len+=sb2->len;
    while(sb->len>sb->alloc)
     {  sb->alloc*=2;
     
    }
    sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
    strcat(sb->buf,((sb2)->buf));
}

static inline void strbuf_setlen(struct strbuf *sb, size_t len)
{
    sb->len=len;
    while(sb->len>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->buf=(char*)malloc(sizeof(char)*(sb->alloc));
}

static inline size_t strbuf_avail(const struct strbuf *sb)
{
    return sb->alloc?sb->alloc - sb->len:0;
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{    
     if(pos>=(sb->len-1))
    {    sb->len+=len;
        if((sb->len)>sb->alloc)
       { sb->alloc*=2;

        }
     sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
        strcat(sb->buf,(const char * restrict)data); 
    }
    else
    { sb->len+=len;
      char *p;
     p=(char*)malloc(sizeof(char)*(len-pos));
     strcpy(p,&sb->buf[pos]);
     sb->buf[pos]='\0';
     if((sb->len)>sb->alloc)
     { sb->alloc*=2;

     }
     sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
     strcat(sb->buf,data);
     strcat(sb->buf,p);
     free(p);
    }
}



//CCCCCC


void strbuf_rtrim(struct strbuf *sb)
{   int delete_len=0;
    char *p=sb->buf;
    while(*p==10||*p==9||*p==' ')
    {
        p++;
        delete_len++;
    }
    strcpy(sb->buf,p);
    sb->len-=delete_len;
}


void strbuf_ltrim(struct strbuf *sb)
{   int delete_len=0;
    char*p=&sb->buf[sb->len-1];
     while(*p==10||*p==9||*p==' ')
    {   *p='\0';
        p--;
        delete_len++;
        
    }
    
    sb->len-=delete_len;
    
}

void strbuf_remove(struct strbuf *sb, size_t pos, size_t len)
{
    char*p=&sb->buf[pos+len];
    
     sb->buf[pos]='\0';
     strcpy(&sb->buf[pos],p);
     sb->len-=len;

}



//DDDDDDDDDD


ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint)

{  char *p;
    FILE*fp;
     size_t len=0;
    p=(char*)malloc(sizeof(char)*8193);
    if((fp=fdopen(fd,"r"))==NULL)
    {   printf("can't open the file\n");
        exit(1);
    }
    sb->alloc+=(hint?hint:8192);
    if(hint!=0)
    sb->buf=realloc(sb->buf,sb->alloc*(sizeof(char)));
     while(getline(&p,&len,fp)!=EOF)
     		{
                 strcat(sb->buf,p);
                 sb->len+=strlen(p);
             }
   
    if(fclose(fp)!=0)
    {
        printf("can't close the file.\n");
        exit(1);
    }
    free(p);
    return sb->len;
}

ssize_t strbuf_read_file(struct strbuf *sb, const char *path, size_t hint)
{
    FILE*fp;
    char *p;
    size_t len;
    p=(char*)malloc(sizeof(char)*8193);
    if((fp=fopen(path,"r"))==NULL)
    {   printf("can't open the file\n");
        exit(1);
    }
    sb->alloc+=hint ? hint : 8192;
    if(hint!=0)
    sb->buf=realloc(sb->buf,sb->alloc*(sizeof(char)));
     while(getline(&p,&len,fp)!=EOF)
     		{
                 strcat(sb->buf,p);
                 sb->len+=strlen(p);
             }
    if(fclose(fp)!=0)
    {
        printf("can't close the file.\n");
        exit(1);
    }
   free(p);
   return sb->len;
 
}

int strbuf_getline(struct strbuf *sb, FILE *fp)
{
   char *p;
   size_t len=0;
   p=(char*)malloc(sizeof(char)*8193);
   if(getline(&p,&len,fp)!=EOF)
   { 
   while(sb->len+strlen(p)>sb->alloc)
   { sb->alloc*=2;
   }
    sb->buf=realloc(sb->buf,sizeof(char)*(sb->alloc));
   strcat(sb->buf,p);
   }
   free(p);
   return sb->len;
}


// challenge
struct strbuf ** strbuf_split_buf(const char *str, size_t len, int terminator, int max)
{ 
  int count=1;
  int i;
  i=0;
  while(str[i]!='\0'&&count!=max)
  {   int len;
      char txt [1000];
      while(str[i]!=terminator)
      {
          txt[i]=str[i];
          i++;
      }

      txt[i]=terminator;
      len=strlen(txt);
      sbuf[count].len=len;
      sbuf[count].alloc=len;
      sbuf[count].buf=(char*)malloc(sizeof(char)*len);
      strcat(sbuf[count].buf,txt);
      count++;
   }
     if(str[i]!='\0'&&count==max)
     {
         sbuf[max].len=len-i;
         sbuf[max].alloc=len-i;
         sbuf[max].buf=(char*)malloc(sizeof(char)*(sbuf[max].len));
         strcat(sbuf[max].buf,&str[i+1]);
     }
    //for(i=1;i<=count;i++)
    //strbuf_release(&sbuf[i]);
    struct strbuf **p;
    struct strbuf *q;
    q=&sbuf[0];
    p=&q;
    return  p;
}

void judge(struct strbuf*sb,const char*string)
{   int len=strlen(string);
    int flag=strncmp(sb->buf,string,len);
    if(flag==0)
    printf("YES\n");
    else
    printf("NO\n");

}


char* getbuf(int begin,int end,struct strbuf *sb,char*p)
{   
    printf("please choice the mode:\n ");
    printf("p:copy mode        y:yinyong mode\n");
    char c;
    c=getchar();
    int count=0;
    if(c=='p')
    {   p=(char*)malloc(sizeof(char)*(end-begin));
        for(int i=begin;i<end;i++)
        p[count++]=sb->buf[i];
        

       
    }
    if(c=='y')
    {
        p=&sb->buf[begin];
    }
    return p;

}
