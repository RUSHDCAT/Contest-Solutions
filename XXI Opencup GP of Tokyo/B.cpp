#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1000000 + 10;
const LL MOD = 998244353;

LL fac[N],inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) 
		cin >> a[i];

	vector<LL> f(n + 1);
	f[1] = 1, f[0] = 1;
	for (int i = 2; i <= n; i ++) {
		f[i] = 1LL * (2 * i - 1) * f[i-1] % MOD;
	}

	LL res = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) {
			int x = i - 1, y = n - i;
			LL ans = c(x + y, x) * f[x] % MOD * f[y] % MOD;
			res = (res + ans) % MOD;
		}
	}
	cout << res << endl;

}	