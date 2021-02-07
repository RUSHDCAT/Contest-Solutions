#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;

int a[N];
LL dp[N], ans = 0;
vector<int> vi, vj;
void solve(int l,int r,int L,int R) {
	int mid = (l+r)>>1;
	if (l > r) return;
	LL mx = 0; int pos = -1;
	for (int i = L; i <= R; i ++) {
		if (vi[i] >= vj[mid]) break;
		LL tmp = 1LL * (a[vi[i]] + a[vj[mid]]) * (vj[mid] - vi[i]);
		if (tmp >= mx) {
			pos = i, mx = tmp;
		}
	}
	if (pos == -1) return;
	ans = max(ans, mx);
	solve(l, mid - 1, L, pos);
	solve(mid + 1, r, pos, R);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	int n; cin >> n;
	for (int i = 0; i <= n; i ++) a[i] = dp[i] = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	int mx = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i] > mx) {
			mx = a[i]; vi.push_back(i);
		}
	}
	mx = 0;
	for (int i = n; i >= 1; i --) {
		if (a[i] > mx) {
			mx = a[i]; vj.push_back(i);
		}
	}
	reverse(vj.begin(), vj.end());
	solve(0, (int)vj.size() - 1, 0, (int)vi.size() - 1);
	cout << ans << endl;
}

