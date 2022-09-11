#include<iostream>
using namespace std;
void delect_x(int *arry,int* size)
{  int elem;
   cout<<"请输入要删除的元素"<<endl;
   cin>>elem;
   int k=0;//记录有多少个要删除的元素
   for(int i=0;i<*size;i++)
   {
      if(arry[i]==elem)
      k++;
      else 
      arry[i-k]=arry[i]; //覆盖
   }
   *size=*size-k;
}
void Print(int *arry,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arry[i]<<" ";

    }
    cout<<endl;
}
int main()
{   
    int size;
    printf("请输入个数！");
    cin>>size;
    int arry[size+1];
   for(int i=0;i<size;i++)
   {
     cin>>arry[i];
   }
   Print(arry,size);
   delect_x(arry,&size);
   Print(arry,size);
}