#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int len;
char list[11];
bool cmp(char a,char b)
{
    return ((int)a-(int)b);
}
void swap(char &a,char &b){
    char temp=a;
    a=b;
    b=temp;
}
void pai(char list[],int low,int high){
    if(low==high){   
        for(int i=0;i<=low;i++)
            cout<<list[i];
        cout<<endl;
    }else{
        for(int i=low;i<=high;i++){
            swap(list[i],list[low]);
            sort(list+1,list+len-1,cmp);
            pai(list,low+1,high); 
            swap(list[i],list[low]);
        }
    }
}
int main()
{

cin>>list;
len=strlen(list);
pai(list,0,len-1);
return 0;
}