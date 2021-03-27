#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 998244353;
int n, f[N], par[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)par[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		par[find(i)]=find(f[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(find(i)==i)cnt++;
	LL ans=1;
	for(int i=1;i<=cnt;i++) ans=ans*2%MOD;
	ans=(ans-1+MOD)%MOD;
	cout<<ans<<endl;
}