#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000 + 10;

struct Edge {
	int u, v, w, fg;
	bool operator < (const Edge & o) const {
		return w > o.w;
	}
} e[500000 + 10];

int par[N], sz[N], n, m;
int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}
vector< pair<int,int> > g[N];
LL ans = 0;
void dfs(int u, int p) {
	sz[u] = 1;
	for (auto e: g[u]) {
		if (e.first == p) continue;
		dfs(e.first, u);
		sz[u] += sz[e.first];
		ans = ans + 1LL * (n - sz[e.first]) * sz[e.first] * e.second;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	

	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].w; e[i].fg = 0;
 	}	
 	for (int i = 1; i <= n; i ++) par[i] = i;
 	sort(e + 1, e + 1 + m);
 	int cnt = 0;

 	int pos = -1;
 	for (int i = 1; i <= m; i ++) {
 		if (find(e[i].u) != find(e[i].v)) {
 			par[find(e[i].u)] = find(e[i].v); cnt ++;
 			if (cnt == n - 1) {
 				pos = i; break;
 			}
 		
 		}	
 	}
 	for (int i = 1; i <= n; i ++) {
 		sz[i] = 1; par[i] = i;
 	}
 	for (int i = pos; i >= 1; i --) {
 		if (find(e[i].u) != find(e[i].v)) {
 			par[find(e[i].u)] = find(e[i].v); e[i].fg = 1;
 		}
 	}
 	for (int i = 1; i <= n; i ++) par[i] = i;
 	for (int i = 1; i <= pos; i ++) {
 		if (e[i].fg == 1) {
 			ans += 1LL * sz[find(e[i].u)] * sz[find(e[i].v)] * e[i].w;
 			sz[find(e[i].v)] += sz[find(e[i].u)];
 			par[find(e[i].u)] = find(e[i].v);	
 		}
 	}
 	cout << ans << endl;
}

