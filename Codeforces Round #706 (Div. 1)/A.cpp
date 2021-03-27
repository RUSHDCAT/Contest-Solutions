#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;

int main() {
	scanf("%d", &t);
	while (t --) {
		int n; scanf("%d", &n);
		vector<double> x, y;
		for (int i = 1; i <= 2 * n; i ++) {
			int px, py; scanf("%d%d",&px,&py);
			if (px == 0) y.push_back(abs(py));
			else if (py == 0) x.push_back(abs(px));
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		double ans = 0;
		for (int i = 0; i < n; i ++) {
			ans += sqrt(x[i] * x[i] + y[i] * y[i]);
		}
		printf("%.9f\n", ans);
	}	
}