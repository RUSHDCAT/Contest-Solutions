#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n;
int sg[N],c[N],a[N];

int mx[N<<2], mxpos[N];
void update(int l,int r,int rt,int pos,int x) {
	if(l==r){
		mx[rt]=x; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	mx[rt] = min(mx[rt<<1], mx[rt<<1|1]); 
}

int query(int l,int r,int rt,int pos) {
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(mx[rt<<1]<pos) return query(l,mid,rt<<1,pos);
	return query(mid+1,r,rt<<1|1,pos);
}	

int main() {
	scanf("%d", &n);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&c[i],&a[i]);
	}
	update(0,n,1,0,1);

	for(int i=2;i<=n;i++){
		int x=i-c[i];
		int pos=query(0,n,1,x);
		sg[i] = pos;
		update(0,n,1,pos,i);
		// printf("sg[%d] = %d\n", i, sg[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(a[i]&1) ans^=sg[i];
	printf("%s\n", ans?"First":"Second");
}