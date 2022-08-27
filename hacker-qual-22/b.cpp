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
        int r, c;
        cin >> r >> c;
        vector<string> v(r);
        int cnt = 0;
        for (auto& s: v) {
            cin >> s;
            cnt += count(s.begin(), s.end(), '^');
        }
        if (cnt == 0) {
           cout << "Case #" << (++cas) << ": Possible\n"; 
            for (auto s: v) cout << s << "\n";
            continue;
        }
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                if (v[i][j] == '.') v[i][j] = '^';
            }
        }
        if (r > 1 and c > 1) {
            cout << "Case #" << (++cas) << ": Possible\n";
            for (auto s: v) cout << s << "\n";
            continue;
        } else {
            cout << "Case #" << (++cas) << ": Impossible\n";
        }
    }
}
