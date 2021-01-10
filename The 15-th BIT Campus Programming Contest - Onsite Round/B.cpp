#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL MOD;
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
int f(int i,int r,int p){
	MOD = p;
	int ans=0;
	for(int a=0;a<p;a++){
		for(int b=0;b<p;b++){
			if(mpow(a,r) * mpow(b*(b+1),i) % MOD == mpow(b,i)) {
				ans++;
				if(b>0&&i>0&&a>0)
				printf("%d %d %d\n", b,i,a);
			}
		}
	}
	return ans;
}
int main() {
	int n,r,p; cin>>n>>r>>p;
	int sum=0;
	for(int i=1;i<=n;i++){
		f(i,r,p);
	}
}