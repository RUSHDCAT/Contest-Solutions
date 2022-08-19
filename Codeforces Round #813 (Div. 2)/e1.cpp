#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int l, r;
		cin >> l >> r;

		vector<vector<int> > g(r+1), f(r+1);

		for (int i = 1; i <= r; i ++) {
			for (int j = i + i; j <= r; j += i) {
				if (i >= l) {
					f[j].push_back(i);
					g[j].push_back(i);
				}
				if (j > 2*i and 2*i>=l and (j%(2*i))) {
					g[j].push_back(2*i);
				}
			}
		}
		ll n = r - l + 1;
		ll ans = 1ll * n * (n-1) * (n-2) / 6;
		//cout << ans << "\n";
		ll res = 0;
		for (int i = l; i <= r; i ++) {
			res += 1ll * f[i].size() * (f[i].size() - 1) / 2;
		}
		//cout << res << "\n";
		auto solve = [](vector<int> v, int x){
			sort(v.begin(), v.end());
			ll ans = 0;
			for (int i = 0, j = v.size() - 1; i < v.size(); i ++) {
				while (j > i and v[i] + v[j] > x) j --;
				// [j+1, v.size()-1]
				if (i < j)
					ans += (int)v.size() - j - 1;
				else
					ans += (int)v.size() - i - 1;
			}
			return ans;
		};
		for (int i = l; i <= r; i ++) {
			//res -= solve(f[i], i);
			//res += solve(g[i], i);
		}
		ans -= res;
		cout << ans << "\n";
	}

}
/*
i + j + k < 3k
lcm(i,j,k) < i + j + k < 3k

2k < i + j + k

*/