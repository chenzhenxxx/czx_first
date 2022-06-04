#include<bits/stdc++.h>
using namespace std;
class Hasptr
{
    public:
    Hasptr();
    Hasptr(const Hasptr &p):ps(new string(*p.ps)),i(p.i){}
    Hasptr(const string &s=string()): ps(new string(s)),i(0){}
    Hasptr& operator=(const Hasptr& p)
    {
        auto new_ps=new string(*p.ps);
        delete ps;
        ps=new_ps;
        return *this;
    }

    ~Hasptr(){delete ps;}

    private:
    string *ps;
    int i;
};