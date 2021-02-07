#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	int n; scanf("%d",&n);
	vector<LL> a(n),b(n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);	
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	LL mxa=0,mxb=0,ans=0;
	for(int i=0;i<n;i++) {
		mxa=max(mxa,a[i]); mxb=max(mxb,b[i]);
		ans=max(ans,b[i]*mxa);
		printf("%lld\n", ans);
	}
}