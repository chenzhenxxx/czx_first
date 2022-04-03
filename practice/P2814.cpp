#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<string,string> p;

string find(string x)
{
    if(p[x]!=x)
    p[x]=find(p[x]);
    return p[x];
}
int main()
{
    string name,father;
    char a;
    while((a=getchar())!='$')
    { 
      cin>>name;
      while(getchar()!='\n');
      if(a=='#')
      {    if(p[name] == "")
          p[name]=name;
          father=name;
      }
      else if(a=='+')
      p[name]=father;
      else 
      {
          cout<<name<<' '<<find(name)<<endl;
      }
      
    }
     return 0;
}