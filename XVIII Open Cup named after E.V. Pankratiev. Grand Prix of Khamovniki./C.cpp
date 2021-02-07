#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int n, m;
vector<int> g[N];
vector< pair<int,int> > vec;
void bfs(int u) {
	int dis[N]; memset(dis,-1,sizeof(dis));
	queue<int> q; dis[u]=0; q.push(u);
	while(q.size()) {
		int u=q.front(); q.pop();
		for(auto v: g[u]){
			if(dis[v]==-1) {
				q.push(v); dis[v]=dis[u]+1;
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++) {
		mx=max(mx,dis[i]);
		if(dis[i]==-1) {
			printf("No\n"); exit(0);
		}
	}
	vec.push_back(make_pair(mx,u));
}

namespace Hungary {
	int n, match[N];
	bool us[N];
	vector<int> gg[N];
	bool dfs(int x)
	{
	    for(int i=0;i<gg[x].size();i++)
	    {
	        if(us[gg[x][i]]) continue;
	        us[gg[x][i]] = 1;
	        if(match[gg[x][i]] == -1 || dfs(match[gg[x][i]]))
	        {
	            match[gg[x][i]] = x; 
	            return 1;
	        }
	    }
	    return 0;
	}
	// 0 - index
	int hungary()
	{
	    memset(match, -1, sizeof(match));
	    int tot = 0;
	    for(int i=0;i<n;i++)
	    {
	        memset(us, 0, sizeof(us));
	        if(dfs(i)) tot ++;
	    }
	    return tot;
	}
}
void solve(int u) {
	int dis[N]; memset(dis,-1,sizeof(dis));
	queue<int> q; dis[u]=0; q.push(u);
	while(q.size()) {
		int u=q.front(); q.pop();
		for(auto v: g[u]){
			if(dis[v]==-1) {
				q.push(v); dis[v]=dis[u]+1;
			}
		}
	}
	Hungary::n = n;
	for (int i = 0; i < n; i ++) Hungary::gg[i].clear();
	int cnt = 0;
	for (int i = 1; i <= n; i ++)  {
		if (dis[i] == 2) cnt ++;
		for (auto j: g[i]) {
			if (dis[i] == 2 && dis[j] == 1) {
				Hungary::gg[i-1].push_back(j-1);
			}
		}
	}
	if (Hungary::hungary()==cnt) {
		vector< pair<int,int> > ans;
		for (int i = 1; i <= n; i ++) {
			if (i == u) continue;
			if (dis[i] == 1) {
				if (Hungary::match[i-1] == -1) ans.push_back(make_pair(i, -1));
				else ans.push_back(make_pair(i, Hungary::match[i-1] + 1));
			} 
		}
		printf("Yes\n");
		printf("%d %d\n", u, ans.size());
		for(auto p: ans) {
			printf("%d %d\n", p.first, p.second);
		}
		exit(0);
	}
}	
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {
		bfs(i);
	}
	sort(vec.begin(),vec.end()); reverse(vec.begin(),vec.end());
	for(auto p: vec) {
		if (p.first <= 2) {
			solve(p.second);
		}
	}
	printf("No\n");
}