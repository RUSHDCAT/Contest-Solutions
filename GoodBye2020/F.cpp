#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
const LL MOD = 1e9 + 7;

int n, m;
int par[N],sz[N],ok[N];
bool vis[N];
int find(int x) {
	return par[x] == x ? x: par[x] = find(par[x]);
}

int x[N][3], k[N];
LL pw[N];
int main() {
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%MOD;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d", &k[i]);
		for(int j=1;j<=k[i];j++) {
			scanf("%d",&x[i][j]); vis[x[i][j]] = 1;
		}
	}

	for(int i=1;i<=m;i++){
		par[i]=i, sz[i]=1;
	}
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(k[i]==2) {
			int u=x[i][1], v=x[i][2];

			if(find(u) != find(v)) {
				if(ok[find(u)] && ok[find(v)]) continue;
				ans.push_back(i);
				ok[find(v)] |= ok[find(u)];
				sz[find(v)] += sz[find(u)];
				par[find(u)] = find(v);
			}
		} else {
			int u=x[i][1];
			if(ok[find(u)]==0){
				ok[find(u)]=1; ans.push_back(i);
			}
		}
	}


	LL sum=1;
	for(int i=1;i<=m;i++){
		if(vis[i]==0)continue;
		if(find(i)==i){		
			//printf("i=%d, sz=%d\n", i,sz[find(i)]);
			if(ok[i]) {
				sum = sum * pw[sz[find(i)]];
				sum %= MOD;
			} else {
				sum = sum * pw[sz[find(i)] - 1];
				sum %= MOD;
			}
		}
	}
	printf("%lld %d\n", sum, ans.size());
	sort(ans.begin(),ans.end());
	for(auto x: ans) {
		printf("%d ", x);
	}
	printf("\n");

}