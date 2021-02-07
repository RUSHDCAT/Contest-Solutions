#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5000 + 10;
int h,w,k;
char s[N][N];
LL dp[N][N];
const LL mod = 998244353;
void add(LL &x,LL y){
	x+=y; if(x>=mod) x%=mod;
}
int d[N][N],r[N][N];
LL pw[N];
int main() {
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=pw[i-1]*3%mod;

	scanf("%d%d%d",&h,&w,&k);
	for(int i=1;i<=k;i++){
		int x,y; char c[2];
		scanf("%d%d%s",&x,&y,c);
		s[x][y]=c[0];
	}
	for(int i=h;i>=1;i--){
		for(int j=w;j>=1;j--){
			d[i][j]=d[i+1][j]+(s[i][j]?0:1);
			r[i][j]=r[i][j+1]+(s[i][j]?0:1);
		}
	}

	for(int i=h;i>=1;i--){
		for(int j=w;j>=1;j--){
			if(i==h&&j==w) {
				if(s[i][j]) dp[i][j]=1; else dp[i][j]=3;
				continue;
			}

			if(s[i][j]=='X') {
				add(dp[i][j],dp[i+1][j] * pw[r[i][j+1]] % mod);
				add(dp[i][j],dp[i][j+1] * pw[d[i+1][j]] % mod);
			} else
			if(s[i][j]=='R') {
				add(dp[i][j],dp[i][j+1] * pw[d[i+1][j]] % mod);
			} else
			if(s[i][j]=='D') {
				add(dp[i][j],dp[i+1][j] * pw[r[i][j+1]] % mod);
			} else {
				add(dp[i][j],2*(dp[i+1][j] * pw[r[i][j+1]] % mod + dp[i][j+1] * pw[d[i+1][j]] % mod));
			}
			//printf("dp[%d][%d]=%lld\n", i,j,dp[i][j]);
		}
	}
	cout<<dp[1][1]<<endl;
}
