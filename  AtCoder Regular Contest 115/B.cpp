#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int n, a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}

	vector<int> d1(n - 1), d2(n - 1);
	for (int r = 1; r <= n; r ++) {
		for (int i = 2; i <= n; i ++) {
			if (r == 1)
				d1[i-2] = a[r][i] - a[r][i-1];
			else
				d2[i-2] = a[r][i] - a[r][i-1];
		}
		if (r >= 2 && d1 != d2) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (int c = 1; c <= n; c ++) {
		for (int i = 2; i <= n; i ++) {
			if (c == 1) 
				d1[i-2] = a[i][c] - a[i-1][c];
			else
				d2[i-2] = a[i][c] - a[i-1][c];
		}
		if (c >= 2 && d1 != d2) {
			cout << "No" << endl;
			return 0;
		}
	}

	int ls = 0, lc = 0;
	for (int i = 2; i <= n; i ++) {
		ls = min(ls, a[1][i] - a[1][1]);
		lc = min(lc, a[i][1] - a[1][1]);
	}
	if ((-ls) + (-lc) > a[1][1]) {
		cout << "No" << endl; 
		return 0;
	}

	cout << "Yes" << endl;
	int add = a[1][1] + ls + lc;
	int cur = - lc + add;
	for (int i = 1; i <= n; i ++) {
		cout << cur + a[i][1] - a[1][1] << " ";
	}
	cout << endl;

	cur = - ls;
	for (int i = 1; i <= n; i ++) {
		cout << cur + a[1][i] - a[1][1] << " ";
	}
	cout << endl;
}
