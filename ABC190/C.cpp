#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vector<int> a(m), b(m);
	for (int i = 0; i < m; i ++) {
		cin >> a[i] >> b[i];
	}
	int k; cin >> k;

	vector<int> x(k), y(k);
	for (int i = 0; i < k; i ++) {
		cin >> x[i] >> y[i];
	}


	int res = 0;
	for (int mask = 0; mask < 1<<k; mask ++) {
		vector<int> c(102, 0);
		for (int i = 0; i < k; i ++) {
			if (mask >> i & 1) c[x[i]] ++; else c[y[i]] ++;
		}
		int ans = 0;
		for (int i = 0; i < m; i ++) {
			if (c[a[i]] > 0 && c[b[i]] > 0) ans ++;
		}
		res = max(res, ans);
	}

	cout << res << endl;
}