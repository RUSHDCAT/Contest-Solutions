#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,s,m;
vector<int> g[N];
int dis[N],par[N];

void dfs(int u,int p){
	dis[u]=dis[p]+1;
	par[u]=p;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
	}
}

bool vis[N]; int tot=0; set< pair<int,int> > st;
void tag(int now) {
	while(now!=m && vis[now]==0){
		vis[now]=1;
		st.erase(make_pair(dis[now],now)); tot++;
		now=par[now];
	}
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&s,&m);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v; scanf("%d%d",&u,&v);
			g[u].push_back(v); g[v].push_back(u);
		}

		dis[s]=-1; dfs(s,s);
		
		int ans=1e9;

		int mx_=0; for(int i=1;i<=n;i++) mx_=max(mx_,dis[i]);
		ans=min(ans, 2*(n-1)-mx_);
		if(s==m){
			printf("%d\n", mx_); continue;
		}


		dis[m]=-1; dfs(m,m);
		for(int i=1;i<=n;i++) vis[i]=0;

		st.clear();		
		for(int i=1;i<=n;i++){
			st.insert(make_pair(dis[i], i));
		}
		tot=0;
		tag(s);

 		while(st.size()){
 			pair<int,int> now = *st.rbegin();
 			if(now.first == 0) break;
 			int tmpans = tot*2 - dis[s] + now.first;
 			//printf("tmpans = %d\n", tmpans);
 			ans=min(ans,tmpans);
 			//printf("tag %d\n", now.second);
 			tag(now.second);
 		}
 		printf("%d\n", ans);
	}
}