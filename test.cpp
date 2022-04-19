#include<bits/stdc++.h>

using namespace std;

bool vst[1005];

int main() {
#ifdef MyTest
	freopen("Sakura.txt", "r", stdin);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	while(k--) {
		bool flag = true;
		memset(vst, 0, sizeof(vst));
		stack<int> st;
		queue<int> que;
		for(int i = 1; i <= n; i++) { int x; cin >> x; que.push(x);}
		for(int i = 1; i <= n && flag; i++) {
			if(st.size() && i == st.top()) { st.pop(); continue; }
			if(vst[i]) { flag = false; break; }
			while(que.front() != i) {
				int x = que.front();
				que.pop();
				st.push(x);
				vst[x] = true;
				if(st.size() > m) { flag = false; break; }
			}
			que.pop();
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}