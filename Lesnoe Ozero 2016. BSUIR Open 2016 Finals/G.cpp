#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL n,t;
int main() {
	scanf("%lld%lld",&n,&t);
	LL q,a,b,m;
	scanf("%lld%lld%lld%lld",&q,&a,&b,&m);
	int ans=0;
	for(int i=1;i<=t;i++){
		q=(a*q+b)%m;
		LL k=q%(n*n+1);
		k=n*n-k;
		bool ok=0;
		
		LL lim1 = min((n-1)/2, (n*n-k)/n);
		lim1 = min(lim1, k/n);

		for(int x=0;x<=lim1;x++) {
			if((k-n*x)%(n-2*x)==0) {
				ok=1; break;
			}
		}
		if(ok) {
			ans++; continue;
		}

		if(n%2==0){
			int x=n%2; if(k-n*x==0) ok=1;
		}
		/*
		LL low=max(n/2+1,(n*n-k+n-1)/n); low=max(low,(k+n-1)/n);
		//printf("low=%lld,n=%lld\n", low,n);
		for(int x=low;x<=n;x++) {
			if((k-n*x)%(n-2*x)==0) {
				//printf("#\n");
				ok=1; break;
			}			
		}
		*/

		if(ok)ans++;
	}
	cout<<ans<<endl;
}