#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int ans = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (i < k and a[i] > k) ans ++;
		}
		cout << ans << "\n";
	}

}