#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
vector<int> g[N];
const LL mod = 1e9 + 7;

pair<int,int> bfs(int u, int f[], int dis[]) {
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=-1;
	q.push(u); dis[u]=0;
	while(q.size()){
		int now=q.front(); q.pop();
		for(auto v:g[now]){
			if(dis[v]==-1){
				dis[v]=dis[now]+1; q.push(v);
			}
		}
	}
	int mx=-1,id=-1;
	for(int i=1;i<=n;i++){
		if(dis[i]>mx){
			mx=dis[i]; id=i;
		}
	}

	for(int i=0;i<=n;i++) f[i]=0;
	for(int i=1;i<=n;i++) f[dis[i]]++;
	for(int i=1;i<=n;i++) f[i]+=f[i-1];

	return make_pair(id,mx);
}
void solve() { 
	LL pw[N]; pw[0] = 1; for (int i =1; i < N;i ++)pw[i]=pw[i-1]*2%mod;

	int f[N], g[N];
	pair<int,int> p1 = bfs(1, f, g);
	pair<int,int> p2 = bfs(p1.first, f, g);
	int s = p1.first, t = p2.first;
	int len = p2.second;

	int dis_s[N], dis_t[N];
	bfs(s, f, dis_s); bfs(t, g, dis_t);
	LL res[N] = {0}; // res[i]: ans <= i
	//printf("s=%d,t=%d\n", s,t);
	int low = 0; for (int i = 1; i <= n; i ++) low = max(low, min(dis_t[i], dis_s[i]));
	LL ans = 1LL * len * pw[n] % mod;
	//printf("low=%d\n", low);
	for (int i = low; i < len; i ++) {
		int c1 = n - f[i];
		int c2 = n - g[i];
		//printf("<=%d, %lld\n", i,pw[n-c1-c2]);
		(ans -= pw[n - c1 - c2 + 1]) %= mod;
	} 
	ans = (ans % mod + mod) % mod;
	cout << ans << endl;
}	

int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}	
	solve();
}