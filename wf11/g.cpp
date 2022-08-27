#include <bits/stdc++.h>
using namespace std;
int n, cas = 0;
int main() {
    while (~ scanf("%d", &n) && n) {
        vector<int> a(n);
        for (int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        
        auto solve1 = [](vector<int> x){
            sort(x.begin(), x.end());
            int s = accumulate(x.begin(), x.end(), 0);
            if (s <= x.back() * 2) 
                return 0.0;
            
            double l = x.back() / 2.0, r = 1e9;
            double area = 0;
            for (int i = 0; i < 100; i ++) {
                double m = (l + r) / 2;
                double sum = 0;
                area = 0;
                for (int j = 0; j < x.size(); j ++) {
                    sum += asin(1.0 * x[j] / 2 / m) * 2;    
                    area += sqrt(m * m - 1.0 * x[j] / 2 * x[j] / 2) * x[j] / 2;
                }
                if (sum > acos(-1) * 2) l = m; else r = m;
                if (i == 99 and abs(sum - 2*acos(-1)) > 1e-6) return 0.0; 
            }
            return area;
        };
        auto solve2 = [](vector<int> x){
            sort(x.begin(), x.end());
            int s = accumulate(x.begin(), x.end(), 0);
            if (s <= x.back() * 2) 
                return 0.0;
            double l = x.back() / 2.0, r = 1e9;
            double area = 0;
            for (int i = 0; i < 100; i ++) {
                double m = (l + r) / 2;
                double sum = 0, las = 0;
                area = 0;
                for (int j = 0; j < (int)x.size(); j ++) {
                    las = asin(1.0 * x[j] / 2 / m) * 2; 
                    sum += asin(1.0 * x[j] / 2 / m) * 2;    
                    int sgn = j == (int)x.size() - 1 ? -1: 1;
                    area += sgn * sqrt(m * m - 1.0 * x[j] / 2 * x[j] / 2) * x[j] / 2;
                }
                if (i == 99 and abs(las * 2 - sum) > 1e-6) return 0.0;
                if (las * 2 > sum) l = m; else r = m;
            }
            return area;
        };  
        auto solve = [&](vector<int> x) {
            return max(solve1(x), solve2(x));
        };
        
        std::function<double(int,int)> dfs = [&](int l, int r) {
            if (r - l <= 1) return 0.0;
            double ans = solve(vector<int>(a.begin() + l, a.begin() + r + 1));
            int pos = max_element(a.begin() + l, a.begin() + r + 1)  - a.begin();
            ans = max(ans, dfs(l, pos - 1) + dfs(pos + 1, r));
            //printf("%d %d %.5f\n", l, r, ans);
            return ans;
        };
        printf("Case %d: %.6f\n", ++cas, dfs(0, n - 1));
    }
}

/*
1. It's opt to make just a single polygon, otherwise we can merge two to increase total area.
2. consider single polygom, have a outside adjacent circle.
*/
