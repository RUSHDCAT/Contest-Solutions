#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL n;
int main() {
	cin >> n;
	LL ans = n - 1;
	for(LL i=1;i*i<=n;i++){
		if(n%i==0){
			LL x=i, y=n/i;
			ans=min(ans,abs(x-y));
		}
	}

	for(LL i=1;i*i<=2*n-1;i++){
		if((2*n-1)%i==0) {
			{
				LL a=i,b=(2*n-1)/i;
				LL k=a,x=(b-1)/2;
				if(b%2 && k>=1 && x>=1 && k%2==1){
					//printf("#%lld %lld\n", k,x);
					ans=min(ans,abs(k-(x+1)));
				}
			}
			{
				LL a=i,b=(2*n-1)/i; swap(a,b);
				LL k=a,x=(b-1)/2;
				if(b%2 && k>=1 && x>=1 && k%2==1){
					//printf("k=%lld,x=%lld\n", k,x);
					ans=min(ans,abs(k-(x+1)));
				}
			}
		}
	}
	//printf("#%lld\n", ans);
	for(LL i=1;i*i<=2*n;i++){
		if((2*n)%i==0) {
			{
				LL a=i,b=2*n/i;
				LL k=a,x=(b-1)/2;

				if(b%2 && k>=1 && x>=1){
					ans=min(ans,abs(k-(x+1)));
				}
			}
			{
				LL a=i,b=2*n/i; swap(a,b);
				LL k=a,x=(b-1)/2;
				if(b%2){
					ans=min(ans,abs(k-(x+1)));
				}
			}

		}
	}

	for(LL i=1;i*i<=2*n+1;i++){
		if((2*n+1)%i==0) {
			{
				LL a=i,b=(2*n+1)/i;
				LL k=a,x=(b-1)/2;
				if(b%2 && k>=1 && x>=1 && k%2==1){
					ans=min(ans,abs(k-(x+1)));
				}
			}
			{
				LL a=i,b=(2*n+1)/i; swap(a,b);
				LL k=a,x=(b-1)/2;
				if(b%2 && k>=1 && x>=1 && k%2==1){
					ans=min(ans,abs(k-(x+1)));
				}
			}

		}
	}

	cout<<ans<<endl;
}