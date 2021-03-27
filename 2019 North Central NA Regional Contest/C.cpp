#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
char s[N];

int a[N], b[N], mx, n;

void dfs(int cur) {
	if (cur == -1) {
		//
		//for (int i = n-1; i >= 0; i --) printf("%d", b[i]%10); printf("\n");
		for (int i = n-1; i >= 0; i --) if (b[i]%10 != s[i]-'0') return;
		for (int i = mx; i >= 0; i --) printf("%d", a[i]); printf("\n");
		exit(0);
		return;
	}
	for (int i = 0; i < 10; i ++) {
		a[cur] = i;
		for (int j = mx; j >= cur; j --) b[j + cur] += (cur!=j)?(2 * a[j] * a[cur]):(a[j]*a[cur]);

		if (b[cur + mx] % 10 == (s[cur + mx] - '0')) {
			dfs(cur - 1);
		}
		for (int j = mx; j >= cur; j --) b[j + cur] -= (cur!=j)?(2 * a[j] * a[cur]):(a[j]*a[cur]);
	}
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	if (n % 2 == 0) return !printf("-1\n");
	reverse(s, s + n);
	mx = n / 2;
	dfs(mx);
	return !printf("-1\n");
}