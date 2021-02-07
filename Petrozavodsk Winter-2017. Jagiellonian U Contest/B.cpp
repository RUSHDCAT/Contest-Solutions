#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
const int inf = 1e9;
int T;
char s[N], t[N];
int nex[N][26];
int dp[1002][1002];
void upd(int &x,int y){
	x=min(x,y);
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<26;i++)nex[n+1][i]=n+1;
		for(int i=n;i>=1;i--){
			for(int j=0;j<26;j++)nex[i][j]=nex[i+1][j];
			nex[i][s[i]-'a']=i;
		}
		for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)
			dp[i][j]=n+1;
		dp[0][0]=0;
		int ans=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<=i;j++){
				int c=t[i+1]-'a';
				int pos=dp[i][j];
				upd(dp[i+1][j], dp[i][j]);
				if(pos!=n+1) {
					upd(dp[i+1][j+1],nex[pos+1][c]);
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<=m;j++) if(dp[i][j]<=n) ans=max(ans,j);
		}
		printf("%d\n", ans);
	}
}