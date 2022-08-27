#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;
int cas = 0;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i ++) {
            int x; cin >> x; mp[x] ++;
        }
        bool ok = 1;
        for (auto [x, c]: mp) {
            if (c >= 3) {
                ok = 0;
            }
        }
        cout << "Case #" << (++cas) << ": ";
        cout << ((ok && 2*k >= n) ? "YES" : "NO") << "\n";
    }
}
