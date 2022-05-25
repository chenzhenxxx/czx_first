#include<bits/stdc++.h>
using namespace std;
static int N=0;
class Employee
{
    public:
    friend void show(Employee s);
    Employee();
    Employee(const string&s);
    Employee(const Employee &a){ N++;
    num=N;
    name="czx";}
    Employee(const Employee& a) =delete;
    Employee &operator=(const Employee &)=delete;
    ~Employee()=default;
    private:
    string name;
    int num;

};
Employee::Employee()
{  
    N++;
    num=N;
    name="czx";
}
Employee:: Employee(const string&s)
{  N++;
   num=N;
   name=s;
}
void show(Employee s)
{
    cout<<s.name<<s.num<<endl;;
}
int main()
{
    Employee a,b=a,c=b;
    show(a);
    show(b);
    show(c);
}