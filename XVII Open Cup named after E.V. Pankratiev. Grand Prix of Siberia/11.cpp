#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
char s[N];
int t, n, mod;
int a[N];
int pre[N], pw[N], ipw[N];

LL mpow(LL a, LL x, LL mod) {
	if(x==0) return 1%mod;
	LL t = mpow(a,x>>1,mod);
	if(x%2==0) return t*t%mod;
	return t*t%mod*a%mod;
} 

int main() {
	scanf("%s", s+1);
	scanf("%d%d",&t,&mod);
	for(int i=1;i<=t;i++) scanf("%d",&a[i]);
	n=strlen(s+1);

	for(int i=1;i<=n;i++) pre[i]=(10LL*pre[i-1] + (s[i]-'0'))%mod;
	pw[0]=1; 
	for(int i=1;i<N;i++) {
		pw[i]=pw[i-1]*10LL%mod;
		ipw[i]=mpow(pw[i],mod-2,mod);
	}

	map<int,int> cnt, pos;

	vector<LL> res(102,0);
	vector< pair<int,int> > P(102,make_pair(0,0));

	cnt[0]=1; pos[0]=1;
	for(int i=1;i<=n;i++) {
		// pre[R] - pre[i] * 10^i = a[x]
		for(int x=1;x<=t;x++) {
			int need = (1LL * (pre[i] - a[x]) * ipw[i] % mod + mod) % mod;
			if (cnt.find(need) == cnt.end()) continue;
			res[x] = (res[x] + cnt[need]);
			if (P[x].first == 0) {
				P[x] = make_pair(pos[need], i);
			}
		}
		cnt[ 1LL * pre[i] * ipw[i] % mod ] ++; pos[  1LL * pre[i] * ipw[i] % mod ] = i+1;
	}

	for(int x=1;x<=t;x++) {
		printf("%lld %d %d\n", res[x], P[x].first, P[x].second);
	}
}

