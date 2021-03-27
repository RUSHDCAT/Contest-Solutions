#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	LL ans = 0;
	{
		vector<int> c(7, 0);
		for (int i = 1; i <= n; i ++) {
			int len = 0, pw = 1;
			int x = a[i];
			while (x) {
				x /= 10; len ++; pw = pw * 10 % 7;
			}
			for (int j = 0; j < 7; j ++) {
				if ((j * pw + a[i]) % 7 == 0) ans += c[j];
			}
			c[a[i] % 7] ++;
		}
	}
	reverse(a.begin() + 1, a.begin() + 1 + n);
	{
		vector<int> c(7, 0);
		for (int i = 1; i <= n; i ++) {
			int len = 0, pw = 1;
			int x = a[i];
			while (x) {
				x /= 10; len ++; pw = pw * 10 % 7;
			}
			for (int j = 0; j < 7; j ++) {
				if ((j * pw + a[i]) % 7 == 0) ans += c[j];
			}
			c[a[i] % 7] ++;
		}
	}	
	cout << ans << endl;
}