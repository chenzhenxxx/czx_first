#include<iostream>
using namespace std;
int main()
{   int ans=0;
    string begin,end;
    cin>>begin;
    cin>>end;
    int state1=0;
    int len=begin.size()-1;
    for(int i=0;i<len;i++)
    {
        if(begin[i]!=end[i])
        {
            if(begin[i]=='*') 
            begin[i]='o';
            else begin[i]='*';
            if(begin[i+1]=='*') 
            begin[i+1]='o';
            else begin[i+1]='*';
            ans++;
        }
    }
    cout<<ans<<endl;
        
  
    
    
}