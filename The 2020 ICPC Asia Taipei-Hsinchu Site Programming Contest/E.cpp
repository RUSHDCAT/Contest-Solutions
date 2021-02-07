#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int n, m;
char s[N];
bool vis[N][N];
int dp[N][N][7];

map<char, int> mp;
void upd(int l,int r){
	int mx=0;
	for(int i=0;i<7;i++)mx=max(mx,dp[l][r][i]);
	if(mx>=m){
		for(int i=0;i<7;i++)dp[l][r][i]=max(dp[l][r][i],0);
	}
}
void solve(int l,int r){
	if(vis[l][r])return;
	vis[l][r]=1;
	if(l==r){
		dp[l][r][mp[s[l]]]=1; upd(l,r) ;return;
	}
	for(int mid=l;mid<r;mid++){
		solve(l,mid);
		solve(mid+1,r);
		for(int x=0;x<7;x++){
			dp[l][r][x] = max(dp[l][mid][x] + dp[mid+1][r][x], dp[l][r][x]);
		}
	}
	upd(l,r);
}

int main() {	
	mp['R']=0,mp['G']=1,mp['B']=2,mp['C']=3,mp['M']=4,mp['Y']=5,mp['K']=6;
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);

	/*
	n=500; m=1;
	for(int i=1;i<=n;i++){
		s[i]=rand()%2?'R':'B';
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)for(int x=0;x<7;x++)
			dp[i][j][x]=-1e9;
	}
	solve(1,n);

	int mx=0;
	for(int i=0;i<7;i++)mx=max(mx,dp[1][n][i]);
	printf("%s\n", mx>=m?"Yes":"No");
}