#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m;
set<int> g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v; 
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
}