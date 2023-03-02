#include <iostream>
using namespace std;

int main()
{
	int ans = 1;
	for (int i = 2021; i > 0; i -= 2)
		ans = ans * i % 100000;
	cout << ans << endl;
	return 0;	
}
