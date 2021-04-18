#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000 + 10;
const LL MOD = 998244353;
 
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL inv(LL x) {
	x %= MOD;
	return mpow(x, MOD-2);
}
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<LL> a(n), b(m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		//a[i] = 100;
	}
	LL sa = accumulate(a.begin(), a.end(), 0LL);
	assert(sa <= 10000);
 
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
		//b[i] = b[i] % 100000000 + 1;
	}
 
	vector< vector<LL> > ways(sa + 1, vector<LL>(2, 0));
	ways[0][0] = 1;
	auto add = [](LL &x, LL y) {
		(x += y) %= MOD;
	};
	for (int i = 0; i < n; i ++) {
		for (int j = sa; j >= 0; j --) {
			for (int f = 0; f < 2; f ++) {
				if (j + a[i] <= sa)
					add(ways[j + a[i]][f ^ 1], ways[j][f]);
			}
		}
	}
	LL ans = 0;
	for (auto B: b) {
		for (int sum = 0; sum <= sa; sum ++) {
			assert(B + sum < MOD);
			LL tmp = 1LL * B * inv(B + sum) % MOD;
			for (int f = 0; f < 2; f ++) {
				if (ways[sum][f]) {
					LL bu = tmp * ways[sum][f] % MOD;
					if (f % 2 == 1) ans = ans - bu; else ans = ans + bu;
			        ans = (ans % MOD + MOD) % MOD;
				}
			}
		}
	}
	ans = (ans % MOD + MOD) % MOD;
	ans = ((n + m - ans) % MOD + MOD) % MOD;
	cout << ans << endl;
}