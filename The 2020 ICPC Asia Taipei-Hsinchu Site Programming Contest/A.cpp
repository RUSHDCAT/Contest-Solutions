#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n; cin >> n;

		bool ok = false;
		for (int x = 1; x * x <= n; x ++) {
			if (n % x == 0) {
				LL a = x, b = n / x;
				if (2 * a >= b) ok = 1;
			}
		}
		cout << (ok?1:0) << endl;
	}
		
}