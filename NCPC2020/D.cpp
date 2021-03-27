#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, w;
vector<int> g[N];
int x[N], y[N];
int need[N];

void dfs(int u, int p) {
	for (auto v: g[u]) {
		if (v == p) continue;
		int cur = x[v] - y[v];
		if (x[v] < need[u]) cur += need[u] - x[v];
		need[v] = cur;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> w;
	need[0] = x[0] = w; 
	for (int i = 1; i <= n; i ++) {
		int p; 
		cin >> p >> x[i] >> y[i];
		g[p].push_back(i);
	}

	dfs(0, 0);
	LL ans = *min_element(need, need + 1 + n);
	cout << ans << endl;
}