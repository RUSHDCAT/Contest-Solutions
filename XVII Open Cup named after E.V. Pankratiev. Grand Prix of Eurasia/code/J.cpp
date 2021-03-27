#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, x[N], y[N];
LL cal(int pos) {
	LL sum = 0;
	for (int i = 1; i <= n; i ++) sum += abs(x[i] - (pos + i - 1));
	return sum;
}
LL solve() {
	sort(y + 1, y + 1 + n);
	int mid = (1 + n) >> 1;
	LL sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += abs(y[mid] - y[i]);
		//printf("mid = %d (%d - %d)\n", mid, y[mid], y[i]);
	}
	sort(x + 1, x + 1 + n);
	int lef = -1e9, rig = 1e9;
	while (rig - lef > 6) {
		int midL = (lef + rig) >> 1;
		int midR = (midL + rig) >> 1;
		if (cal(midL) < cal(midR)) {
			rig = midR;
		} else {
			lef = midL;
		}
	}
	LL mn = 1e18;
	for (int i = lef; i <= rig; i ++) {
		//printf("i = %d, cal = %lld\n", i, cal(i));
		mn = min(mn, cal(i));
	}
	//printf("sum = %lld, mn = %lld\n", sum, mn);
	return mn + sum;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
	LL ans = solve();
	swap(x, y);
	ans = min(ans, solve());
	cout << ans << endl;
}
