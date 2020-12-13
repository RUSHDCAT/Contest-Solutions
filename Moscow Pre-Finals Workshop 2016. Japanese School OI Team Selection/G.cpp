#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, a[N], c[N];
vector<int> g[N]; int nex[N],vis[N];
bool ring[N];

LL val[N],f[N][2];
void dfs(int u,int p){
	int son=0;
	for(auto v:g[u]){
		if(v==p || ring[v])continue;
		son++;
	}
	if(son==0 && ring[u]==0){
		val[u]=0;
		return;
	}
	int mx=0;
	for(auto v:g[u]){
		if(v==p || ring[v])continue;
		//printf("%d -> %d\n", u,v);
		dfs(v,u);
		val[u]+=val[v]; mx=max(mx,c[v]);
	}
	val[u]+=mx;
	//printf("val[%d] = %lld\n", u, val[u]);
	if(ring[u]){
		f[u][1] = val[u] + c[u];
		f[u][0] = 0;
		for(auto v:g[u]){
			if(v==p||ring[v])continue;
			f[u][0]+=val[v];
		}
		f[u][0] += c[u];
		
		//printf("! %d / %lld %lld\n", u,f[u][0],f[u][1]);
	}	

}

int par[N],done[N],sz[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
int main() {
	for(int i=0;i<N;i++){
		par[i]=i;sz[i]=1;
	}
	LL ans = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&c[i]);ans+=c[i];
	}
	for(int i=1;i<=n;i++){
		if(find(a[i]) != find(i)) {
			sz[find(i)] += sz[find(a[i])];
			par[find(a[i])] = find(i);
		}
		g[a[i]].push_back(i); 
		g[i].push_back(a[i]);
		nex[i] = a[i];
	}

	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(done[find(i)])continue;
		int now=i;
		vector<int> stk;
		while(1){
			if(vis[now]==1) {
				done[find(now)] = 1;
				while(1) {
					ring[stk.back()]=1;
					if(stk.back() == now) break;
					stk.pop_back();
				}
				break;
			}
			stk.push_back(now);
			vis[now]=1; now=nex[now];
		}
	}
	int ringcnt=0;
	for(int i=1;i<=n;i++){
		if(ring[i]){
			ringcnt++;
			//printf("ring %d\n", i);
			dfs(i,i);
			//printf("solve %d : (%lld,%lld)\n", i,f[i][0],f[i][1]);
		}
	}
	if(sz[find(1)] == n && ringcnt == n) {
		printf("0\n"); return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(ring[i] && vis[i]==0){
			int now=i; 
			vector<int> v;
			while(1){
				v.push_back(now);  vis[now]=1;
				//printf("# %d: %lld %lld\n", now, f[now][0], f[now][1]);
				if(now==i && v.size()>1) break;
				now=nex[now];
			}
			v.pop_back();

			//printf("!\n");
			for(int j=0;j<v.size();j++) {
				//printf("(%lld,%lld)\n", f[p][0],f[p][1]);
				f[v[j]][1] -= (j==0)?c[v.back()]:c[v[j-1]];
				//printf("(%lld,%lld)\n", f[v[j]][0],f[v[j]][1]);
			}
			LL dp[2];


			memset(dp,0,sizeof(dp)); dp[1]=-1e18;
			for(int i=0;i<(int)v.size();i++){
				LL g[2]; memset(g,0,sizeof(g));
				g[0]=dp[0]+f[v[i]][0];
				g[1]=max(max(dp[0],dp[1])+f[v[i]][1], dp[1]+f[v[i]][0]);
				dp[0]=g[0],dp[1]=g[1];
			}	
			ans -= dp[1];


		}
	}
	printf("%lld\n", ans);
}