#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
     {
        cin>>a[i];
     }
     set<int> visit;
     visit.insert(0);
     for(int i=0;i<n;i++)
     {
        vector<int>b;
        for(auto it=visit.begin();it!=visit.end();it++)
        {
            int t1=*it+a[i];
            int t2=*it-a[i];
            b.push_back(t1);
            b.push_back(t2);
        }
        for(int j=0;j<b.size();j++)
     {
        visit.insert(fabs(b[j]));
     }

     }
     cout<<visit.size()-1<<endl;
     

}