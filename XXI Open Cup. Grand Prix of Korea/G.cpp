#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 50000 + 10;
const int MOD = 1e9 + 7;
map< vector< pair<int,int> >, int > mp[N];
char s[N]; int n,k;
void add(int &x,int y){
	x+=y; if (x>=MOD) x-=MOD; 
}

char t[N]; int ac=0;
int lcs() {
	int dp[20][20] = {0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][n]>=n-k;
}

void gen(int pos) {
	if(pos==n+1){
		ac += lcs(); 
		//printf("%s %s\n", s+1,t+1);
		return;
	}
	for(char c='A';c<='Z';c++){
		t[pos]=c; gen(pos+1);
	}
}

int dp[N][8][1<<8];
int nex[1<<8][1<<8], flag[1<<8][1<<8];
int trans(int mask1,int same){
	if(nex[mask1][same] != -1) return nex[mask1][same];
	vector<int> f(7,0);
	f[0]=0; for(int i=1;i<7;i++) f[i]=f[i-1]+(mask1>>(i-1)&1);
	vector<int> g(7,0);
	for(int i=0;i<7;i++){
		if(same>>i&1) g[i]=f[i]+1;
		else g[i]=f[i+1];
	}
	int nexmask=0;
	for(int i=1;i<7;i++){
		g[i]=max(g[i-1],g[i]);
		if(g[i]>g[i-1])nexmask|=(1<<(i-1));
	}
	flag[mask1][same] = g[3] - f[3];
	printf("nex[%d][%d]=%d\n", mask1,same,nexmask);
	return nex[mask1][same] = nexmask;
}
void upd(int i, int lcs, int mask) {
	vector<int> f(7,0);
	f[3]=i+lcs-3;
	for(int i=4;i<7;i++) f[i]=f[i-1]+(mask>>i&1);
	for(int i=2;i>=0;i--) f[i]=f[i+1]-(mask>>i&1);
	//printf("dp %d %d %d = %d\n", i,lcs,mask,dp[i][lcs][mask]);
	for(int x=i-3;x<=i+3;x++){
		//printf("(%d,%d)=%d # ",i,x,f[x-(i-3)]);
	}
	//printf("\n");
	// i-3,i-2,i-1,i,i+1,i+2,i+3
	//     i-2,i-1,i,i+1,i+2,i+3,i+4
	vector<int> sam(26,0);
	for(int x=i-2;x<=i+4;x++){
		if(x>=1&&x<=n) sam[s[x]-'A']|=1<<(x-(i-2));
	}
	for(int c=0;c<26;c++){
		trans(mask,sam[c]);
		if(lcs-1+flag[mask][sam[c]]>=0) add(dp[i+1][lcs-1+flag[mask][sam[c]]][nex[mask][sam[c]]],dp[i][lcs][mask]);
	}
}

int main() {
	memset(nex,-1,sizeof(nex));
	scanf("%s", s + 1); n = strlen(s + 1);
	//n = 50000; for(int i=0;i<26;i++) s[i+1] = rand()%26 + 'A';
	scanf("%d", &k);
	dp[0][3][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=3;j++){
			for(int mask=0;mask<1<<6;mask++){
				if(dp[i][j][mask]==0)continue;
				upd(i,j,mask);
			}
		}
	}
	int ans=0;
	for(int lcs=3;lcs>=3-k;lcs--){
		for(int mask=0;mask<1<<6;mask++) add(ans,dp[n][lcs][mask]);
	}
	cout<<ans<<endl;
	//gen(1); cout<<ac<<endl;
}