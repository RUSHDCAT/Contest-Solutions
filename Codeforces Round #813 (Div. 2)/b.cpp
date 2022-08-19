#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y) {
	return x * y / gcd(x, y);
} 
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		/*
		vector<int> a;
		for (int i = 1; i <= n; i ++) a.push_back(i);
		int mx = 0;
		do {
			int cur = 0;
			for (int i = 0; i  <n; i ++) {
				cur += lcm(i+1, a[i]);
			}
			if (cur > mx) {
				mx = max(mx, cur);
				for (int i = 0; i < n; i ++) {
					printf("%d ", a[i]);
				}
				printf("\n");
			}
		} while (next_permutation(a.begin(), a.end()));
		*/
		if (n % 2== 1) {
			cout << 1 << " ";
			for (int i = 2; i <= n; i += 2) {
				cout << i + 1 << " " << i << " ";
			}
			cout << "\n";
		} else {
			for (int i = 1; i <= n; i += 2) {
				cout << i + 1 << " " << i << " ";				
			}
			cout << "\n";
		}
	}

}