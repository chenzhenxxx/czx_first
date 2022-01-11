ssize_t strbuf_read_file(struct strbuf *sb, const char *path, size_t hint)
{
    FILE*fp;
    char *p=(char*)malloc(BUFSIZ);
    if((fp=fopen(path,"r"))==NULL)
    {   printf("can't open the file\n");
        exit(1);
    }
    sb->alloc+=hint ? hint : 8192;
    if(hint!=0)
    realloc(sb->buf,sb->alloc*(sizeof(char)));
    size_t len=0;
     //while(fgets(txt,255,fp)!=NULL)
     		//strcat(sb->buf,txt);
    //sb->len=strlen(sb->buf);
    int sign=0;
      while(sign=getline(&p,&len,fp)!=NULL)
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