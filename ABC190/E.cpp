#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

vector<int> g[N];
int dp[1<<17][17];

struct Nod {
	int i, j, dis;
	bool operator < (const Nod&o) const {
		return dis > o.dis;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> u(m), v(m);
	for (int i = 0; i < m; i ++) {
		cin >> u[i] >> v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	int k; cin >> k;
	vector<int> c(k);
	for (int i = 0; i < k; i ++) cin >> c[i];


	int link[20][20] = {0};
	for (int i = 0; i < k; i ++) {
		vector<int> d(n + 1, -1);
		d[c[i]] = 0; queue<int> q; q.push(c[i]);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto v: g[u]) {
				if (d[v] == -1) {
					d[v] = d[u] + 1; q.push(v); 
				}
			}
		}
		for (int j = 0; j < k; j ++) link[i][j] = d[c[j]];
	}

	
	memset(dp,-1,sizeof(dp));
	priority_queue<Nod> q;
	for (int i = 0; i < k; i ++) {
		dp[1<<i][i] = 1; q.push((Nod){1<<i,i,1});
	}	
	/*
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			printf("E %d %d %d\n", i,j,link[i][j]);
		}
	}
	*/
	while (q.size()) {
		Nod now = q.top(); q.pop();
		int i = now.i, j = now.j;	

		if (now.dis > dp[i][j]) continue;
		//printf("# %d %d %d\n", i,j,dp[i][j]);
		for (int x = 0; x < k; x ++) {
			if (link[j][x] > 0) {
				if (dp[i|1<<x][x] == -1 || now.dis + link[j][x] < dp[i|1<<x][x]) {
					dp[i|1<<x][x] = now.dis + link[j][x];
					q.push((Nod){i|1<<x,x,dp[i|1<<x][x]});
				}
			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < k; i ++) if (dp[(1<<k)-1][i] > 0) ans = min(ans, dp[(1<<k)-1][i]);
	printf("%d\n", ans == 1e9 ? -1: ans);
}

