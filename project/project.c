#include "strbuf.h"


void strbuf_init(struct strbuf *sb, size_t alloc) {
    
    
    sb->len=0;
    sb->alloc=alloc;
    sb->buf=(char*)malloc((sb->alloc+1)*sizeof(char));

}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc) {
    sb->len=len;
    sb->alloc=alloc;
    sb->buf = (char *) str;
}

void strbuf_release(struct strbuf *sb) 
{      
        free(sb->buf);
    
}

void strbuf_swap(struct strbuf *a, struct strbuf *b) {
    int len, alloc;
    char *p;
    len = a->len;
    a->len = b->len;
    b->len = len;

    alloc = a->alloc;
    a->alloc = b->alloc;
    b->alloc = alloc;
    p = a->buf;
    a->buf = b->buf;
    b->buf = p;
}

char *strbuf_detach(struct strbuf *sb, size_t *sz) {
    *sz = sb->alloc;
    return sb->buf;
}


int strbuf_cmp(const struct strbuf *first, const struct strbuf *second) {
    if (first->len > second->len)
        return 1;
    else if (first->len == second->len)
        return 0;
    else
        return -1;
}


void strbuf_reset(struct strbuf *sb)
{  
    for(int i=0;i<sb->len;i++)
    sb->buf[i]='\0';
     sb->len=0;
     

}


void strbuf_grow(struct strbuf *sb, size_t extra) 
{     
     if(sb->alloc> sb->len+extra)
    return;
     else
    sb->alloc=sb->len+extra;
    int x;
    x=sb->alloc;
    sb->buf = (char *) realloc(sb->buf, sizeof(char) * (x+1));
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len) 
{ 
    if(sb->len+len>sb->alloc)   
    {
        strbuf_grow(sb,len+1);
    }

    for(int i = 0;i < len  ;i++)
    {
            sb->buf[sb->len+i] = ((char *)data)[i];
    }
    sb->len+=len;
    sb->buf[sb->len]='\0';



}


void strbuf_addch(struct strbuf *sb, int c) 
{
   if(sb->len+2>sb->alloc)
   {
       strbuf_grow(sb,2);
   }
   sb->buf[sb->len]=(char)c;
   sb->len++;
   sb->buf[sb->len]='\0';
}

void strbuf_addstr(struct strbuf *sb, const char *s) 
{   strbuf_add(sb,s,strlen(s));
     


}



void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2) {


    strbuf_add(sb,sb2->buf,strlen(sb2->buf));

}

void strbuf_setlen(struct strbuf *sb, size_t len) 
{
    sb->len = len;
    sb->buf[len]='\0';
}

size_t strbuf_avail(const struct strbuf *sb) {
    return sb->alloc ? sb->alloc - sb->len-1 : 0;
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
 {
     if (pos > (sb->len - 1)) {
        sb->len += len;
        if ((sb->len) > sb->alloc)
        {
            strbuf_grow(sb,len);
        }
        sb->buf = (char *) realloc(sb->buf, sizeof(char) * (sb->alloc));
        strcat(sb->buf, (const char *) data);
    } 
    else {
        sb->len += len;
        char *p;
        p = (char *) malloc(sizeof(char) * (sb->len));
        strcpy(p, &sb->buf[pos]);
        sb->buf[pos] = '\0';
        if ((sb->len) > sb->alloc)
        {
            strbuf_grow(sb,len);
        }
        sb->buf = (char *) realloc(sb->buf, sizeof(char ) * (sb->alloc));
        strcat(sb->buf, (const char *) data);
        strcat(sb->buf, p);
        free(p);
    }
}


void strbuf_ltrim(struct strbuf *sb) 
{  char p[sb->len+1];
int i,flag=1;
int count=0;
   for(i=0;i<sb->len;i++)
   {
       if(sb->buf[i]!=' '&&sb->buf[i]!='\t'&&sb->buf[i]!='\n')
       {
           flag=0;
       }
       if(flag==1&&(sb->buf[i]==' '||sb->buf[i]=='\t'||sb->buf[i]=='\n'))
       {
           continue;
       }

       p[count++]=sb->buf[i];
   }

   for(i=0;i<count;i++)
   {
       sb->buf[i]=p[i];
   }
   sb->buf[count]='\0';
   sb->len=count;
}


void strbuf_rtrim(struct strbuf *sb) 
{
     while(sb->buf[sb->len-1]==' '||sb->buf[sb->len-1]=='\t'||sb->buf[sb->len-1]=='\n')
     {  sb->buf[sb->len-1]='\0';
         sb->len--;

     }

}

void strbuf_remove(struct strbuf *sb, size_t pos, size_t len) {
    char *p = &sb->buf[pos + len];

    sb->buf[pos] = '\0';
    strcpy(&sb->buf[pos], p);
    sb->len -= len;
}


ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint)

