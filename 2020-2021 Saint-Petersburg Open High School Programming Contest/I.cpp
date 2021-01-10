#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m;
vector<int> g[N];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; 
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> c(n+2,0);
	for(auto x: g[1]) {
		for(auto y: g[x]) {
			if(y==1) continue;
			c[y] ++;
		}
	}
	LL ans=0;
	for(int i=2;i<=n;i++)ans+=1LL*c[i]*(c[i]-1);
	cout<<ans<<endl;

}