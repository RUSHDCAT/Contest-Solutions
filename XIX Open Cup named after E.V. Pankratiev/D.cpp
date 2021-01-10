#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 200000 + 10;

LL dx[5] = {-1,1,0,0,0};
LL dy[5] = {0,0,-1,1,0};


pair<LL,LL> get() {
	LL x, y; 
	scanf("%lld%lld",&x,&y); 
	for(LL i=0;i<5;i++){
		LL nx = x + dx[i],  ny = y + dy[i];
		if ( (2*nx + ny) % 5 == 0 ) {
			// prLLf("# %d %d\n", nx, ny);
			LL y_ = (2*nx + ny) / 5;
			LL x_ = nx - 2 * y_;
			return make_pair(x_, y_);
		}
	}
}

int main() {
	pair<LL,LL> p1 = get();
	pair<LL,LL> p2 = get();
	printf("%lld\n", abs(p1.first - p2.first) + abs(p1.second - p2.second));
}