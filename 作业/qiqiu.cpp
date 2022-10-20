#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        set<string> st;
        int cnt = 0,ct=0;
        cin>>cnt;
        while (cnt--)
        {
            string s;
            cin >> s;
            st.insert(s);
        }
        printf("%d\n", st.size());
        auto it = st.begin();
        for (it;; it++)
        {
            if (ct == st.size() - 1)
                break;
            cout<<*it<<" ";
            ct++;
        }
        cout<<*it<<endl;
        st.clear();
    }
}