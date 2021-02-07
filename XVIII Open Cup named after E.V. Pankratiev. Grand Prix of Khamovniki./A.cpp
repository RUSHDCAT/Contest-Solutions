#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9;

int n, s, ps, pu, a[N];
int dp[42][42][1<<5][1<<5],v1[N],v2[N],mx[N];

int dfs(int u,int p1,int g1,int g2) {
	int p2 = u-1-p1;
	if(u==2*n*(s+1)+1) {
		return 0;
	}
	if(dp[u][p1][g1][g2]!=-inf)return dp[u][p1][g1][g2];
	if(a[u]<=n) {
		int ans=-inf;
		int id = a[u] - 1;
		if(p1<ps && !( mx[a[u]] == u && (g1>>id&1) == 0 ) ) {
			ans=max(ans,v1[p1+1]+dfs(u+1,p1+1,g1,g2));
		}
		if(p2<pu && ((g1>>id&1) == 0) ) {
			ans=max(ans,v2[p2+1]+dfs(u+1,p1,g1|1<<id,g2));
		}
		return dp[u][p1][g1][g2]=ans;
	}
	int ans=inf;
	int id = a[u] - n - 1;
	if(p1<ps && !( mx[a[u]] == u && (g2>>id&1) == 0 ) ) {
		ans=min(ans,-v1[p1+1]+dfs(u+1,p1+1,g1,g2));
	}
	if(p2<pu && ((g2>>id&1) == 0) ) {
		ans=min(ans,-v2[p2+1]+dfs(u+1,p1,g1,g2|1<<id));
	}
	return dp[u][p1][g1][g2]=ans;
}
int main() {
	scanf("%d%d",&n,&s);
	for(int i=1;i<=2*n*(s+1);i++) {
		scanf("%d", &a[i]); mx[a[i]] = i;
	}

	scanf("%d",&ps);
	for(int i=1;i<=ps;i++) scanf("%d",&v1[i]);
	sort(v1+1,v1+1+ps); reverse(v1+1,v1+1+ps);
	
	scanf("%d",&pu);
	for(int i=1;i<=pu;i++) scanf("%d",&v2[i]);
	sort(v2+1,v2+1+pu); reverse(v2+1,v2+1+pu);

	for(int i=0;i<42;i++)for(int j=0;j<42;j++)for(int x=0;x<1<<5;x++)for(int y=0;y<1<<5;y++) dp[i][j][x][y]=-inf;
	cout<<dfs(1,0,0,0)<<endl;
}	