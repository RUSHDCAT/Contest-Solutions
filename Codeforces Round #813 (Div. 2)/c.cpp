#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		map<int,int> mp, mp2;

		for (int i = n - 1; i >= 0; i --) mp[a[i]] = i;

		for (int i = 0; i < n; i ++) mp2[a[i]] ++;
		int ans = mp2.size(), tmp = mp2.size(), mn = n;
		for (int i = n - 1; i >= 0; i --) {
			if (i < n - 1 and a[i] > a[i+1]) break;
			mp2[a[i]] --;
			if (mp2[a[i]] == 0) tmp --;
			mn = min(mn, mp[a[i]]);
			if (mn >= i) {
				ans = tmp;
			}
		}
		cout << ans << "\n";
	}

}