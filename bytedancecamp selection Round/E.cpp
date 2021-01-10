#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m;
LL a[N], b[N];
LL gcd(LL x, LL y) {
	return y==0?x:gcd(y,x%y);
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//a[i]=rand()%100+1;
	}
	
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		//b[i]
	}
	sort(a+1,a+1+n);

	if(n==1) {
		for(int i=1;i<=m;i++){
			printf("%lld%c", b[i]+a[1], i==m?'\n':' ');
		}
		return 0;
	}

	LL g=a[2]-a[1];
	for(int i=3;i<=n;i++)g=gcd(a[i]-a[i-1],g);

	for(int i=1;i<=m;i++){
		printf("%lld%c", gcd(g, a[1]+b[i]), i==m?'\n':' ');
	}
}