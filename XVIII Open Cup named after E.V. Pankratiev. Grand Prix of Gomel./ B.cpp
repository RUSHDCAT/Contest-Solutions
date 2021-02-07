#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL inf = (1000000000000000000LL) + 7;

int t; LL n;


LL mul(LL x, LL y) {
	if (x == 0 || y == 0) return 0;
	if (x > inf || y > inf) return inf;
	if (y > 0 && x >= (inf + y - 1) / y) return inf;
	return x * y;
}
LL su(LL x, LL y) {
	LL A = (y - x + 1);
	LL B = (x + y);
	if (A % 2 == 0) A /= 2; else B/=2;
	// printf("[%lld * %lld]\n", A,B);
	return mul(A,B);
}

LL add(LL x, LL y) {
	return min(x + y, inf);
}


LL res = 0;
bool check(LL x) {
	vector<LL> v;
	for (LL i = 0; i <= 32; i ++) {
		v.push_back(x / (1LL<<i) );
	}
	//printf("check %lld\n", x);
	LL sum = 0, freq = 1, cnt = 1, tmp = 0;
	for (int i = 0; i + 1 < 33; i ++) {
		LL lef = v[i+1] + 1, rig = v[i]; 
		//printf("[%lld,%lld]\n", lef,rig);
		LL s = su(lef, rig);  
		//printf("sum = %lld\n", s);
		tmp += cnt * (rig - lef + 1);
		sum = add(sum, mul(freq, s)); 
		freq = freq * 2 + 1; cnt ++;
	}
	if (n - sum > 0) tmp += (n - sum) / (x + 1);
	res = tmp;
	//printf("# %lld\n", tmp);
	return sum <= n;
}

int main() {
	// printf("%lld\n", inf);
	cin >> t;
	while (t --) {
		cin >> n;// check(2e9); return 0;
		//cout << check(2e9) << endl; return 0;
		LL lef = 1, rig = 2e9;
		while (rig - lef > 1) {
			LL mid = (lef + rig) >> 1;
			if (check(mid)) lef = mid; else rig = mid;
		}
		check(lef);
		printf("%lld\n", res);
	}
}