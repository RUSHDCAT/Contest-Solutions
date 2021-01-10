#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL mpow(LL a,LL b,LL mod){
	if(b==0)return 1;
	LL t=mpow(a,b>>1,mod);
	if(b%2==0) return t*t%mod;
	return t*t%mod*a%mod;
}

int main() {
	LL n,m; cin>>n>>m;
	LL d=mpow(10,n,m);
	LL f=mpow(10,n,m*m) - d;
	f=(f%(m*m) + (m*m))%(m*m);
	printf("%lld\n", f/m);
}
/*
(10^n - 10^n % m) / m


10^n = km + b
k%m

k'*m*m + b'

*/