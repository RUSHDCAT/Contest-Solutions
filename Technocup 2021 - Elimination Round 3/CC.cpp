#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
bool vis[20];
set<string> s[20];
void dfs(int len) {
	if(len==1) {
		s[1].insert("1"); return;
	}
	if(vis[len]) return;
	for(int i=1;i<len;i++){
		dfs(i); dfs(len-i);
		for(auto p: s[i]) {
			for(auto q: s[len-i]) {
				string s1 = p;
				string s2 = q;
				for(int j=0;s1[j];j++) s1[j] = (char)(('0'+'1')-s1[j]);
				s[len].insert(s1+s2);
			}
		}
	}
}

int main() {
	int x = 6;
	dfs(x);
	for(auto p: s[x]) {
		cout << p << endl;
	}
	cout<<s[x].size()<<endl;
}