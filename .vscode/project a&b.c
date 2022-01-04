#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};
strbuf_init(struct strbuf *sb,int cslen)
{   sb->len=0;
    sb->alloc=cslen;
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
    struct strbuf* t;
    t=a;
    a=b;
    b=t;
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
    sb->len=0;
    sb->alloc=0;
    sb->buf=0;
}
char *strbuf_detach(struct strbuf *sb, size_t *sz)
{   
    *sz=sb->len;
    return sb->buf;
}
void strbuf_grow(struct strbuf *sb, size_t extra)
{
    if(sb->len+extra>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->len+=extra;
    sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->alloc));

}
void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    sb->len+=len;
    if(sb->len>sb->alloc)
    {
        sb->alloc*=2;
    }
    sb->buf=(char*)realloc(sb->buf,sizeof(char)*(sb->alloc));
    strcat((sb->buf),(char*)data);

}
void strbuf_addch(struct strbuf *sb, int c)
{
    sb->len+=1;
    if(sb->len>sb->alloc)
    {  sb->alloc*=2;
     
    }
    sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
    sb->buf[sb->len-1]=(char)c;
}

void strbuf_addstr(struct strbuf *sb, const char *s)
{
    strbuf_add(sb, s, strlen(s));

}
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2)
{
    sb->len+=sb2->len;
    if(sb->len>sb->alloc)
     {  sb->alloc*=2;
     
    }
    sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
    strcat(sb->buf,((sb2)->buf));
}
static inline size_t strbuf_avail(const struct strbuf *sb)
{
    return sb->alloc ? sb->alloc - sb->len - 1 : 0;
}
static inline void strbuf_setlen(struct strbuf *sb, size_t len)
{
    sb->len=len;
}
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{    char *p;
     p=(char*)malloc(sizeof(char)*(len-pos));
     strcpy(p,&sb->buf[pos]);
     sb->buf[pos]='\0';
     if(pos+1+len>sb->alloc)
     { sb->alloc*=2;

     }
     sb->buf=(char*)realloc(sb->buf,sizeof(char*)*(sb->alloc));
     strcat(sb->buf,data);
     strcat(sb->buf,p);
     free(p);
     
    

}
int main() {
  struct strbuf sb;
  strbuf_init(&sb, 10);
  strbuf_attach(&sb, "xiyou", 5, 10);
  puts(sb.buf);
  strbuf_insert(&sb,2,"hello",5);
  puts(sb.buf);
   strbuf_release(&sb);
}