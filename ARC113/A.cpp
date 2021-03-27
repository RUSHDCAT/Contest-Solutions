#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k; 
	LL ans = 0;
	cin >> k;
	for (int a = 1; a <= k; a ++) {
		for (int b = a; b <= k; b += a) ans += k / b;
	}	
	cout << ans << endl;
}