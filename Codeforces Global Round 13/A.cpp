#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);	
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int c[3] = {0};
	for (int i = 1; i <= n; i ++) c[a[i]] ++;

	while (q --) {
		int op, x; cin >> op >> x;
		if (op == 1) {
			c[a[x]] --;
			a[x] ^= 1;
			c[a[x]] ++;
		} else {
			if (x <= c[1]) cout << 1 << endl;
			else cout << 0 << endl;

		}
	}

}