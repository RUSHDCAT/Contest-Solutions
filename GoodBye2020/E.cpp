#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
const LL MOD = 1e9 + 7;
int t,n;
LL x[N];
int main() {	
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		LL c[61] = {0};

		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(int j=0;j<60;j++){
				c[j] += (x[i]>>j)&1;
			}
		}
		//printf("%d %d\n", c[0],c[1]);
		LL ans=0;
		for(int i=1;i<=n;i++){
			LL s1=0,s2=0;

			for(int j=0;j<60;j++){
				if(x[i]>>j&1) {

					s1 += (1LL<<j) % MOD * c[j] % MOD;
					s1 %= MOD;
					s2 += (1LL<<j)%MOD * n % MOD;
					s2 %= MOD;
				} else {
					s2 += (1LL<<j)%MOD * c[j] % MOD;;
					s2 %= MOD;
				}

			}

			ans += s1 * s2;
			ans = ans % MOD;
		}
		printf("%lld\n", ans);
	}
}