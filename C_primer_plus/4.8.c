 int fact(int a)
 {
     int s;
     if(a==1)
     return 1;
     else
     s=fact(a-1)*a;
     
     return s;
 }
 #include <stdio.h>
 main()
 {
     int n,m;
     int a,b,c;
     scanf("%d,%d",&n,&m);
     b=fact(m);    
     printf("%d",m);

 }