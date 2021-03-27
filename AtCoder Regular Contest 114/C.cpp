#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5000 + 10;
const LL MOD = 998244353;
int n, m;
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}

LL f[N][N], pw[N][N];

int main() {
	pw[0][0] = 1;
	for (int i = 1; i < N; i ++) {
		pw[i][0] = 1;
		for (int j = 1; j < N; j ++) pw[i][j] = pw[i][j-1] * i % MOD;
	}
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		f[1][i] = pw[m][n-1];
	}
	for (int i = 2; i <= n; i ++) {
		for (int x = 1; x <= m; x ++) {
			f[i][x] = f[i-1][x] - pw[m-x][i-2] * pw[m][n-(i-1)] % MOD + 
				pw[m-x][i-1] * pw[m][n-i] % MOD + 
				pw[m-x][i-2] * (x-1) % MOD * pw[m][n-i] % MOD;
			
			f[i][x] = (f[i][x] % MOD + MOD) % MOD;
			//printf("# %d %d : %d\n", i, x, f[i][x]);
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i ++) for (int x = 1; x <= m; x ++) (ans += f[i][x]) %= MOD;
	cout << ans << endl;
}