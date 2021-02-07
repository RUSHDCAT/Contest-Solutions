#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m;
vector< pair<int,int> > g[N]; bool vis[N];
int a[N];
void dfs(int u, int p) {
	if (vis[u]) return;
	vis[u] = 1;
	for (auto e: g[u]) {
		if (vis[e.first] == 0) {
			if (a[u] != e.second)
				a[e.first] = e.second;
			else {
				a[e.first] = (e.second + 1);
				if (a[e.first] == n + 1) a[e.first] = 1;
			}
			dfs(e.first, u); 
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}	
	for (int i = 1; i <= n; i ++) a[i] = 1;
	dfs(1, 1);
	for (int i = 1; i <= n; i ++) printf("%d\n", a[i]);
}