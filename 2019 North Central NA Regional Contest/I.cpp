#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, t[N];
vector< pair<int,int> > g[N];

LL sz[N], sumt[N], sumd[N], sumdt[N];

void dfs(int u, int p) {
	sz[u] = 1; sumt[u] = t[u];
	for (auto e: g[u]) {
		int v = e.first;
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		sumd[u] += sumd[v] + sz[v] * e.second;
		sumt[u] += sumt[v];
		sumdt[u] += sumdt[v] + sumt[v] * e.second;
	}
	// printf("u=%d, sz=%lld,sumd=%lld,sumt=%lld,sumdt=%lld\n", u,sz[u],sumd[u],sumt[u],sumdt[u]);
}

LL up_sumt[N], up_sumd[N], up_sumdt[N], ans[N];

void dfs_up(int u, int p) {
	ans[u] += sumdt[u] + t[u] * sumd[u];
	ans[u] += up_sumdt[u] + t[u] * up_sumd[u];
	for (auto e: g[u]) {
		int v = e.first;
		if (v == p) continue;

		up_sumt[v] = sumt[1] - sumt[v];
		up_sumd[v] = up_sumd[u] + (sz[1] - sz[u]) * e.second + (sumd[u] - (sumd[v] + sz[v] * e.second)) + e.second * (sz[u] - sz[v]);
		up_sumdt[v] = up_sumdt[u] + up_sumt[u] * e.second + (sumdt[u] - (sumdt[v] + sumt[v] * e.second) + e.second * (sumt[u] - sumt[v]));

		dfs_up(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) 
		scanf("%d", &t[i]);

	for (int i = 1; i < n; i ++) {
		int u, v, w; 
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}	
	
	dfs(1, 1);
	dfs_up(1, 1);

	for (int i = 1; i <= n; i ++) {
		printf("%lld\n", ans[i]);
	}
}

