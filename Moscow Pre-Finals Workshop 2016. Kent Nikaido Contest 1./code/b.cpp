#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
const LL MOD = 1e9 + 7;
int n, a[N];
LL fac[N],inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

LL pw[N];
int main() {
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}


	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);

	pw[0]=1;
	for(int i=1;i<N;i++){
		pw[i]=pw[i-1]*k%MOD;
	}

	if(l==n) {
		LL sum=0;
		for(int i=1;i<=n;i++){
			int x=gcd(n,i);
			sum += pw[x];
			sum %= MOD;
		}
		printf("%lld\n", sum * mpow(n,MOD-2) % MOD);
	}else{
		LL ans;
		if(l%2==0){
			ans = c(n + k - 1, k - 1);
		} else {
			LL m1 = 1, m2 = 1;
			for (int i=0;i<n;i++){
				m1=m1*(k-i)%MOD;
			}
			for(int i=0;i<n;i++){
				m2=m2*(k+i)%MOD;
			}
		
			LL r1 = ((m2+m1)%MOD+MOD) % MOD;
			LL r2 = ((m2-m1)%MOD+MOD) % MOD;
			r1 = r1*mpow(fac[n],MOD-2)%MOD;
			r2 = r2*mpow(fac[n],MOD-2)%MOD;
			//printf("%lld %lld\n", r1,r2);
			ans=r1;
		}
		printf("%lld\n", ans);
	}
}
