#include <bits/stdc++.h>
using namespace std;
const int N = 102;

struct Vec {
	int x, y;
	Vec operator - (const Vec & o) const {
		return (Vec){x - o.x, y - o.y};
	}
	double operator ^ (const Vec & o) const {
		return x * o.y - y * o.x;
	}
	double len() {
		return sqrt(x*x + y*y);
	}
};


int main() {
	int n, cas = 0;
	while (cin >> n and n > 0) {
		vector<Vec> p(n);
		for (int i = 0; i < n; i ++) {
			cin >> p[i].x >> p[i].y;
		}
		double ans = 1e9;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) if (i != j) {
				bool ok = 1;
				double dis = 0;
				for (int k = 0; k < n; k ++) if (k != i and k != j) {
					ok &= (((p[j] - p[i]) ^ (p[k] - p[i])) >= 0);
					if (! ok) break;
					dis = max(dis, ((p[j] - p[i]) ^ (p[k] - p[i])) / (p[i] - p[j]).len() );
				}
				if (ok) {
					ans = min(ans, dis);
				}
			}
		}
		printf("Case %d: %.2f\n", ++cas, (ans*100+0.5)/100);
	}
}
