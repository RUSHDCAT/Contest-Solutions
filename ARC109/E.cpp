#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
const LL MOD = 998244353;

int n;
LL mpow(LL a, LL x) {
	if (x==0) return 1;
	LL t = mpow(a,x>>1);
	if(x%2==0) return t*t%MOD;
	return t*t%MOD*a%MOD;
}
LL inv(int x) {
	return mpow(x,MOD-2);
}
LL pw[N];
LL pre[N];
void solve(int s) {
	LL tot = pw[n];
	LL ans = tot * n % MOD * inv(2) % MOD;

	int d_max = max(min(s-1,n-s)-1,0);
	LL sum=pre[d_max];
	/*
	for(int d=1;d<=d_max;d++) {
		sum = sum + pw[2*d-1] % MOD * (2*d+1) % MOD;
		sum = sum % MOD;
	}
	*/
	//printf("d_max=%d,sum=%lld,pre=%lld\n", d_max,sum,pre[d_max]);
	ans = ((ans + sum) % MOD + MOD) % MOD;
	ans = ans * inv(pw[n]) % MOD;

	printf("%lld\n", ans);
}

int main() {
	for(int i=1;i<N;i++){
		pre[i]=pre[i-1] + mpow(2,2*i-1) % MOD * (2*i+1) % MOD;
		pre[i]=pre[i]%MOD;
	}

	pw[0] = 1;
	for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * 2 % MOD;

	cin >> n; //solve(1); return 0;
	for (int i = 1; i <= n; i ++) {
		solve(i);
	}
}