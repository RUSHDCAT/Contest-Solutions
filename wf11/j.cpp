#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000;
struct Cube {
    int s; string name;
    bool operator < (const Cube & o) const {
        return s < o.s;
    }
};
short f[500][inf+2];
void upd(short& x, short y) {
    if (x == -1) x = y;
    else x = min(x, y);
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);

    vector<Cube> cubes;
    for (int i = 1, s = 0, h = 0;; i ++) {
        s += i * i; h ++;
        if (s > inf) break;
        if (h >= 2) {
            cubes.push_back((Cube){s, to_string(i) + "H"});
        }
    }
    for (int i = 1, s = 0, h = 0;; i += 2) {
        s += i * i; h ++;
        if (s > inf) break;
        if (h >= 2) {
            cubes.push_back((Cube){s, to_string(i) + "L"});
        }
    }
    for (int i = 2, s = 0, h = 0;; i += 2) {
        s += i * i; h ++;
        if (s > inf) break;
        if (h >= 2) {
            cubes.push_back((Cube){s, to_string(i) + "L"});
        }
    }
    sort(cubes.begin(), cubes.end());
    //cout << cubes.size() << "\n";
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < cubes.size(); i ++) {
        for (int j = 0; j <= inf; j ++) {
            if (f[i][j] != -1) {
                upd(f[i+1][j], f[i][j]);
                if (j + cubes[i].s <= inf)
                    upd(f[i+1][j + cubes[i].s], f[i][j] + 1);
            }
        }
    }

    int n, cas = 0;
    while (cin >> n and n) {
        vector<string> ans;
        int las = cubes.size();
        cout << "Case "<< ++cas <<":";
        if (f[las][n] == -1) {
            cout << " impossible\n"; 
            continue;
        }
        for (int i = cubes.size(); i >= 1; i --) {
            if (n >= cubes[i-1].s and f[i][n] == f[i-1][n - cubes[i-1].s] + 1) {
                ans.push_back(cubes[i-1].name); 
                n -= cubes[i-1].s;
            }
        }
        for (auto x: ans) cout << " " << x;
        cout << "\n";
    }
}
