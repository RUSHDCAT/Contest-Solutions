#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		sort(a.begin(), a.end());
		creverse(a.begin(), a.end());
		LL ans = 0;
		for (int i = 0; i < a.size(); i ++) {
			ans += max(a[i] - i, 0);
		}
		cout << ans << endl;
	}
}