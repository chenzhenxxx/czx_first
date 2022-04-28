#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
         if(grade==1)
          break;
        ++scores[grade / 10];
    }
    for (auto beg = scores.begin(), end = scores.end(); beg != end; ++beg) {
        cout << *beg << endl;
    }
    system("pause");
    return 0;
}
