#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int k;
int main() {
	scanf("%d",&k);
	double ans = 25 + k / 100.0;
	if (ans < 100) ans = 100;
	if (ans > 2000) ans = 2000;
	printf("%.2f\n", ans);
}