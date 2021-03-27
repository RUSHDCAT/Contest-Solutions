#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

LL mpow(LL a, LL x, LL MOD) {
	if (x == 0) return 1 % MOD;
	LL t = mpow(a, x>>1, MOD);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL a, b, c;
	cin >> a >> b >> c;

	if (b == 1 || (b == 2 && c == 1)) {
		cout << mpow(a, mpow(b,c,10LL), 10LL) << endl; 
		return 0;
	}

	cout << mpow(a, mpow(b,c,4)+4, 10) << endl;

}