#include<iostream>  
#include<fstream>
#include<string>  
#include<vector>  
#include<algorithm>  
#include<numeric>  
#include<functional>
#include<iterator>
using namespace std;
using namespace placeholders;
 
int main(int argc, char**argv)  
{  
	vector<string> v;
    ifstream in("/home/chenzhenxxx/czx_first/C++ prime/10/1.txt");
    istream_iterator<string> str(in);
    istream_iterator<string> end;
    copy(str,end,back_inserter(v));
     
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}
} 