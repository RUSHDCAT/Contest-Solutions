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
        
        set<vector<int> > s;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        vector<vector<int> > d(r, vector<int>(c, 0));
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
                        if (v[nx][ny] == '.' || v[nx][ny] == '^') 
                            d[i][j] ++;
                    }
                }
                if (v[i][j] == '.') s.insert(vector<int>{d[i][j], i, j}); 
            }
        }
        while (not s.empty()) {
            auto vec = *s.begin();
            if (vec[0] <= 1) {
                s.erase(vec);
                if (vec[0] == 0) continue;
            } else break;
            int x = vec[1], y = vec[2];
            for (int k = 0; k < 4; k ++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
                    if (v[nx][ny] == '.') {
                        s.erase(vector<int>{d[nx][ny], nx, ny});
                        d[nx][ny] --;
                        s.insert(vector<int>{d[nx][ny], nx, ny});
                    }
                }
            }
        }
        for (auto vec: s) {
            v[vec[1]][vec[2]] = '^';
        }
        bool ok = 1;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                int deg = 0; 
                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 0 and nx < r and ny >= 0 and ny < c) {
                        if (v[nx][ny] == '^') 
                            deg ++;
                    }
                }
                if (v[i][j] == '^' and deg <= 1) ok = 0;
            }
        }
        if (ok) {
            cout << "Case #" << (++cas) << ": Possible\n";
            for (auto s: v) cout << s << "\n";
            continue;
        } else {
            cout << "Case #" << (++cas) << ": Impossible\n";
        }
    }
}
