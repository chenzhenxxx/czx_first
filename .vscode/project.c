#include <stdio.h>
#include <stdlib.h>
struct strbuf {
  int len;     //当前缓冲区（字符串）长度
  int alloc;   //当前缓冲区（字符串）容量
  char *buf;   //缓冲区（字符串）
};
strbuf_init(struct strbuf *sb,int cslen)
{
    sb->alloc=cslen;
}
void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t mem)
{
    sb->len=len;
    sb->buf=(char *)malloc(sizeof(char)*len);
    sb->buf=str;
    sb->alloc=mem;
}
void strbuf_release(struct strbuf *sb)
{
    free(sb->buf);
    free(sb);
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
    if(sizeof(first)>sizeof(second))
     return 1;
     else if(sizeof(first)==sizeof(second))
     return 0;
     else
     return -1;
}
strbuf_reset(struct strbuf *sb)
{
    sb->len=0;
    sb->alloc=0;
    sb->buf=NULL;
}
char *strbuf_detach(struct strbuf *sb, size_t *sz)
{
    
}
int main() {
  struct strbuf sb;
  strbuf_init(&sb, 10);
  strbuf_attach(&sb, "xiyou", 5, 10);
  puts(sb.buf);
}