#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
LL dp[N+2][2];

int main() {
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t --) {
		cin >> n;

		vector<LL> a(n+1);

		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		dp[0][0] = 0; dp[0][1] = -1e18;
		LL ans = -1e18;
		for (int i = 1; i <= n; i ++) {
			dp[i][1] = a[i]; dp[i][0] = 0;
			for (int j = 0; j < 2; j ++) {
				dp[i][j] = max(dp[i][j], dp[i-1][j^1] + a[i]);
			}
			ans = max(ans, dp[i][1]);
		}
		cout << ans << endl;
	}
}