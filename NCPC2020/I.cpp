#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000000 + 10;

double fac[N];
double c(int x, int y) {
	return fac[x] - fac[y] - fac[x - y];
}
double cal(int n, int k, int r) {

}
void iter() {

}

int main() {
	fac[0] = 0;
	for (int i = 1; i < N; i ++) fac[i] += log2(i);

	
}