#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main()
{   vector<int> s(5,10);
    cout<<accumulate(s.cbegin(),s.cend(),0)<<endl;

}