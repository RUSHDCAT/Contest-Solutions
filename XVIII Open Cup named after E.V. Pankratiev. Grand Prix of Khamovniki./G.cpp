#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
LL x[N], y[N]; int n;
int main() {
	scanf("%d", &n);
	for(int i=0;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}


	pair<LL,LL> v1=make_pair(x[1]-x[0],y[1]-y[0]);
	pair<LL,LL> v2=make_pair(x[n]-x[n-1],y[n-1]-y[n]);

	bool flag = v1.first*v2.second == v1.second*v2.first;

	
	for(int i=)
}