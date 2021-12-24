#include <stdio.h>
struct queue
{
    int a[101];
    int head;
    int tail;
}
main()
{ int n;
  scanf("%d",&n);
  int i;
  int a[i];
  struct queue q;
  for(i=0;i<n;i++)
  scanf("%d",&q.a[i]);
  q.head=0;
  q.tail=n;
  while(q.head<q.tail)
  {  printf("%d",q.a[q.head]);
     q.head++;
     q.a[q.tail]=q.a[q.head];
     q.tail++;
     q.head++;
 }


}