#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m, k;
string s[N], t[N];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
    	cin >> s[i];
    }

    map<string, int> mp;
    for (int i = 1; i <= m; i ++) {
    	cin >> t[i];
    	for (int j = 0; j < j<<k; j ++) {
    		string str = ""; int mn; cin >> mn;
    		for (int x = 0; x < k; x ++) {
    			if (j >> x & 1) 
    				str += t[i][x];
    			else
    				str += "_";
    		}
    		if (mp.find(str) == mp.end()) mp[str] = mn;
    		else mp[str] = max(mp[str], mn);
    	}
    }
    for (int i = 1; i <= n; i ++) {
    	if (mp.find(s[i]) == mp.end())
    }
}