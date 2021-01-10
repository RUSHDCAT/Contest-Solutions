#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL s;
bool ok(LL x) {
	return x >= -1e18 && x <= 1e18;
}
int main() {
	cin >> s;
	LL x = s / 2;
	for (LL a = x - 2; a <= x + 2; a ++) {
		LL b = s - a;
		if (ok(a) && ok(b)) {
			printf("%lld %lld\n", a, b); return 0;
		}
	}
}