#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n,s[N],t[N],sum[N], mx[N<<2];
void build(int l,int r,int rt){
	if(l==r){
		mx[rt]=sum[l]; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
int query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R)return mx[rt];
	int ans=0;
	int mid=(l+r)>>1;
	if(L<=mid) ans=max(query(l,mid,rt<<1,L,R),ans);
	if(R >mid) ans=max(query(mid+1,r,rt<<1|1,L,R),ans);
	return ans;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i],&t[i]);
		sum[s[i]]++, sum[t[i]]--;
	}
	for(int i=1;i<=100000;i++)sum[i]+=sum[i-1];
	int res=1e9;
	int B=100000;
	build(1,B,1);
	for(int i=1;i<=n;i++){
		int tmp=query(1,B,1,s[i],t[i]-1) - 1;
		if(s[i]>=2) tmp=max(tmp, query(1,B,1,1,s[i]-1));
		if(t[i]<=B) tmp=max(tmp, query(1,B,1,t[i],B));
		//printf("i=%d,tmp=%d\n", i,tmp);
		res=min(res,tmp);
	}
	printf("%d\n", res);
}