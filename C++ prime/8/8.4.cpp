#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
int main()
{   string s="/home/chenzhenxin/1.txt";
    ifstream inn(s,ios::in);//以读模式打开
    ofstream outt("/home/chenzhenxin/2.txt",ios::out); //以写模式打开
    vector<string> v;
    if(inn&&outt)
    {
        string buf;
        while(getline(inn,buf))
          {   outt<<buf<<endl;
              v.push_back(buf);
          }
    }
    inn.close();
    outt.close();

    for(int i=0;i<v.size();i++)
     cout<<v[i]<<endl;

}