#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{   string str;
    while(getline(cin,str))
    {
        string s;
        for(auto c:str)
        if(isalpha(c)) s.push_back(c);

        stable_sort(s.begin(),s.end(),[](char a,char b){return tolower(a)<tolower(b);});
        for(int i=0,j=0;i<str.size();i++)
        {
            if(isalpha(str[i])) cout<<s[j++];
            else
            cout<<str[i];
        }
        cout<<endl;
    }
}