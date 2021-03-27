#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1000000 + 10;
int n, top, a[N];
LL super_m = -1;

int M = 7;
int ans() {
	LL sum = 0;
	for (int i = top; i > top - n; i --) sum += a[i];
	return sum % M;	
}

LL gcd(LL x, LL y) {
	return y==0?x:gcd(y,x%y);
}
void ask(int x) {
	printf("? %d\n", x); fflush(stdout);
	a[++ top] = x;
	LL sum = 0;
	for (int i = top; i > top - n; i --) sum += a[i];

	int y; 
	scanf("%d", &y);
	//y = ans();
	if (super_m == -1)
		super_m = sum - y;
	else
		super_m = gcd(super_m, sum - y);

	a[++ top] = y;
}

bool chk(int x) {
	LL sum = 0;
	for (int i = top; i > top - (n - 1); i --) sum += a[i];
	int need = ((x - sum) % x + x) % x;
	a[++top] = need;
	printf("? %d\n", need); fflush(stdout);
	int y; 
	scanf("%d", &y);
	//y = ans();
	super_m = gcd(super_m, sum + need - y);
	//y = ans();
	a[++top] = y;
	return y == 0;
} 

int main() {
	scanf("%d", &n); top = n - 1;
	for (int i = 1; i < n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 999; i ++) {
		ask(1000000000 - i);
	} 
	printf("! %lld\n", super_m); fflush(stdout);
	/*
	vector<LL> vec;
	for (LL x = 1; x * x <= super_m; x ++) {
		if (super_m % x == 0) {
			vec.push_back(x);
			if (x * x != super_m)
				vec.push_back(super_m / x);
		}
	}		

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()),vec.end());
	vector<int> v;
	for (auto x: vec){
		if (x >= 2 && x <= 1000000000) v.push_back(x);
	}
	reverse(v.begin(), v.end());
	int ans = v[0];
	vector<bool> ok(v.size(), false);
	for (int i = 0; i < v.size(); i ++) {
		if (super_m % v[i]) continue;
		bool fg = 0;
		for (int j = 0; j < i; j ++) if (v[j] % v[i] == 0 && ok[j] == 0) fg = true;
		if (fg) continue;
		printf("chk %d\n", v[i]);
		if (chk(v[i])) {
			printf("win %d\n", v[i]);
			ans = v[i]; ok[i] = 1;
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
	*/
}