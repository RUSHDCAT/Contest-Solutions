#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,t;
double p[N][4];
int x[N],s[N];
double dp[N][8];
void upd(double &x,double y){
	x=min(x,y);
}

int main() {
	scanf("%d%d",&t,&n);
	for(int i=1;i<=t;i++){
		scanf("%lf%lf%lf",&p[i][3],&p[i][2],&p[i][1]);
		p[i][1]/=100, p[i][2]/=100, p[i][3]/=100;
	}	
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&s[i]);
	}
	for(int i=0;i<N;i++)for(int j=0;j<8;j++)dp[i][j]=1e9;
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=6;j++){
			int id = x[i+1], tmp = s[i+1];
			upd(dp[i+1][j],dp[i][j] + p[id][tmp] * tmp);
			upd(dp[i+1][j+1], dp[i][j] + p[id][1] * tmp);
		}
	}	
	double ans = 1e9;
	for(int i=0;i<=6;i++){
		ans = min(ans, dp[n][i]);
	}
	printf("%.10f\n", ans);
}
