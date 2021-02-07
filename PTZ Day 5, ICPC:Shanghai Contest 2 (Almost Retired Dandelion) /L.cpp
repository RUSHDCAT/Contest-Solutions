#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double inf = 1e9, pi = acos((long double)-1.0), eps = (long double)1e-9;
const int N = 50000000 + 10;
long double f[2][N];
void dp(int a,int b){
	for(int i=0;i<=a;i++){
		int x = i % 2;
		for(int j=0;j<=b;j++){
			f[x][j] = (long double)0;
			if(i) f[x][j] += f[x^1][j];
			if(j) f[x][j] += f[x][j-1];
			f[x][j] /= (long double)2.0;
			if(i==0&&j==0) f[x][j] = (long double)1;
		}
	}
	long double ans = f[a%2][b];
	if(ans<(long double)1e-10){
		printf("Extreme Wealth\n"); return;
	}
	ans = (long double)1.0 / ans;
	if(ans>inf){
		printf("Extreme Wealth\n"); return;
	}
	printf("%.13Lf\n",ans);
}
void calc(ll a,ll b){
	ll n = a + b;
	long double p = (long double)1.0 * a / n;
	long double q = (long double)1.0 - p;
	long double ans = (long double)1.0;
	ans = ans * sqrt((long double)2 * pi * p * q * n);
	long double x = (long double)2 / pow((long double)1 / p, p) / pow((long double)1 / q, q);
	if(n * log(x) > log(inf) + 1){
		printf("Extreme Wealth\n"); return;
	}
	ans = ans * pow(x, n);
	if(ans > inf){
		printf("Extreme Wealth\n"); return;
	}
	printf("%.13Lf\n",ans);
}
void brute(ll a,ll b){
	ll k = min(a,b), n = a + b;
	long double ans = (long double)1; ll rem = n;
	for(int i=0;i<k;i++){
		ans = ans * (k - i) / (n - i);
		while(rem&&ans<(long double)1) ans *= (long double)2, rem--;
	}
	while(rem){
		ans *= (long double)2, rem--;
		if(ans>inf){
			printf("Extreme Wealth\n");
			return;
		}
	}
	printf("%.13Lf\n",ans);
}
int main(){
	ll R,B; 
	while(cin>>R>>B){
		if(R<N&&B<N&&R*B<N) dp(R,B);
		else if(min(R,B)<N) brute(R,B);
		else calc(R,B);
	}
}
/*
0 29
30 0
37 73
100 100
100 50
1000 10000
100000 100
10000 1000
10000000000000 10000000
10000000000000 10000000000000
*/