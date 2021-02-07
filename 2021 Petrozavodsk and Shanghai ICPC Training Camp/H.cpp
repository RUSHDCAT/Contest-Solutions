#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
const int B = 1000003;
unordered_set<int> st[N];
int n, m, a[N];

vector<int> v;
int cal() {
	if (*max_element(a+1,a+1+n) <= 0) return 0;
	int ans = 0;

	vector<bool> vis(B, false);
	vis[0] = vis[n+1] = 1;
	for (auto x: v) {	
		if (x - B <= 0) return ans;

		for (auto pos: st[x]) {
			if (vis[pos]) continue;

			int cur = pos;
			int lef = cur, rig = cur;
			//printf("pos = %d\n", pos);
			int sum = x - B - 1, mn = a[pos];
			int len = 1;
			vis[pos] = 1;
			//printf("sum = %d\n", sum);
			while (1) {
				int nlef = lef - 1;
				int nrig = rig + 1; 
				if (vis[nlef] && vis[nrig]) break;

				if (vis[nlef] == 1) {
					mn = min(mn, a[nrig]);
					vis[nrig] = 1; rig = nrig;
				} else if (vis[nrig] == 1) {
					mn = min(mn, a[nlef]);
					vis[nlef] = 1; lef = nlef;
				} else {
					if (a[nlef] > a[nrig]) {
						mn = min(mn, a[nlef]);
						vis[nlef] = 1; len = nlef;
					} else {
						mn = min(mn, a[nrig]); 
						vis[nrig] = 1; rig = nrig;
					}
				}

				++ len;
				//printf("mn = %d, len = %d\n", mn, len);
				ans = max(ans, min(len, sum + mn));
				if (len >= sum + mn) break;
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	v.resize(n);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];  v[i-1] = a[i] + B;
		st[a[i] + B].insert(i);
	}
	int mx = *max_element(a+1,a+1+n);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	reverse(v.begin(), v.end());

	cout << cal() << endl;
	while (m --) {
		int k; cin >> k;
		for (int i = 1; i <= k; i ++) {
			int x, y; cin >> x >> y;
			st[a[x] + B].erase(x);
			st[a[y] + B].erase(y);
			swap(a[x], a[y]);
			st[a[x] + B].insert(x);
			st[a[y] + B].insert(y);			
		}
		cout << cal() << endl;
	}
}