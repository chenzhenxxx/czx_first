//自己写的第一版错了，忘记在倍数那去模了，靠
// #include <iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// int main()
// {
//   // 请在此输入您的代码
//   int n;
//   cin>>n;
//   int m1,m2;
//   vector<long> a;
//   vector<long> b;
//   cin>>m1;
//   for(int i=0;i<m1;i++)
//   {
//     int tmp;
//     cin>>tmp;
//     a.push_back(tmp);
//   }
//   cin>>m2;
//   for(int i=0;i<m2;i++)
//   {
//     int tmp;
//     cin>>tmp;
//     b.push_back(tmp);
//   }
//   reverse(a.begin(),a.end());
//   reverse(b.begin(),b.end());
//   int w=0;
//   long long maxx=0,minn=0,bei=1;
//   while(m1>0&&m2>0)
//   {
//      int tmp=max(a[w],b[w])+1;
//      if(tmp<2)
//      {
//        tmp=2;
//      }
//      minn = (minn+bei*a[w])%1000000007;
//      maxx = (maxx+bei*b[w])%1000000007;
//      w++;
//      m1--;
//      m2--;
//      bei*=tmp;
//   }
//   while(m1>0){
//     int tmp=a[w]+1;
//     if(tmp<2)
//     {
//       tmp=2;
//     }
//     minn = (minn+bei*a[w])%1000000007;
//     w++;
//     m1--;
//     bei*=tmp;

//   }
//   while(m2>0){
//     maxx = (maxx+bei*b[w])%1000000007;
//     m2--;
//     w++;
//     bei*=n;

//   }
//   cout<<(minn-maxx+1000000007)%1000000007;

//   return 0;
// }

//去模后ok
// #include <iostream>
// #include<bits/stdc++.h>
// const int M = 100010,N=1010,mod = 1000000007;

// long long a[M],b[M],w[M];
// int n;
// int Ma,Mb;
// long long mul[M];
// long long A,B;
// using namespace std;
// int main()
// {
//   // 请在此输入您的代码
//   cin >> n;
//   cin >> Ma;
//   for(int i = Ma;i>=1;i--) cin>>a[i];

//   cin>>Mb;
//   for(int i = Mb;i>=1;i--) cin >> b[i];
  
//   int MM = max(Ma,Mb);
//   for(int i = MM;i>=1;i--)
//   {
//     int tmax=max(a[i],b[i]);
//     w[i]=max(2,tmax+1);
//   }

//   mul[1]=1;
//   for(int i =2;i<=MM;i++)
//   {
//     mul[i] = w[i-1]*mul[i-1]%mod;
//   }

//   for(int i = 1; i<=Ma;i++)
//   {
//     A = (A+a[i]*mul[i])%mod;
//   }

//   for(int i = 1; i<=Mb;i++)
//   {
//     B = (B+b[i]*mul[i])%mod;
//   }
//   cout<<(A-B+mod)%mod <<endl;
//   return 0;
// }


// 题解思路

// #include <iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// int main()
// {
//   // 请在此输入您的代码
//   int n;
//   cin>>n;
//   int m1,m2;
//   vector<long> a;
//   vector<long> b;
//   cin>>m1;
//   for(int i=0;i<m1;i++)
//   {
//     int tmp;
//     cin>>tmp;
//     a.push_back(tmp);
//   }
//   cin>>m2;
//   for(int i=0;i<m2;i++)
//   {
//     int tmp;
//     cin>>tmp;
//     b.push_back(tmp);
//   }
//   reverse(a.begin(),a.end());
//   reverse(b.begin(),b.end());
//   int w=0;
//   long long maxx=0,minn=0,bei=1;
//   while(m1>0&&m2>0)
//   {
//      int tmp=max(a[w],b[w])+1;
//      if(tmp<2)
//      {
//        tmp=2;
//      }
//      minn = (minn+bei*a[w])%1000000007;
//      maxx = (maxx+bei*b[w])%1000000007;
//      w++;
//      m1--;
//      m2--;
//      bei=bei*tmp%1000000007;
//   }
//   while(m1>0){
//     int tmp=a[w]+1;
//     if(tmp<2)
//     {
//       tmp=2;
//     }
//     minn = (minn+bei*a[w])%1000000007;
//     w++;
//     m1--;
//     bei=bei*tmp%1000000007;

//   }
//   while(m2>0){
//     maxx = (maxx+bei*b[w])%1000000007;
//     m2--;
//     w++;
//     bei=bei*n%1000000007;

//   }
//   cout<<(minn-maxx+1000000007)%1000000007;

//   return 0;
// }