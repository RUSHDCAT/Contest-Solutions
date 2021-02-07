#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 600000 + 10;
const LL mod = 998244353;

LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x >> 1);
	if (x % 2 == 0) return t * t % mod;
	return t * t % mod * a % mod;
}
void look(int x) {
	printf("x=%d\n", x);
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			if(1LL*i*mpow(j,mod-2)%mod == x) {
				printf("%d/%d\n", i,j); return;
			}
		}
	}
}

int main() {
	int n; cin >> n;
	int a, b; cin >> a >> b; 
	int p = 1LL * a * mpow(b, mod-2) % mod;

	vector<int> g(N,0), pw1(N,0), pw2(N,0), fac(N,0), inv(N,0);
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=1LL*(mod-(mod/i))*inv[mod%i]%mod;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		inv[i]=1LL*inv[i-1]*inv[i]%mod;
	}

	g[1] = 1;
	for (int i = 2; i < N; i ++) 
		g[i] = (1LL * g[i-1] * g[i-1] % mod + 2) % mod;
	
	if (2 * a == b) {
		LL ans = 0;
		for (int i = 1; i < n; i ++) {
			LL A = 1LL * fac[n] * inv[i] % mod * inv[n-i] % mod;
			LL B = mpow((mod+1)/2, 1LL*i*(n-i));
			LL X = A * B % mod;
			ans += 1LL * g[i] * X % mod;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}

	pw1[0] = 1;
	for (int i = 1; i < N; i ++) 
		pw1[i] = 1LL * pw1[i-1] * p % mod;

	pw2[0] = 1;
	for (int i = 1; i < N; i ++) 
		pw2[i] = 1LL * pw2[i-1] * (1-p+mod) % mod;

	int ans = 0;
	int las = 1;
	for (int i = 1; i < n; i ++) {
		int cur = 1LL * las * (pw1[n-i+1] - pw2[n-i+1] + mod) % mod * mpow( (pw1[i] - pw2[i] + mod) % mod, mod - 2 ) % mod;
		ans = (ans + 1LL * g[i] * cur % mod) % mod;
		//printf("i=%d\n", i);
		//look(cur); printf("# %d\n", g[i]);
		las = cur;
	}
	cout << ans << endl;
}

