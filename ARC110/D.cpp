#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000 + 10;
const LL mod = 1e9 + 7;
const LL MOD = 1e9 + 7;
LL inv[N*N+N];
LL c(LL x, LL y) {
	LL ans=1;
	for(LL i=x;i>x-y;i--) ans=ans*i%mod;
	for(int i=1;i<=y;i++) ans=ans*inv[i]%mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	inv[1]=1;
	for(int i=2;i<N*N+N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}	
	int n,m; cin>>n>>m;
	int sum=0;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];sum+=a[i];
	}
	cout<<c(m+n,sum+n)<<endl;
}


