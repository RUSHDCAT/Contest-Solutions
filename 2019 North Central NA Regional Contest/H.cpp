#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
vector<int> g[N];
int n, m, dis[N];

int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= m; i ++) {
		int u, v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}		
	memset(dis, -1, sizeof(dis));
	dis[1] = 0; queue<int> q; q.push(1);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v: g[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1; q.push(v);
			}
		}
	}
	int ans = max(dis[n]-1, 0);
	printf("%d\n", ans);
}