#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s, d; cin >> n >> s >> d;
	int ok = 0;
	for (int i = 1; i <= n; i ++) {
		int x, y; cin >> x >> y;
		if (x < s && y > d) ok = 1;
	}
	cout << (ok?"Yes":"No") << endl;
}