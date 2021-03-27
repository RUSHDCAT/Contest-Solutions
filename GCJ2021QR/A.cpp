#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);		
	int T, cas = 0; cin >> T;
	while (T --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n - 1; i ++) {
			int mn = 1e9, pos = -1;
			for (int j = i; j < n; j ++) {
				if (a[j] < mn) {
					mn = a[j]; pos = j;
				}
			}
			ans += pos - i + 1;
			reverse(a.begin() + i, a.begin() + pos + 1);
		}
		cout << "Case #" << (++cas) << ": " << ans << endl;
	}
}
