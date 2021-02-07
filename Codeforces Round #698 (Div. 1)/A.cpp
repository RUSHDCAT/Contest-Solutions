#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
LL n, k, a[N];
LL gcd(LL x, LL y) {
	return y==0?x:gcd(y,x%y);
}
LL pre[N], suf[N];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&k); 
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);a[i]*=2; 
		}
		sort(a+1,a+1+n);
		LL g=1;
		for(int i=2;i<=n;i++){
			g=gcd(g,a[i+1]-a[i]);
		}
		bool ok=0;
		for(int i=1;i<=n;i++){
			LL tmp=k-(a[i]/2);
			if(tmp%g==0) ok=1;
		}
		printf("%s\n", ok?"YES":"NO");
	}
}