{   
    FILE *fp;
    if ((fp = fdopen(fd, "r")) == NULL) {
        printf("can't open the file\n");
          sb->len=strlen(sb->buf);
         return sb->len;
    }

       char ch;
      if((ch=fgetc(fp))==EOF)
      return sb->len;

  else{
       sb->buf[sb->len++]=ch;
       sb->alloc+=8192;
      sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->alloc));
     while ((ch=fgetc(fp))!=-1) 
    { 
       sb->buf[sb->len++]=ch;
    }
    sb->buf[sb->len]='\0';
   return sb->len;
  }
}

ssize_t strbuf_read_file(struct strbuf *sb, const char *path, size_t hint) 

{   char *p;
    p=(char*)malloc(sizeof(char)*8193);
    FILE *fp;
    size_t len=0;
    if ((fp = fopen(path, "r")) == NULL) {
        printf("can't open the file\n");
        exit(1);
    }
    sb->alloc += hint?hint:8192;
    while (getline(&p,&len,fp)!=-1) 
    { 
     continue;  
    }
    while(sb->len+strlen(p)>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->len+=strlen(p);
    sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->alloc));
    strcat(sb->buf,p);
    free(p);
    return sb->len;
}

int strbuf_getline(struct strbuf *sb, FILE *fp) 
{  
    char ch;
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n'||feof(fp))
        break;
        if(sb->alloc<sb->len)
       {
        strbuf_grow(sb,1);
       }

        strbuf_addch(sb,ch);
    }
    return sb->len;

}


struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max) 
{     char q[2]; 
      q[0]=(char)terminator;
      q[1]='\0';
      int count=0,i;
      
     struct strbuf **p=NULL;
       p=(struct strbuf**)realloc(p,sizeof(struct strbuf*)*(count+1));
     struct strbuf *k;
      
       char s[len+1];
       memcpy(s,str,len+1);
    
       for(i=0;i<len;i++)
       {
           if(s[i]=='\0')
           s[i]='{';

       }
      char*r=strtok(s,q);//分割字符串函数。
      while(r!=NULL&&count<max)
      {   int r_len=strlen(r);
          for(i=0;i<r_len;i++)
          {
              if(r[i]=='{')
              r[i]='\0';
          }
          k=(struct strbuf*)malloc(sizeof(struct strbuf));
         {
          strbuf_init(k,r_len+1); //'\0'
          strbuf_add(k,r,r_len);
         }
          p[count++]=k;
          p=(struct strbuf**)realloc(p,sizeof(struct strbuf*)*(count+1));
          r=strtok(NULL,q);

      }
      p[count]= NULL;
      return p;
}

bool strbuf_begin_judge(char *sb, const char *string,int len) {
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(sb[i]=='\0'||string[i]=='\0')
        break;
        if(sb[i]!=string[i])
        {
           flag=1;
        }
    }
    if (flag == 0)
       return true;
    else
      return false;
}
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len)
{    int i,count=0;
    if(target_buf == NULL)
        return NULL;
    char * p = (char *)malloc((end - begin + 1)*sizeof (char));
    for(i=begin;i<=end;i++)
    p[count++]=target_buf[i];
    p[end - begin] = '\0';
    return p;
}