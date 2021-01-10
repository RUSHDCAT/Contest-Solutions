#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, x[N], dp[N][2];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i <= n; i ++) dp[i][0] = dp[i][1] = 0;
		dp[1][0] = dp[1][1] = 1;
		for (int i = 1; i < n; i ++) {
			for (int j = 0; j < 2; j ++) {
				int now = x[i] + j;

				if (x[i+1] >= now)
					dp[i+1][0] = max(dp[i][j] + (x[i+1]==now?0:1), dp[i+1][0]);

				if (x[i+1] + 1 >= now) 
					dp[i+1][1] = max(dp[i][j] + (x[i+1]+1==now?0:1), dp[i+1][1]);
			}
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
}