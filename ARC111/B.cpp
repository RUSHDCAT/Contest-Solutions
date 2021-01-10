#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
int n;
int par[N],sz[N],sz2[N],vis[N];
int find(int x) {
	return par[x]==x?x:par[x]=find(par[x]);
}
int main() {
	for(int i=0;i<N;i++){
		par[i]=i; sz[i]=1;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int u,v; scanf("%d%d",&u,&v);vis[u]=vis[v]=1;
		if(find(u)!=find(v)){
			sz[find(v)] += sz[find(u)];
			sz2[find(v)] += sz2[find(u)] + 1;
			par[find(u)]=find(v);
		}else{
			sz2[find(u)]++;
		}
	}
	int ans=0;
	for(int i=1;i<N;i++){
		if(find(i)==i && vis[i]){
			if(sz2[find(i)] + 1 == sz[find(i)]) ans += sz[find(i)] - 1;
			else ans += sz[find(i)];
		}
	}
	cout<<ans<<endl;
}