#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;

int main() {
	cin >> n;
	vector<int> facs;
	int x=n;
	for(int i=1;i*i<=x;i++){
		if(x%i==0) {
			facs.push_back(i);
			if(i*i!=x) facs.push_back(x/i);
		}
	}	
	sort(facs.begin(),facs.end());

	map<int, int> dp;
	dp[1] = 1;

	for(auto x: facs) {
		if (x == 1) continue;
		int mn = x / 2 + 1;
		for (auto d: facs) {
			if (x > d && x % d == 0) {
				int cnt = x / d;
				mn = min(mn, dp[d] * (cnt / 2 + 1) );
			}
		}
		dp[x] = mn;
	}
	cout << dp[n] << endl;
}