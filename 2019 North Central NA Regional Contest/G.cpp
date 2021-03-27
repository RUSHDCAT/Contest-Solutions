#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n;
int a[N], cnt[N];

double sum[N];
double c(int x, int y) {
	return sum[x] - sum[y] - sum[x - y];
}
int main() {
	for (int i = 1; i < N;i ++) {
		sum[i] = sum[i-1] + log10(i);
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), cnt[a[i]] ++;

	double itom	= - log10(365);
	double ans = 0;
	for (int i = 1; i <= n; i ++) 
		ans += a[i] * itom;
	
	for (int i = 0; i < n; i ++)
		ans += log10(365 - i);
	
	int tot = accumulate(a + 1, a + 1 + n, 0);
	for (int i = 1; i <= n; i ++) {
		ans += c(tot, a[i]); tot -= a[i];
	}	
	for (int i = 1; i <= 100; i ++)
		ans -= sum[cnt[i]];
	printf("%.8f\n", ans);
}