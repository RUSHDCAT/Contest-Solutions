#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int t,n,k,x[N],y[N];
int f[N][N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=i==j?0:1e9;
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			if(i!=j){
				if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= k) f[i][j]=1;
			}
		}
		bool ok=0;
		for(int i=1;i<=n;i++){
			bool tmp=0;
			for(int j=1;j<=n;j++)if(f[i][j]>1)tmp=1;
			if(tmp==0)ok=1;
		}
		printf("%s\n", ok?"1":"-1");
	}
}