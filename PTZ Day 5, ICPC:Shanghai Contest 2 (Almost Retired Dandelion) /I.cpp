#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<int> c(n), p(n);
    
    for (int i = 0; i < n; i ++) {
    	cin >> c[i];
    	//c[i] = 1; 
    }
    for (int i = 0; i < n; i ++) {
    	cin >> p[i];
    	//p[i] = i;
    }
    
    vector< pair<int,int> > items(n);	
	for (int i = 0; i < n; i ++) items[i] = make_pair(p[i], c[i]);
	sort(items.begin(), items.end(), greater<>());
	
	auto add = [](int x, int y) {
		return min(x + y, inf);
	};
	auto updmin = [](int &x, int y) {
		x = min(x, y);
	};
	vector<int> dp(1, 0);
	for (auto item: items) {
		int p = item.first; int c = item.second;
		vector<int> nex_dp(dp.size() + 1, inf);

		int extra = 0;
		for (int i = 0; i < dp.size(); i ++) {
			updmin(nex_dp[i], dp[i]);
			updmin(nex_dp[i+1], (int)min(dp[i] + c + 1LL * i * p, (LL)inf) );
			//updmin(nex_dp[i+1], add(add(dp[i],c),extra) );
			//extra = add(extra,p);
		}
		while (nex_dp.size() && nex_dp.back() > s) nex_dp.pop_back();
		swap(nex_dp, dp);
	}

	for (int i = dp.size() - 1; i >= 0; i --)
		if (dp[i] <= s) {
			cout << i << endl;
			return 0;
		}
}