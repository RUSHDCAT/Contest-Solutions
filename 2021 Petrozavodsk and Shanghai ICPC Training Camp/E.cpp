#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;
const int N = 102;
int par[N];
int find(int x) {
	return par[x] == x ? x: par[x] = find(par[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m);
	for (int i = 0; i < m; i ++) {
		cin >> u[i] >> v[i]; --u[i], --v[i];
	}	
	for (int i = 0; i < n; i ++) {
		par[i] = i;
	}

	for (int i = 0; i < n - 1; i ++) {
		if (find(u[i]) == find(v[i])) {
			cout << 0 << endl; return 0;
		}
		par[find(u[i])] = find(v[i]);
	}


	LL C[102][102] = {}; vector<int> fac(m + 1, 0);
	fac[0] = 1;
	for (int i = 1; i <= m; i ++) 
		fac[i] = 1LL * fac[i-1] * i % MOD;

	for (int i = 0; i < 102; i ++) C[i][0] = 1;
	for (int i = 1; i < 102; i ++) {
		for (int j = 1; j <= i; j ++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
	}

	vector<int> f(1<<(n-1), 0);
	for (int i = 0; i <1<<(n-1); i ++) {
		for (int j = 0; j < n; j ++) par[j] = j;
		for (int j = 0; j < (n-1); j ++) {
			if (i >> j & 1) par[find(u[j])] = find(v[j]);
		}
		for (int j = 0; j < m; j ++) if (find(u[j]) == find(v[j])) f[i] ++;
		// printf("f[%d] = %d\n", i, f[i]);
	}

	vector<int> dp(1<<(n-1), 0);
	dp[(1<<(n-1)) - 1] = 1;
	for (int i = (1<<(n-1)) - 1; i >= 0; i --) {
		for (int j = 0; j < n-1; j ++) if (i>>j&1) {
			int desc = f[i] - f[i^(1<<j)];
			int tot = m - f[i^(1<<j)];
			LL tmp = 1LL * fac[desc - 1] * C[tot-1][desc-1] % MOD;
			// printf("i=%d,j=%d,desc=%d,tot=%d,tmp=%lld\n", i,j,desc,tot,tmp);
			(dp[i^(1<<j)] += 1LL * dp[i] * tmp % MOD) %= MOD;
		}
	}
	int cnt = 0;
	for (int i = n - 1; i < m; i ++) if (u[i] == v[i]) cnt ++;
	dp[0] = 1LL *dp[0] * C[m][cnt] % MOD * fac[cnt] % MOD;
	cout << dp[0] << endl;
}



