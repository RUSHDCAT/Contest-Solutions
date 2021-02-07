#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	LL a,b,x,y;
	cin >> a >> b >> x >> y;
	LL ans;
	if (a == b) ans = x;
	else if (b < a) {
		ans = min( x * ((a - b) * 2 - 1), (a-b-1)*y + x );
	} else {
		ans = min( x * ((b - a) * 2 + 1), (b-a)*y + x );
	}
	cout << ans << endl;
}