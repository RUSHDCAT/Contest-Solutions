#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1000 + 10;

struct Point {
	int x, y, id;
	void read() {
		scanf("%d%d",&x,&y);
	}
	bool operator< (const Point & o) const {
		if (x == o.x) return y < o.y;
		return x < o.x;
	}
} p[N];

int n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		p[i].read(); p[i].id = i;
	}
	sort(p + 1, p + 1 + n);
	printf("%d\n", 2 * n - 1);
	for (int i = 1; i <= n; i ++) {
		printf("%d ", p[i].id);
	}
	for (int i = n - 1; i >= 1; i --) {
		printf("%d ", p[i].id);
	}
}