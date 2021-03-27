#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
typedef long long LL;
const LL mod = 1e9 + 7;

LL cal(string s) {
	LL ans = 0;
	for (int i = 0; i < s.length(); i ++) {
		ans = ans * 10LL + (LL)(s[i] - '0');
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i ++) cin >> str[i];

	for (int i = 0; i + 1 < n; i ++) {
		if (str[i].length() < str[i+1].length()) continue;
		int j = str[i].length();
		for (int x = 0; x < j; x ++) {
			char low = x == 0 ? '1' : '0';
			if (j == 1) low = '0';

			char c = str[i+1][x];
			str[i+1][x] = low;
			if (cal(str[i+1]) < cal(str[i])) {
				for (auto x: str) cout << x << endl;
				return 0;					
			}
			str[i+1][x] = c;
		}
		
	}

	for (int i = n - 2; i >= 0; i --) {
		if (str[i].length() < str[i+1].length()) continue;
		int j = str[i].length();
		for (int x = 0; x < j; x ++) {
			char high = '9';
			char c = str[i][x];
			str[i][x] = high;
			if (cal(str[i+1]) < cal(str[i])) {
				for (auto x: str) cout << x << endl;
				return 0;					
			}
			str[i][x] = c;
		}		
	}

	cout << "impossible" << endl;
}
