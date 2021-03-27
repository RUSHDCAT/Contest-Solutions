#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9;

int dp[N][2], x, y;
char s[N];

int main() {		
	int T, cas = 0;
	scanf("%d", &T);
	while (T --) {

		scanf("%d%d%s", &x, &y, s+1);
		int n = strlen(s + 1);

		for (int i = 0; i <= n; i ++) dp[i][0] = dp[i][1] = inf;
		
		if (s[1] != 'J') dp[1][0] = 0;
		if (s[1] != 'C') dp[1][1] = 0;

		for (int i = 2; i <= n; i ++) {
			if (s[i] != 'J') {
				dp[i][0] = min({dp[i][0], dp[i-1][1] + y, dp[i-1][0]});
			}
			if (s[i] != 'C') {
				dp[i][1] = min({dp[i][1], dp[i-1][0] + x, dp[i-1][1]});
			}
		}		
		int ans = min(dp[n][0], dp[n][1]);
		printf("Case #%d: %d\n", ++cas, ans);
	}
}