#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,m,nex[N],vis[N],in[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			vis[i]=0,nex[i]=0;in[i]=0;
		}
		int ans=0;
		set<int> s;
		for(int i=1;i<=m;i++){
			int x,y; scanf("%d%d",&x,&y);
			nex[x] = y; in[y] = 1;

			s.insert(x);
			if(x!=y) ans++;
		}

		for(auto p: s) {
			int now=p;
			if(nex[now] == now) continue;
			if(in[now] == 0) {
				if(vis[now]==0){
					while(now>0 && vis[now]==0){
						vis[now]=1; now=nex[now];
					}
					if(now) ans++;
				}				
			}
		}
		
		for(auto p: s) {
			int now=p;
			if(nex[now] == now) continue;
			if(vis[now]==0){
				while(now>0 && vis[now]==0){
					vis[now]=1; now=nex[now];
				}
				if(now) ans++;
			}
		}
		printf("%d\n", ans);
	}
}