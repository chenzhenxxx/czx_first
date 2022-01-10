#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};
struct strbuf sbuf[101];

//AAAA
strbuf_init(struct strbuf *sb,int alloc)
{   sb->len=0;
    sb->alloc=alloc;
    sb->buf=(char*)malloc(sizeof(char)*(sb->alloc)); 
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t mem)
{
    sb->len=len;
    sb->buf=(char *)malloc(sizeof(char)*mem);
     memcpy(sb->buf, str, len);
    sb->alloc=mem;
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
strbuf_reset(struct strbuf *sb)
{
    sb->buf=NULL;
    sb->len=0;
}



////  BBBBBB

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
    strcat(sb->buf,c);
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
}
static inline size_t strbuf_avail(const struct strbuf *sb)
{
    return sb->alloc ? sb->alloc - sb->len -1: 0;
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{    
     if(pos>=(sb->len-1))
    {    sb->len+=len;
        if((sb->len)>sb->alloc)
       { sb->alloc*=2;

        }
     sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
        strcat(sb->buf,data); 
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



///CCCCCC


void strbuf_rtrim(struct strbuf *sb)
{   int delete_len=0;
    char *p=sb->buf;
    while(*p==' '||*p=='\t'||*p=='tab')
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
     while(*p==' '||*p=='\t'||*p=='tab')
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



////////DDDDDDDDDD


ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint)

{  char txt[8193];
    FILE*fp;
    if((fp=fdopen(fd,"r"))==NULL)
    {   printf("can't open the file\n");
        exit(1);
    }
    sb->alloc+=(hint?hint:8192);
    if(hint!=0)
    realloc(sb->buf,sb->alloc*(sizeof(char)));
     char ch;
     while(fgets(txt,255,fp)!=NULL)
     		strcat(sb->buf,txt);
   
    sb->len=strlen(sb->buf);
    if(fclose(fp)!=0)
    {
        printf("can't close the file.\n");
        exit(1);
    }
}

ssize_t strbuf_read_file(struct strbuf *sb, const char *path, size_t hint)
{
    FILE*fp;
    char txt[8193];
    if((fp=fopen(path,"r"))==NULL)
    {   printf("can't open the file\n");
        exit(1);
    }
    sb->alloc+=hint ? hint : 8192;
    if(hint!=0)
    realloc(sb->buf,sb->alloc*(sizeof(char)));
    char ch;
     while(fgets(txt,255,fp)!=NULL)
     		strcat(sb->buf,txt);
    sb->len=strlen(sb->buf);
    if(fclose(fp)!=0)
    {
        printf("can't close the file.\n");
        exit(1);
    }


}

int strbuf_getline(struct strbuf *sb, FILE *fp)
{
   char txt[300];
   fgets(txt,255,fp);
   sb->len+=strlen(txt);
   while(sb->len>sb->alloc)
   { sb->alloc*=2;
     realloc(sb->buf,sizeof(char)*(sb->alloc));

   }
   strcat(sb->buf,txt);
}

struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max)
{ 
  int count=1,i=0,index=0;
  while(str[i]!='\0'&&count!=max)
  {   int len;
      char txt [1000];
      while(str[i]!=terminator)
      txt[i]=str[i++];
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
         strcat(sbuf[max].buf,str[i+1]);
     }
    return  &sbuf;
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
        return p;

       
    }
    if(c=='y')
    {
        p=sb->buf[begin];
       return p;
    }



}

int main() {
  struct strbuf sb;
  strbuf_init(&sb, 10);
  strbuf_attach(&sb, "  xiyou", 7, 10);
  puts(sb.buf);
  
  strbuf_insert(&sb,7,"hello ",6);
  puts(sb.buf);

  strbuf_rtrim(&sb);
  puts(sb.buf);

  printf("%d",strlen(sb.buf));
  strbuf_ltrim(&sb);
  puts(sb.buf);

  printf("%d",strlen(sb.buf));
  printf("\n");
  strbuf_remove(&sb,3,6);
   puts(sb.buf);
   printf("%d",sb.len);


  strbuf_read_file(&sb,"/home/chenzhenxin/Desktop/czx_first/student.txt",0);
   puts(sb.buf);
   printf("%d",sb.len);


   FILE*fpf;
   fpf=fopen("/home/chenzhenxin/Desktop/czx_first/student.txt","r");
   strbuf_getline(&sb,fpf);
   puts(sb.buf);


   char*p;
   p=getbuf(0,6,&sb,p);
   puts(p);
   free(p);


   judge(&sb,"xiyo");



   struct strbuf sq;
  strbuf_init(&sq, 10);
  strbuf_attach(&sq, "666", 3, 10);
  
  
  strbuf_swap(&sb,&sq);
  puts(sb.buf);
 strbuf_release(&sb);
   strbuf_release(&sq);
}