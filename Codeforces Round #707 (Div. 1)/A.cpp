#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N];
const int M = 3000000 + 10;
vector<int> v[M];
pair<int,int> f[5000000 + 10];
bool ban[N];
int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	} 	

	for (int i = 1; i < M; i ++) 
		if (v[i].size() >= 4) {
			printf("YES\n");
			for (int x = 0; x < 4; x ++) printf("%d ", v[i][x]);
			return 0;
		}

	vector<int> vec;
	for (int i = 1; i < M; i ++)
		if (v[i].size() >= 2) vec.push_back(i);

	if (vec.size() >= 2) {
		printf("YES\n%d %d %d %d\n", v[vec[0]][0], v[vec[1]][0], v[vec[0]][1], v[vec[1]][1]); return 0;
	}

	if (vec.size() == 1) {
		int x = vec[0];
		bool ok = false;
		for (int i = 1; i <= n; i ++) {
			if( a[i] == x ) {
				if (ok == true) ban[i] = true;
				ok = true;
				continue;
			}
			int need = 2 * x - a[i];
			if (need >= 0 && need < M && v[need].size() > 0) {
				return !printf("YES\n%d %d %d %d\n", i, v[need][0], v[x][0], v[x][1]);
			} 
		}

	}


	for (int i = 1; i <= n; i ++) if(!ban[i]) {
		for (int j = i + 1; j <= n; j ++) if(!ban[j]) {
			if (f[a[i] + a[j]] != make_pair(0, 0)) {
				return !printf("YES\n%d %d %d %d\n", i, j, f[a[i]+a[j]].first, f[a[i]+a[j]].second);
			}
		}
		for (int j = i + 1; j <= n; j ++) {
			if (f[a[i] + a[j]] == make_pair(0, 0)) {
				f[a[i] + a[j]] = make_pair(i, j);
			}
		}
	}
	return !printf("NO\n");
}
