#include<iostream>
using namespace std;
istream & read(istream& is)
{   string mm;
    while(!is.eof()&&cin>>mm)
    {
        cout<<mm<<endl;
    }
    is.clear();
    return is;
}
int main()
{
       read(cin);
}