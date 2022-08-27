#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, p, q, cas = 0;
    while (cin >> n >> m >> p >> q) {
        if (not (n || m || p || q)) break;
        int r = n + m;
        vector<vector<int> > sum(r+1, vector<int>(r+1, 0));
        // cout << n << " " << m << "\n"; 
        while (p --) {
            int x, y; cin >> x >> y;
            sum[x + y][x - y + m] ++;
        } 
        for (int i = 1; i <= r; i ++)
            for (int j = 1; j <= r; j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        
        cout << "Case " << ++cas << ":\n";

        while (q --) {
            int d;
            cin >> d;
            int mx = -1;
            pair<int, int> res;
            for (int j = 1; j <= m; j ++) {
                for (int i = 1; i <= n; i ++) {
                    int x = i + j, y = i - j + m;
                    // cout << i << " " << j << " " << m << "\n";
                    // cout << x << " " << y << "\n";
                    int x_2 = min(x + d, r), y_2 = min(y + d, r);
                    int x_1 = max(x - d, 1), y_1 = max(y - d, 1);
                    int tmp = sum[x_2][y_2] + sum[x_1 - 1][y_1 - 1] - sum[x_2][y_1 - 1] - sum[x_1 - 1][y_2];
                    if (tmp > mx) {
                        mx = tmp;
                        res = {i, j};
                    }
                }
            }
            cout << mx << " (" << res.first << "," << res.second << ")\n";  
        }
    }
}
