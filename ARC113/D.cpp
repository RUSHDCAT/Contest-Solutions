#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 998244353;

LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	if (m == 1) {
		cout << mpow(k, n) << endl; return 0;
	}
	if (n == 1) {
		cout << mpow(k, m) << endl; return 0;
	}
	LL ans = 0;
	for (int i = 1; i <= k; i ++) {
		LL ways1 = ((mpow(i, n) - mpow(i-1, n)) % MOD + MOD) % MOD;
		LL ways2 = mpow(k - i + 1, m);
		ans += ways1 * ways2;
		ans = (ans % MOD + MOD) % MOD;
	}
	cout << ans << endl;
}