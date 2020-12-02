#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n,deg[N],par[N];
vector<int> g[N];
void dfs(int u,int p) {
	par[u]=p;
	for(auto v: g[u]) {
		if(v==p) continue;
		dfs(v,u);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int rt=-1;
	int mx=0;
	for(int i=0;i<n;i++){
		if(g[i].size() >= 3) rt=i;
		mx=max(mx,(int)g[i].size());
	}

	if(mx<=2){
		return !printf("1\n");
	}

	dfs(rt,rt);

	for(int i=0;i<n;i++){
		if(g[i].size() == 1) {
			//printf("i=%d\n", i);
			int now = i;
			while(g[now].size() <= 2) {
				//printf("now = %d\n", now);
				now = par[now];
			}
			deg[now] ++;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(deg[i]) ans += deg[i]-1;
	}
	printf("%d\n", ans);
}