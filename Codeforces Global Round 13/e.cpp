#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
vector<int> g[N];
int fib[N], rk[N], par[N], deg[N], sz[N], dep[N];
set<int> s; 
map<int,int> mm;
void dfs(int u, int p) {
	par[u] = p;
	sz[u] = 1;
	map<int,int> mp;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		if (s.count(sz[v])) mp[sz[v]] ++; 
	}
	mp[n - sz[u]] ++;
	if (sz[u] == 1) {
		dep[u] = 1;
	}

	for (auto p: mp) if (p.second > 2) {
		printf("NO\n"); exit(0);
	}
}
int fib2[100];
int main() {
	fib[0] = 1, fib[1] = 1;
	fib2[0] = 0, fib2[1] = 0;

	for (int i = 2; i <= 26; i ++) {
		fib[i] = (fib[i-1] + fib[i-2]); s.insert(fib[i]);
	}
	for (int i = 2; i <= 26; i++) {
		fib2[i] = fib2[i-1] + fib2[i-2] + 2 * fib[i];
	}

	s.insert(1);
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);   
	}
	if (n<=2) return !printf("YES\n");
	if (s.count(n) == 0) return !printf("NO\n");

	int rt = -1;
	for (int i=1;i<=n;i++) if (g[i].size()>=2) rt=i;
	dfs(rt, rt);
	
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		if (g[i].size() >= 26) return !printf("NO\n");
		sum += fib[g[i].size() + 1];
		//printf("i=%d, #%d\n", i,fib[g[i].size() + 1]);
	}
	int pos = -1;
	for (int i=1;i<=26;i++) if(fib[i]==n) {pos=i; break;}
	//printf("sum = %d, %d\n", sum, fib2[pos]);
	if (sum > fib2[pos]) return !printf("NO\n"); 

	printf("YES\n");
		
}