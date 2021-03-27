#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
const LL MOD = 998244353;

int a[N];
int stk[N], L[N], top = 0;

LL dp[N][2], s[N][2];
void add(LL &x, LL y) {
	(x += y) %= MOD;
}
LL query(int l, int r, int pos, int flag) {
	while ((r % 2 + 2) % 2 != pos) -- r;
	while ((l % 2 + 2) % 2 != pos) ++ l;
	if (l > r) return 0;
	return (r>=0?s[r][flag]:0) - (l-2>=0?s[l-2][flag]:0);
}
int main() {
	ios::sync_with_stdio(false);	
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		while (top > 0 & a[stk[top]] >= a[i]) -- top;
		L[i] = stk[top];
		stk[++top] = i;
		//printf("pre %d = %d\n", i, L[i]);
	}
	dp[0][0] = 1; s[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		int pre = L[i];
		// j->i
		// j>=pre
		int l=pre, r=i-1;
		add(dp[i][0], a[i] * query(l,r,i%2, 1));
		add(dp[i][0], a[i] * query(l,r,(i%2)^1,0));
		add(dp[i][1], a[i] * query(l,r,i%2,0));
		add(dp[i][1], a[i] * query(l,r,(i%2)^1,1));

		// j <pre
		if(pre>=1) {
			bool flag = ((i - pre) % 2);
			add(dp[i][0], dp[pre][0 ^ flag]);
			add(dp[i][1], dp[pre][1 ^ flag]);
		}
		//printf("i=%d,%lld/%lld\n", i,dp[i][0],dp[i][1]);
		s[i][0] = ((i-2>=0?s[i-2][0]:0L) + dp[i][0]) % MOD;
		s[i][1] = ((i-2>=0?s[i-2][1]:0L) + dp[i][1]) % MOD;
	}
	cout << ((dp[n][0] - dp[n][1]) % MOD + MOD) % MOD << endl;
}