#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20;
int t,n,nex[N],dp[1<<N];
char s[N][N];
bool ok[1<<N];

const LL MOD = 1LL<<32;
LL mpow(LL a, LL x) {
	if(x==0) return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		for(int i=0;i<n;i++){
			nex[i]=0;
			for(int j=0;j<n;j++){
				if(s[i][j]=='1') nex[i]|=(1<<j);
			}
		}
		for(int i=0;i<1<<n;i++){
			bool ng=0;
			for(int j=0;j<n;j++){
				if(i>>j&1){
					if(nex[j]&i) {
						ng=1; break;
					}
				}
			}
			ok[i]=!ng;
			//printf("ok[%d] = %d\n", i, ok[i]);
		}
		for(int i=0;i<1<<n;i++) dp[i]=1e9;
		dp[0]=0;


		for(int mask=1;mask<(1<<n);mask++)
		for(int sub=mask;sub;sub=(sub-1)&mask) {
		    if(ok[sub]) {
		    	dp[mask] = min(dp[mask], dp[mask ^ sub] + 1);
		    }
		}
		LL ans = 0;
		for(int i=1;i<1<<n;i++){
			ans += (LL)dp[i] * mpow(233, i);
			ans %= MOD;
			//printf("%d %d\n", i,dp[i]);
		}
		printf("%lld\n", ans);
	}
}