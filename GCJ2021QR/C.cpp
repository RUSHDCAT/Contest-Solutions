#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, cas;
int n, c, a[N], p[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &c);
		int now = 1;
		for (int i = 1; i <= n; i ++) p[i] = i;
		c -= (n - 1);

		if (c < 0) {
			printf("Case #%d: IMPOSSIBLE\n", ++ cas); continue;
		}

		while (now <= n) {
			int pos = now + min(n - now, c);
			c -= min(n - now, c);
			a[p[pos]] = now;
			reverse(p + now, p + 1 + pos);
			++ now; 
		}
		if (c > 0) {
			printf("Case #%d: IMPOSSIBLE\n", ++ cas); continue;	
		}
		printf("Case #%d:", ++ cas); 
		for (int i = 1; i <= n; i ++) printf(" %d", a[i]);
		printf("\n");
	}	
}