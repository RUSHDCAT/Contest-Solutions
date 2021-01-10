#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
#define pii pair<long long, int >
using namespace std;
const int N = 1e3 + 50, M = 1e5 + 7;

int cnt = 1, S, T, pre[N], id[N], b[N];
long long dis[N], h[N]; 
bool vis[N];
struct node{
   int v, c, w, nex;
}e[M];
void addadge(int u, int v, int c, int w){ 
	//printf("%d %d %d %d\n", u, v, c, w);
	e[++cnt] = node{v, c, w, b[u]}; b[u] = cnt; 
	e[++cnt] = node{u, 0, -w, b[v]}; b[v] = cnt;
}
long long mcmf(){
	memset(h, 0, sizeof(h));
	priority_queue<pii, vector<pii >, greater<pii > > Q; 
	int maxflow = 0;
	long long cost = 0;
	while (1){
		//printf("*^");
		memset(dis, INF, sizeof(dis)); 
		Q.push(pii{0, S}); dis[S] = 0;
		while (!Q.empty()){
			pii q = Q.top(); Q.pop();
			int now = q.second;
			//printf("%d %lld %lld ^*^\n", now, q.first, dis[now]);
			if (dis[now] < q.first) continue;
			for (int i = b[now]; i != -1; i = e[i].nex){
				//printf("^*^%d", i);
				if (e[i].c > 0 && dis[e[i].v] > dis[now] + e[i].w + h[now] - h[e[i].v]){
					dis[e[i].v] = dis[now] + e[i].w + h[now] - h[e[i].v]; 
					pre[e[i].v] = now;
					id[e[i].v] = i;
					Q.push(pii{dis[e[i].v], e[i].v});
				}
			}
		}
		if (dis[T] == dis[0]) break;
		int flow = INF;
		for (int i = T; i != S; i = pre[i]) flow = min(flow, e[id[i]].c); 
		maxflow += flow; cost += 1LL * flow * (dis[T] - h[S] + h[T]);
		for (int i = T; i != S; i = pre[i]){
			//printf("^*^");
			e[id[i]].c -= flow;
			e[id[i] ^ 1].c += flow; 
		}
		for (int i = 1; i <= T + 2; ++i){ 
			h[i] += dis[i];
		}
	}
	return cost;
}
	

int a[N][N];

int main(){
	int n, k, t;
	scanf("%d%d%d", &n, &k, &t);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k + 1; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int SS = n + k + 2, TT = n + k + 3, ss = SS + 2, tt = TT + 2;
	long long ans = 1e9;
	vector<int> ppp(n + 1);

	for (int my = 1; my <= (n + 1) / 2; my++){

		memset(b, -1, sizeof(b)); cnt = 1;
		for (int i = 1; i <= n; i++){
			addadge(SS, i, 1, 0);
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= k + 1; j++){
				addadge(i, j + n, 1, a[i][j]);
			}
		}
		for (int i = 1; i <= k; i++){
			if (i != t){
				addadge(n + i, TT, my - 1, 0);
			}
		}
		//printf("^*^");
		addadge(n + t, TT, INF, 0);
		addadge(n + k + 1, TT, INF, 0);
		addadge(TT, SS, INF, 0);

		addadge(ss, TT, my, 0);
		addadge(n + t, tt, my, 0);
		long long cost = 0;
		S = ss; T = tt;

		cost += mcmf();

		//printf("^*^");
		S = SS; T = TT;
		cost += mcmf();

		//printf("^*^");
		vector<int > vec(n + 1);
		for (int i = n + 1; i <= n + k + 1; i++){
			for (int j = b[i]; j != -1; j = e[j].nex){
				if (e[j].v >= 1 && e[j].v <= n && e[j].c == 1){
					vec[e[j].v] = i - n;
				}
			}
		}

	//	printf("%d %lld^*^\n", my, cost);

		if (cost < ans){
			ans = cost;
			ppp = vec;
		}


	}	
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) printf("%d%c", ppp[i], i == n ? '\n' : ' ');
	return 0;	
}