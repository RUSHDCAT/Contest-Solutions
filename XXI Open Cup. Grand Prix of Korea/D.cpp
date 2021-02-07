#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int n, m;

struct Edge {
	int u, v, w; bool ontree;
	bool operator < (const Edge & o) const {
		return w > o.w;
	}
	void read() {
		scanf("%d%d%d",&u,&v,&w);
	}
} e[N];


int par[N], sz[N];
int find(int x) {
	return par[x]==x?x:par[x]=find(par[x]);
}
int mn[N][20], fat[N][20], dep[N]; bool vis[N];
vector< pair<int,int> > g[N];

void dfs(int u,int p,int w) {
	if(vis[u]) return;
	dep[u]=dep[p]+1;
	vis[u]=1; fat[u][0]=p; mn[u][0]=w;
	for(auto e: g[u]) {
		int v=e.first; if(v==p) continue;
		dfs(v,u,e.second); 
	}
}
int query(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	int d=dep[u]-dep[v];
	int res=1e9;
	for(int i=19;i>=0;i--){
		if(d>>i&1) {
			res=min(res,mn[u][i]);
			u=fat[u][i]; 
		}
	}
	if(u==v)return res;
	for(int i=19;i>=0;i--){
		if(fat[u][i]!=fat[v][i]){
			res=min(res,mn[u][i]); res=min(res,mn[v][i]);
			u=fat[u][i], v=fat[v][i];
		}
	}
	res=min(res,mn[u][0]);
	res=min(res,mn[v][0]);
	return res;
}	
int main() {
	scanf("%d%d", &n,&m);
	for(int i=1;i<=n;i++) par[i]=i;

	for(int i=1;i<=m;i++) {
		e[i].read(); e[i].ontree = false;
	}	
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		if(find(e[i].u) != find(e[i].v)) {
			par[find(e[i].u)] = find(e[i].v);
			g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
			g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
			e[i].ontree = 1;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0) {
			dfs(i,i,0);
		}
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			fat[j][i]=fat[fat[j][i-1]][i-1];
			mn[j][i]=min(mn[j][i-1], mn[fat[j][i-1]][i-1]);
		}
	}	
	for(int i=1;i<=m;i++){
		if(e[i].ontree==false && query(e[i].u,e[i].v) != e[i].w) {
			return !printf("-1\n");
		}  
	}

	for(int i=1;i<=n;i++) par[i]=i,sz[i]=1;
	LL ans=0;
	for(int i=1;i<=m;i++) {
		if(e[i].ontree == true) {
			//printf("unite %d(%d) %d(%d) : %d\n", e[i].u, sz[find(e[i].u)], e[i].v, sz[find(e[i].v)], e[i].w);
			ans += 1LL * sz[find(e[i].u)] * sz[find(e[i].v)] * e[i].w;
			sz[find(e[i].v)] += sz[find(e[i].u)];
			par[find(e[i].u)] = find(e[i].v);
		}
	}
	vector<int> vec;
	int tot=n;
	for(int i=1;i<=n;i++){
		if(find(i)==i) {
			//printf("# %d\n", sz[find(i)]);
			vec.push_back(sz[find(i)]);
		}
	}
	for(auto p: vec) {
		tot -= p;
		ans += 1LL * tot * p;
	}
	cout << ans << endl;
}