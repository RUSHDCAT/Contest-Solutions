#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N];
LL sum[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i]; sum[a[i]] += a[i];
	}
	for (int i = 1; i <= 20000; i ++) {
		sum[i] += sum[i-1];
	}

	for (int i = 1; i <= 20000; i ++) {
		if (sum[i-1] == sum[20000] - sum[i]) {
			cout << i << endl; return 0;
		}
	}
}