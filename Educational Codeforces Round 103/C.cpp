#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t --) {
    	int n; cin >> n;
    	vector<int> a(n),b(n),c(n);
    	for (int i = 0; i < n; i ++) cin >> c[i];
    	for (int i = 0; i < n; i ++) cin >> a[i];
    	for (int i = 0; i < n; i ++) cin >> b[i];
    	LL ans = 0;
    	for (int i = 0, j = 0; i + 1 < n; i = j) {
    		//printf("i = %d, j = %d\n", i, j);
    		LL tmp = abs(a[i + 1] - b[i + 1]);
    		//printf("# %d\n", tmp);
    		while (i == j || (j + 1 < n && a[j + 1] != b[j + 1])) {
    			j ++; 
    			tmp += 2; 
    			if (j - i > 1) tmp += c[j - 1] - 1 - abs(a[j] - b[j]);
    			//printf("## %d\n", tmp);
    		}
    		tmp += c[j] - 1;
    		//printf("j = %d\n", j);
    		ans = max(ans, tmp);
    		//printf("tmp = %lld\n", tmp);
    		for (int x = i; x + 2 <= j; x ++) {
    			tmp -= abs(a[x+1] - b[x+1]);
    			tmp -= 2;
    			tmp -= (c[x+1] - abs(a[x+2] - b[x+2]));
    			tmp += abs(a[x+2] - b[x+2]);
    			ans = max(ans, tmp);
    		}
    	}
    	cout << ans << endl;
    }
}
