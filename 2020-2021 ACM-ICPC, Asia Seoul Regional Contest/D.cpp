#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1002;
const int inf = 2e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	int n; cin >> n;
	vector<int> a(n),b(n),c(n);
	for (int i = 0; i < n; i ++) cin >> a[i] >> b[i] >> c[i];
	int w, det; 
	cin >> w >> det;
	int s = 0, t = 1;

	vector<int> near[N];
	int d[N][N], d2[N][N];

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) { 
			d[i][j] = abs(a[i] - a[j]) + abs(b[i] - b[j]);
			if (d[i][j] <= w) near[i].push_back(j);
			d2[i][j] = inf;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) if (d[i][j] > w && d[i][j] < 2 * w) {
			for (auto k: near[i]) {
				if (d[k][j] <= w) {
					d2[i][j] = min(d2[i][j], c[k] * (d[j][k] - (w - d[i][k])));
				}
			}
		}
	}
	/*
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			printf("d[%d][%d] = %lld, d2[%d][%d] = %lld\n", i,j,d[i][j],i,j,d2[i][j]);
		}
	}
	*/
	const LL dpinf = 1e12;
	LL down[12][N], up[12][N];
	for (int i = 0; i < 12; i ++) for (int j = 0; j < N; j ++)
		down[i][j] = up[i][j] = dpinf;

	auto upd = [](LL &x, LL y) {
		x = min(x, y);
	};

	down[0][s] = 0;
	for (int i = 0; i <= det; i ++) {
		for (int x = 0; x < n; x ++) {
			//printf("down[%d][%d] = %lld, up[%d][%d] = %lld\n",i,x,down[i][x],i,x,up[i][x] );
			if (down[i][x] < dpinf) {
				upd(up[i+1][x], down[i][x] + w * c[x]);
			}	
			for (int y = 0; y < n; y ++) {
				if (d[x][y] <= w) {
					upd(down[i+1][y], down[i][x] + d[x][y] * c[x]);
					upd(up[i+1][y], up[i][x] + d[x][y] * c[y]);
				}
				if (d2[x][y] != inf) {
					upd(down[i+1][y], up[i][x] + d2[x][y]);
				}
			}
		}
	} 
	LL ans = dpinf;
	for (int i = 0; i <= det; i ++) 
		upd(ans, down[i][t]);
	if (ans == dpinf) ans = -1;

	cout << ans << endl;
}		