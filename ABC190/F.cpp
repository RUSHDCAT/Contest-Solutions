#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int bit[N], n, a[N];
LL pre[N], suf[N];

void add(int x) {
	while (x < N){
		bit[x] ++; x += x&(-x); 
	}
}
int sum(int x) {
	int ans = 0;
	while (x > 0) {
		ans += bit[x]; x -= x & (-x);
	}
	return ans;
}



int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]); ++a[i];
	}

	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i-1] + (i - 1) - sum(a[i]); 
		add(a[i]);
	}
	memset(bit,0,sizeof(bit));

	for (int i = n; i >= 1; i --) {
		suf[i] = suf[i+1] + sum(a[i]); 
		add(a[i]);
	}
	assert(pre[n] == suf[1]);

	LL tot = pre[n];
	for (int i = 0; i < n; i ++) {
		LL x = pre[i], y = suf[i+1];
		LL g = tot - x - y;
		LL f = 1LL * i * (n - i);
		LL tmp = f - g;
		printf("%lld\n", x + y + tmp);
	}
}
