#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 2000 + 10;
int n, a[N];
LL dp[N][N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL solve(int l,int r){
	if(l+1 == r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int cnt=0;
	for(int mid=l+1;mid<r;mid++){
		if(a[mid]>a[l] && a[mid]<a[r]) cnt++;
	}
	dp[l][r]=0;
	for(int mid=l+1;mid<r;mid++){
		if(a[mid]>a[l] && a[mid]<a[r]) {
			dp[l][r] += (solve(l,mid) + solve(mid,r) + 1);
			dp[l][r] %= MOD;
		}
	}
	(dp[l][r] *= mpow(cnt, MOD-2)) %= MOD;
	return dp[l][r];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	a[n+1] = n+1;
	memset(dp,-1,sizeof(dp));
	cout << solve(0,n+1) << endl;
}