#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400 + 10;
const int inf = 1e9;
int n, a[N];
void upd(int &x,int y){
	x=max(x,y);
}
int dp[N][N][N];
int solve(int l,int r,int x){
	if(l==1&&r==n)return 0;
	//printf("#\n");
	if(dp[l][r][x]!=-1) return dp[l][r][x];
	//printf("#\n");
	dp[l][r][x]=0;
	int pl=l-1,pr=r+1;
	int nex;
	if(pr==n+1) nex=pl;
	else if(pl==0) nex=pr;
	else if(a[pl]<a[pr]) nex=pr; else nex=pl;

	if(pr<=n){
		if(x>=1) upd(dp[l][r][x],solve(l,pr,x-1)+a[pr]);
		if(x<=n-1 && nex==pr) upd(dp[l][r][x],solve(l,pr,x+1));
	}
	if(pl>=1){
		if(x>=1) upd(dp[l][r][x],solve(pl,r,x-1)+a[pl]); 
		if(x<=n-1 && nex==pl) upd(dp[l][r][x],solve(pl,r,x+1));
	}
	
	//printf("dp[%d][%d][%d] = %d\n", l,r,x,dp[l][r][x]);
	return dp[l][r][x];
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	memset(dp,-1,sizeof(dp));
	//printf("%d\n", solve(3,3,0));return 0;
	
	for(int i=1;i<=n+1;i++){
		printf("%d\n", solve(i,i-1,1));
	}
	

}