#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 22;
const double eps = 1e-7;
pair<double,double> items[23];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];	
		//a[i] = rand() % 1000000000 + 1;
	}
	
	sort(a.begin(), a.end(), greater<>()); 

	vector<double> dp(1<<n, 0);
	dp[0] = 0;

	auto cal = [](double lb, int now) {
		double sk = 0, sb = 0;
		for (int i = 0; i < now; i ++) {
			double k = items[i].first;
			double b = items[i].second; 
			double nexb = (i == now - 1 ? lb : items[i+1].second);
			
			sk += 1.0 / k;
			sb += - b / k;
			double x = (1 - sb) / sk;
			if (x >= nexb && x <= b) return x;
		}
		return lb;
	};

	for (int mask = 1; mask < 1<<n; mask ++) {

		int now = 0;
		double lb = -1e9;
		for (int i = 0; i < n; i ++) {
			if (mask >> i & 1) {
				double k = dp[mask ^ (1<<i)] - a[i];
				if (k < - eps) {
					items[now ++] = make_pair(k, a[i]);
				} else {
					lb = max(lb, 1.0 * a[i]);
				}
			}
		}
		dp[mask] = cal(lb, now);

		// k[i] * q[i] * p[i] + b[i] * p[i]
		// sum q = 1, 1 >= q[i] >= 0
		// k[i] * q[i] + b[i]
		/* check code
		double l = 0, r = 1e9;
		for (int it = 1; it <= 100; it ++) {
			double mid = (l + r) / 2;
			double need = 0;
			bool ok = true;
			for (int i = 0; i < n; i ++) if (mask >> i & 1) {
				// k[i] * need + b[i] < mid
				if (b[i] <= mid) need = 0;
				else {
					if (k[i] >= 0) {
						ok = false;
					} else {
						need += (b[i] - mid) / (-k[i]);
					}
				}
			}
			if (need > 1) ok = false;
			if (ok) r = mid; else l = mid;
		}
		dp[mask] = r;
		*/

	}
	printf("%.10f\n", dp[(1<<n) - 1]);
}