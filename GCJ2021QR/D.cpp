#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, q;
int ask(int p1, int p2, int p3) {
	printf("%d %d %d\n", p1, p2, p3);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

int mxpos;
bool cmp(int x, int y) {
	int id = ask(x, y, mxpos);
	return y == id;
}

int main() { 
	scanf("%d%d%d",&t,&n,&q);
	while (t --) {
		int mid = ask(1,2,3), rig = -1;
		for (int i = 1; i <= 3; i ++) if (i != mid) {
			rig = i; break;
		}
		for (int i = 4; i <= n; i ++) {
			int x = ask(i, mid, rig);
			if (x == rig) {
				mid = rig; rig = x;
			}
		}
		mxpos = rig;
		vector<int> v;
		for (int i = 1; i <= n; i ++) {
			if (i != mxpos) v.push_back(i);
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
		printf("%d\n", mxpos);
		fflush(stdout);
		int ac = 0;
		scanf("%d", &ac);
	}
}