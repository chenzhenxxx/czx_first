#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    vector<int> a(5,1);
    
    list<int> b(5,2);
    if(a.size()==b.size())
    {
      vector<int>::iterator b1=a.begin();
      list<int>::iterator b2=b.begin();
      for(b1,b2;b1!=a.end()&&b2!=b.end();b1++,b2++)
      {
          if(*b1!=*b2)
          {
              cout<<"not";
              return 0;
          }
      }

    }
    else
    {
        cout<<"not"<<endl;
    }
    cout<<"yes";
    return 0;
}