#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3000 + 10;
typedef long long LL;
const LL MOD = 998244353;

LL pw[N];

int n;
vector<int> g[N];


int tot[2][N/2], cnt[2][N/2], dis[N];
LL ans[N], res[N];



void bfs(int s1, int s2) {
	memset(tot,0,sizeof(tot));
	memset(dis,-1,sizeof(dis));
	memset(ans,0,sizeof(ans));
	queue<int> q;
	if(s1 == s2) {
		q.push(s1); dis[s1] = 0; 
	} else {
		q.push(s1); q.push(s2);
		dis[s1] = dis[s2] = 0;
	}

	vector<int> tmp;
	set<int> st1, st2;
	for(auto v: g[s1]) {
		if (v == s2) continue;
		tmp.push_back(v); st1.insert(v);
	}
	//printf("s1 = %d, s2 = %d\n", s1, s2);
	if (s1 != s2){
		//printf("s2 = %d\n", s2);
		for(auto v: g[s2]) {
			if (v == s1) continue;
			//printf("%d -> %d\n", s2, v);
			tmp.push_back(v); st2.insert(v);
		}
	}
	int mmx = 0;

	//printf("bfs %d %d\n", s1, s2);
	for (auto root: tmp) {
		queue<int> q; q.push(root); dis[root] = 1;
		int id = st1.count(root) ? 0: 1;
		cnt[id][1] ++; tot[id][1] ++;
	
		int mx = 1;
		while (q.size()) {
			int u = q.front(); q.pop(); 
			if(dis[u] > n/2) continue;
			mx = max(mx, dis[u]);
			for(auto v: g[u]) {
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					cnt[id][dis[v]] ++;
					tot[id][dis[v]] ++;
					q.push(v);
				}
			}
		}

		//printf("	root = %d, mx = %d\n", root, mx);
		for(int i=1;i<=min(mx,n/2);i++){
			int dia = s1==s2?2*i:2*i+1;
			//printf("	cnt[%d] = %d\n", i, cnt[i]);
			ans[dia] -= (pw[ cnt[0][i] + cnt[1][i] ] - 1);
			if(s1 != s2) ans[dia] += pw[cnt[0][i]] - 1;
			if(s1 != s2) ans[dia] += pw[cnt[1][i]] - 1;
			cnt[0][i] = cnt[1][i] = 0;
		}	
		mmx = max(mmx, mx);
	}
	int pre = s1==s2?1:2;
	for(int i=1;i<=min(mmx,n/2);i++){
		int dia = s1==s2?2*i:2*i+1;

		ans[dia] += pw[tot[0][i] + tot[1][i]] - 1;
		ans[dia] = (ans[dia] % MOD + MOD) % MOD;
		if(s1 != s2) {
			ans[dia] -= (pw[tot[0][i]] - 1);
			ans[dia] -= (pw[tot[1][i]] - 1);
		}
		res[dia] += ans[dia] * pw[pre] % MOD;
		pre += tot[0][i] + tot[1][i];
	} 
} 

int main() {
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%MOD;

	scanf("%d",&n);
	//n=3000;
	for(int mi=1;i<n;i++) {
		int u,v; 
		scanf("%d%d",&u,&v);
		//u=i+1,v=rand()%i+1;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	for(int i=1;i<=n;i++) bfs(i,i);
	for(int u=1;u<=n;u++)for(auto v:g[u]){
		if(u<v) bfs(u,v);
	}
	res[0] = n; res[1] = n - 1;
	for(int i=0;i<n;i++){
		res[i] = (res[i] % MOD + MOD) % MOD;
		printf("%lld ", res[i]);
	}
	printf("\n");
}