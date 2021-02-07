#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, k, t;
int f[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		for (int i = 0; i < N; i ++) f[i] = 0;
		scanf("%d%d", &n, &k);
		f[1] = k-1; int pos = 1;
		for (int i = 2; i <= n; i ++) {
			if (f[pos] % 2) pos ++; 
			for (int j = i; j >= 1; j --) {
				f[j] = (f[j-1] >> 1)  + ((f[j] + 1) >> 1);
			}
		}
		printf("%d\n", pos - 1);
	}	
}