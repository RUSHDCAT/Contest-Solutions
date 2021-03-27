#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000000 + 10;
const LL MOD = 1e9 + 7;
LL mpow(LL a, LL x) {
	if (x == -1) return mpow(a, MOD-2);
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}


LL det(int n, int m) {
	return mpow(m+1,n-1) * (m-n+1) % MOD;
}

LL inv[N];
LL c(int n, int m) {
	m = min(m, n - m);
	LL ans = 1;
	for (int i = n; i > n - m; i --) ans = ans * i % MOD;
	for (int i = 1; i <= m; i ++) ans = ans * inv[i] % MOD;
	return ans;
}



int main() {
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	int n, k; cin >> n >> k; k = n - k;
	LL ans = det(n-k, n-1) * c(n,k) % MOD;
	cout << ans << endl;
}