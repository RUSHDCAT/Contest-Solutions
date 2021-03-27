#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);	
    int t;
    cin >> t;

    while (t --) {
    	int n, u, v; cin >> n >> u >> v;
    	vector<int> a(n+1);
    	for (int i = 1; i <= n; i ++) cin >> a[i];

    	bool gg = true;
    	for (int i = 1; i <= n; i ++) {
    		if (i >= 2 && abs(a[i-1] - a[i]) > 1) gg = false;
    	}

    	if (! gg) {
    		cout << 0 << endl; 
    		continue;
    	}

    	int ans = 1e9 + 7;
    	int mn = *min_element(a.begin() + 1, a.end());
    	int mx = *max_element(a.begin() + 1, a.end());

    	if (mn != mx) {
    		ans = min(u, v);
    	} else {
    		ans = min(v + v, v + u);
    	}


    	cout << ans << endl;
    }
}