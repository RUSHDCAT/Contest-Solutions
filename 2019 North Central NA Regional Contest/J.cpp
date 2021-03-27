#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
char s[N][N];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
	}
	bool ok = 1;
	vector<int> r(n+1, 0), c(n+1, 0);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (s[i][j] == 'W') r[i] ++, c[j] ++;
			if (j + 2 <= n && s[i][j] == s[i][j+1] && s[i][j] == s[i][j+2]) ok = 0;
			if (i + 2 <= n && s[i][j] == s[i+1][j] && s[i][j] == s[i+2][j]) ok = 0;
		}
	}
	for (int i = 1; i <= n; i ++) if (r[i] != n / 2 || c[i] != n/2) ok = 0;
	printf("%d\n", ok?1:0);
}