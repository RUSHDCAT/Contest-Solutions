#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL n;

int main() {
	cin >> n;
	// x+....+n <= n*(n+1)/2
	LL l = 0, r = 2e9;
	while (r - l > 1) {
		LL m = (l + r) >> 1;
		if ( m * (m+1) / 2 > n + 1 )
			r = m;
		else
			l = m;
	}	
	LL ans = (n+1)-r + 1;
	cout << ans << endl;
}