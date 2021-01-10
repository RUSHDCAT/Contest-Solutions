#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 6000000 + 10;
int mn[N], vis[N], cur[N];

int join(int x){
	int xcopy=x,val=1e9;
	while(x>1) {
		int v=mn[x];
		while(x%v==0) x/=v;
		while(vis[cur[v]] == 1) cur[v] += v;
		val = min(val, cur[v]);
	}	
	return val;
}
int main() {
	for(int i=1;i<N;i++) mn[i]=i;
	for(int i=2;i<N;i++){
		if(vis[i]==0){
			mn[i]=i; cur[i]=i; 
			for(int j=i+i;j<N;j+=i){
				vis[j]=1;  mn[j]=min(mn[j],i);
			}
		}
	}	
	memset(vis,0,sizeof(vis));

	int n; cin >> n;
	if(n<=2) return !printf("%d\n", n);
	vis[2]=1; int pre=2;
	for(int i=1;i<=n-2;i++){
		int nex = join(pre);
		vis[nex]=1;
		pre = nex;
	}
	printf("%d\n", pre);
}



