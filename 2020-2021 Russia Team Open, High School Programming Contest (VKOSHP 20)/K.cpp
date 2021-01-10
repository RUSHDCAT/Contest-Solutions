#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n, m, k, c[N];
vector<int> g[N];
 
int par[N], ans[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
set< pair<LL,int> > st;
 
 
int main() {
	for(int i=0;i<N;i++) par[i]=i;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]); -- c[i];
	}
	for(int i=1;i<=m;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	set< pair<int,int> > st;
	for(auto x: g[1]) {
		int d = (c[x] - c[1] + k) % k;
		st.insert(make_pair(d - 1, x));
	}

	LL s = 0;
	st.insert(make_pair(0,1));
	set<int> vis;
	while (st.size()) {
		pair<LL,int> now = (*st.begin()); st.erase(now);
		if (vis.count(now.second)) continue;
		vis.insert(now.second);
		//printf("%lld %d\n", now.first, now.second);
		s = now.first;
		//printf("sum += %lld\n", now.first);
		int u = now.second;
		for (auto v: g[u]) {
			if(vis.count(v)) continue;
			LL d = ((c[v] - c[u]) % k + k) % k;
			//printf("ins %lld %d\n", s+d,v);
			st.insert( make_pair(s + d - 1, v) );
		}
		c[u] = ((c[u] - s) % k + k) % k;
	}
	for(int i=1;i<=n;i++){
		int x = (c[i] + s) % k;
		printf("%d ", x+1);
	}
}



