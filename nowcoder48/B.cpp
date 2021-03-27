#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 200000 + 10;
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> w(n+1);
	for (int i = 1; i <= n; i ++) 
		cin >> w[i];
	vector<LL> suf(n+1, 0);
	suf[n] = w[n];
	for (int i = n-1; i >= 1; i --) 
		suf[i] = (suf[i+1] + w[i]) % MOD;
	LL ans = 1;
	
	for (int i = 2; i <= n; i ++) {
		ans = ans * (w[i] * mpow(suf[i], MOD-2) % MOD) % MOD;
	}
	cout << ans << endl;

}