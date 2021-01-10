#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,m,u[N],v[N],c[N];
bool vis[N],flag[N];
pair<int,int> dir[N];
vector< pair<int,int> > g[N];
void dfs(int u, int p) {
	vis[u]=1;
	for(auto e: g[u]){
		if(e.first == p || flag[e.second]) continue;
		//printf("# %d->%d\n", u,e.first);
		flag[e.second] = 1;
		if(vis[e.first] == 0) {
			dir[e.second] = make_pair(u, e.first);
			dfs(e.first, u);
		} else {
			dir[e.second] = make_pair(u, e.first); 
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
	}	
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m;i++){
		if(c[u[i]] == c[v[i]]) {
			g[u[i]].push_back(make_pair(v[i], i));
			g[v[i]].push_back(make_pair(u[i], i));
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])
		dfs(i,i);
	}
	for(int i=1;i<=m;i++){
		if(c[u[i]] == c[v[i]]) {
			if(dir[i] == make_pair(u[i],v[i])) printf("->\n"); else printf("<-\n");
		}else{
			if(c[u[i]]<c[v[i]]) printf("<-\n"); else printf("->\n");
		}
	}
}