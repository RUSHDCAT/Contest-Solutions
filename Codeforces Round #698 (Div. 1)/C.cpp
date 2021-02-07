#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5000 + 10;
int n;
LL x[N],y[N];
int p[N];
bool chk(int i){
	pair<LL,LL> v1=make_pair(x[p[i]]-x[p[i-1]],y[p[i]]-y[p[i-1]]);
	pair<LL,LL> v2=make_pair(y[p[i+1]]-y[p[i]],x[p[i+1]]-x[p[i]]);
	return v1.first *  v2.first + v1.second * v2.second < 0;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	p[1]=1,p[2]=2;
	for(int i=3;i<=n;i++){
		p[i]=i;
		int cur = i-1;
		while (cur >= 2 && chk(cur) == false) {
			swap(p[cur], p[cur+1]); cur--;
		}
		if (chk(2) == false) swap(p[1],p[2]);
	}
	for(int i=1;i<=n;i++) printf("%d ", p[i]);
}