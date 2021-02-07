#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k, C, dfn[N], R[N];
vector<int> g[N];
void dfs(int u, int p) {
	dfn[u] = ++C;
	for (auto v: g[u]) {
		if (v == p) continue; 
		dfs(v, u);
	}
	R[u] = C;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> a(k);
	vector<int> sum(n + 1, 0);
	for (int i = 0; i < k; i ++) {
		cin >> a[i];
	}
	dfs(a[0], a[0]);
	for (int i = 0; i < k; i ++) {
		sum[dfn[a[i]]] ++;
	}
	for (int i = 1; i <= n; i ++) sum[i] += sum[i-1];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int x = sum[R[i]] - sum[dfn[i] - 1];
		if (x > 0) ans ++;
	}
	cout << ans << endl;
}