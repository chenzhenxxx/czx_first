#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class a
{
public:
    int num;
    int time;
};
bool cmp(a b, a c)
{
    return b.time < c.time;
}
int main()
{
    a water[1001];
    double total=0;
    int n, cnt = 0;
    cin >> n;
   for(int i=1;i<=n;i++)
     {   cin >> water[i].time;
        water[i].num = i;
    }
    sort(water, water + n+1, cmp);
    for (int i = 1; i <=n; i++)
        cout << water[i].num << " ";
    cout << endl;
    for(int i=1;i<=n;i++)   //这个循环用来计算总时间 
	{
		total+=water[i].time*(n-i);
	}
    printf("%.2f",total/n);
}