#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
LL sum[N<<2];
int n, k, w[N], l[N], tot, C;
vector<int> g[N];

int L[N],R[N];
void update(int l,int r,int rt,int pos,LL x){
	if(l==r) {
		sum[rt]=x; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
LL query(int l,int r,int rt,int L,int R){
	if(!(1<=L && L<=R && R<=tot)) while(1);
	if(L<=l&&r<=R) return sum[rt];
	int mid=(l+r)>>1;
	LL ans=0;
	if(L<=mid) ans+=query(l,mid,rt<<1,L,R);
	if(R >mid) ans+=query(mid+1,r,rt<<1|1,L,R);
	return ans;
}
LL Q(int u) {
	int l = L[u], r = R[u];
	return query(1,tot,1,l,r);
}
bool vis[N];
void dfs(int u){
	if(vis[u]==1) while(1);
	L[u]=++C; vis[u]=1;
	if(g[u].size()==0) {
		if(u <= n) while(1);
		// printf("update u = %d, val = %d\n", u, w[u - n]);
		update(1,tot,1, L[u], w[u - n]);
	}
	for(auto v: g[u]) {
		dfs(v);
	}
	R[u]=C;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d", &n, &k);
	tot=2*n+1;
	for(int i=1;i<=n+1;i++) {
		scanf("%d",&w[i]);
	}		
	for(int i=1;i<=n;i++){
		int lef,rig;
		scanf("%d%d%d",&l[i],&lef,&rig);
		if(lef < 0) g[i].push_back(-lef + n); else g[i].push_back(lef);
		if(rig < 0) g[i].push_back(-rig + n); else g[i].push_back(rig);
	}
	dfs(1);
	for(int i=1;i<=k;i++){
		int q; scanf("%d",&q);
		if(q==1) {
			int k,v; scanf("%d%d",&k,&v);
			int pos=L[k+n];
			update(1,tot,1,pos,v);
		}else{
			int x; scanf("%d",&x);
			int lson=g[x][0]; LL sumL = Q(lson);
			int rson=g[x][1]; LL sumR = Q(rson);
			double ans = (double)l[x] * sumR / (sumL + sumR);
			printf("%.14f\n", ans);
		}
	}
}