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
LL inv(LL x) {
	return mpow(x, MOD-2);
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	for (int i = 0; i < m; i ++)
		cin >> b[i];

	LL tail = 0;
	for (int i = 0; i < m; i ++) {
		vector<int> p(n);
		iota(p.begin(), p.end(), 0);
		do {
			LL sum = b[i];
			for (auto x: a) sum += x;
			LL mul = 1;
			for (int j = 0; j < n; j ++) {
				int id = p[j];
				mul = mul * a[id] % MOD * inv(sum) % MOD;
				//printf("mul *= (%lld/%lld)\n", a[id], sum);
				sum -= a[id];
			}
			(tail += mul) %= MOD;
		} while(next_permutation(p.begin(), p.end()));
	}
	LL ans = (n + m - tail + MOD) % MOD;
	cout << ans << endl;
}
