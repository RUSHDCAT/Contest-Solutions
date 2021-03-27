#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
const double eps = 1e-6;
int main() {
	scanf("%d", &t);
	while (t --) {
		int n, l, k;
		scanf("%d%d%d",&n,&l,&k);

		LL ans = 1e18, id = -1;
		LL nex;
		int x = (int)(log2(n) + 0.5);

		for (LL i = 1; i <= l; i = nex + 1) {
		    nex = l / (l / i);
		    if (i > k) break;

		    if (nex <= k) 
		    {
		    	LL tmp = (LL)(nex * log2(n) + 1) * ((l + nex - 1) / nex);
			    if (1<<x==n) 
			    	tmp = (LL)(nex * x) * ((l + nex - 1) / nex);
				if (tmp < ans) {
					ans = tmp; id = nex;
				}
			}

			if (i <= k && i != nex)
		    {
		    	LL tmp = (LL)(i * log2(n) + 1) * ((l + i - 1) / i);
			    if (1<<x==n) 
			    	tmp = (LL)(i * x) * ((l + i - 1) / i);
				if (tmp < ans) {
					ans = tmp; id = i;
				}
			}
		}


		printf("%lld %lld\n", ans, id);	
	}	
}
