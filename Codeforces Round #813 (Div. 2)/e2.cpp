#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
const int M = 200000;
vector<pair<int,int> > q[N];

struct Tree {
	vector<ll> sum;
	void init(int n) {
		sum.resize(4 * n + 1);
		for (int i = 1; i <= 4 * n; i ++) sum[i] = 0;
	}
	void update(int l, int r, int rt, int pos, ll x) {
		if (l == r) {
			sum[rt] = x; return; 
		}
		int mid = (l+r)>>1;
		if (pos <= mid) update(l,mid,rt<<1,pos,x);
		else update(mid+1,r,rt<<1|1,pos,x);
		sum[rt] = sum[rt<<1] + sum[rt<<1|1]; 
	}	
	ll query(int l,int r,int rt,int L,int R) {
		if (L<=l&&r<=R) {
			return sum[rt];
		}
		int mid = (l+r)>>1;
		ll ans = 0;
		if (L<=mid) ans += query(l,mid,rt<<1,L,R);
		if (R >mid) ans += query(mid+1,r,rt<<1|1,L,R);
		return ans;
	}
} t1, t2;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i ++) {
		int l, r;
		cin >> l >> r;
		q[l].push_back({i, r});
	}
	t1.init(M);
	t2.init(M);

	vector<ll> f(M + 1, 0);
	for (int i = 1; i <= M; i ++) {
		for (int j = i + i; j <= M; j += i) {
			f[j]++;
		}
	}

	for (int i = 1; i <= M; i ++) {
		t1.update(1,M,1,i,f[i]);
		t2.update(1,M,1,i,f[i]*f[i]);
	}


	vector<ll> sub(t+1, 0);
	for (int i = 1; i <= M; i ++) {
		for (const auto & [id, r]: q[i]) {
			// x * (x - 1) / 2 = x*x / 2 - x/2
			sub[id] = (t2.query(1,M,1,i,r) - t1.query(1,M,1,i,r)) / 2;
		}
		for (int j = i + i; j <= M; j += i) {
			f[j] --;
			t1.update(1,M,1,j,f[j]);
			t2.update(1,M,1,j,f[j]*f[j]);
		}		
	}
	
	for (int i = 1; i <= M; i ++) {
		for (const auto & [id, r]: q[i]) {
			// [i, r]
			if (i * 2 <= r) {
				// [2 * i, r]
				sub[id] += r / 6 - (2 * i - 1) / 6;
			}
			if (i * 5 <= r * 2) {
				int tmp = (5 * i + 1) / 2;
				// [tmp, r]
				sub[id] += r / 15 - (tmp - 1) / 15;
			}
		}		
	}
	
	vector<ll> ans(t+1, 0);
	for (int i = 1; i <= M; i ++) {
		for (const auto & [id, r]: q[i]) {
			ll n = r - i + 1;
			ll tot = n * (n-1) * (n-2) / 6;
			ans[id] = tot - sub[id];
		}
	}
	for (int i = 1; i <= t; i ++) cout << ans[i] << "\n";
}

