#include<stdio.h>
main()
{
  float a1,b1,a2,b2,c,d;
  scanf("%f %f %f %f",&a1,&b1,&a2,&b2);
  c=a1+a2;
  d=b1+b2;
  printf("(%.1f%+.1fi) + (%f%+.1fi) = ",a1,b1,a2,b2);
  if(c<=0.05&&c>=-0.05)
  {
    if(d>0.05||d<-0.05)
    printf("%.1fi",d);
    else
    printf("0.0");
  }
  if(d<=0.05&&d>=-0.05)
  {
    if(c>0.05||c<-0.05)
    printf("%.1f",c);
  }
  if((c>0.05||c<-0.05)&&(d>0.05||d<-0.05))
  printf("%.1f%+.1fi",c,d);
  printf("\n");


  c=a1-a2;
  d=b1-b2;
  printf("(%.1f%+.1fi) - (%f%+.1fi) = ",a1,b1,a2,b2);
   if(c<=0.05&&c>=-0.05)
  {
    if(d>0.05||d<-0.05)
    printf("%.1fi",d);
    else
    printf("0.0");
  }
  if(d<=0.05&&d>=-0.05)
  {
    if(c>0.05||c<-0.05)
    printf("%.1f",c);
  }
  if((c>0.05||c<-0.05)&&(d>0.05||d<-0.05))
  printf("%.1f%+.1fi",c,d);
  printf("\n");


  c=a1*a2-b1*b2;
  d=a1*b2+a2*b1;
  printf("(%.1f%+.1fi) * (%f%+.1fi) = ",a1,b1,a2,b2);
   if(c<=0.05&&c>=-0.05)
  {
    if(d>0.05||d<-0.05)
    printf("%.1fi",d);
    else
    printf("0.0");
  }
  if(d<=0.05&&d>=-0.05)
  {
    if(c>0.05||c<-0.05)
    printf("%.1f",c);
  }
  if((c>0.05||c<-0.05)&&(d>0.05||d<-0.05))
  printf("%.1f%+.1fi",c,d);
  printf("\n");

  c=(a1*a2+b1*b2)*1.0/(a2*a2+b2*b2);
  d=(b1*a2-a1*b2)*1.0/(a2*a2+b2*b2);
  printf("(%.1f%+.1fi) / (%f%+.1fi) = ",a1,b1,a2,b2);
   if(c<=0.05&&c>=-0.05)
  {
    if(d>0.05||d<-0.05)
    printf("%.1fi",d);
    else
    printf("0.0");
  }
  if(d<=0.05&&d>=-0.05)
  {
    if(c>0.05||c<-0.05)
    printf("%.1f",c);
  }
  if((c>0.05||c<-0.05)&&(d>0.05||d<-0.05))
  printf("%.1f%+.1fi",c,d);
  printf("\n");
}
