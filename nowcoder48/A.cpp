#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	vector<int> a(n+1);
	vector< pair<int,int> > b(n+1);
	b[0] = make_pair(0,0);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = b[i-1];
		if (a[i] >= b[i].first) {
			b[i].second = b[i].first, b[i].first = a[i];
		} else if (a[i] >= b[i].second) {
			b[i].second = a[i];
		}
	}

	cin >> q;
	while (q --) {
		int x; cin >> x;
		cout << b[x].second << endl;
	}
}
