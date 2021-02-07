#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, r[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &r[i]);
	}
	double sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += 1LL * r[i] * r[i];
	}
	printf("%.10f\n", sum / 2.0);
}