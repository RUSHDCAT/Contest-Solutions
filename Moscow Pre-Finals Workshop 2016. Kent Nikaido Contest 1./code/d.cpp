#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
struct Edge {
	int u,v,w;
	bool operator < (const Edge&o)const{
		return w < o.w;
	}
} e[N];
int n,m,par[N],deg[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
const int MOD = 1e9 + 7;

vector< pair<int,int> > g[N];
int pw[N],sz[N],tot=0;
LL ans=0;
void dfs(int u,int p){
	if(deg[u]%2==1){
		sz[u]=1;
	}
	for(auto e:g[u]){
		if(e.first==p)continue;
		//printf("%d -> %d\n", u,e.first);
		dfs(e.first,u);
		sz[u]+=sz[e.first];

		int x=sz[e.first];
		int y=tot-x;
		if(x%2==1 && y%2==1){
			ans += 1LL * pw[e.second];
			ans %= MOD;
		}
	}

}
int main() {
	pw[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*2%MOD;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		par[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].u,&e[i].v); e[i].w=i; ans=ans+pw[i];ans%=MOD;
		deg[e[i].u]++; deg[e[i].v]++;
		if(find(e[i].u) != find(e[i].v)) {
			par[find(e[i].u)] = find(e[i].v);
			g[e[i].u].push_back(make_pair(e[i].v,i));
			g[e[i].v].push_back(make_pair(e[i].u,i));
		}
	}
	for(int i=1;i<=n;i++)if(deg[i]%2==1)tot++;
	dfs(1,1);	
	cout<<ans<<endl;

}