#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> x(m);
	for (int i = 0; i < m; i ++) 
		cin >> x[i];

	vector<bool> vis(n+1, false);
	for (int i = 0; i < m; i ++) 
		vis[x[i]] = true;
	vector<int> dog;
	for (int i = 1; i <= n; i ++)
		if (! vis[i]) 
			dog.push_back(i);
	vector<int> add(n + 1, 0);


	add[x[0]] ++;
	bool foul = false;
	for (int i = 0; i + 1 < m; i ++) {
		if (x[i] > x[i+1]) {
			foul = true; add[max(x[i], x[i+1])] ++; break;
		}
		add[max(x[i], x[i+1])] ++;
	}
	if (! foul) {
		add[x[m-1]] ++;
	}

	LL ans = 1;
	int valid = 0, las = 1;
	for (auto x: dog) {
		while (las < x) {
			valid += add[las ++];
		}
		ans = ans * valid % MOD;
		valid ++;
	}
	cout << ans << endl;
}