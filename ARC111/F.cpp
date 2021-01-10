#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 998244353;

LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if(x%2==0) return t*t%MOD;
	return t*t%MOD * a % MOD;
}
void look(LL x) {
	for(LL i=0;i<=200;i++){
		for(int j=1;j<=200;j++){
			if(i*mpow(j,MOD-2)%MOD == x) {
				printf("%d/%d", i,j); return;
			}
		}
	}
}


LL n, m, q;
int tp[N], l[N], r[N], x[N], C;
int solve() {
	int a[N]={0}, ans=0;;
	//printf("! %d\n",++C);
	for(int i=1;i<=q;i++){
		//printf("%d %d %d %d\n", tp[i],l[i],r[i],x[i]);
		if(tp[i]==0) {
			for(int j=l[i];j<=r[i];j++) a[j]=max(a[j], x[i]);
		}
		if(tp[i]==1) {
			for(int j=l[i];j<=r[i];j++) a[j]=min(a[j], x[i]);
		}
		if(tp[i]==2) {
			int s=0;
			for(int j=l[i];j<=r[i];j++) s+=a[j];
			ans+=s;	
		}
	}
	return ans;
}
int res=0;
void dfs(int now) {
	if (now == q + 1) {
		res+=solve(); return;
	}
	for(int i=0;i<=2;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				for(int x_=0;x_<((i<=1)?m:1);x_++){
					tp[now]=i, l[now]=j, r[now]=k, x[now]=x_;
					dfs(now+1);
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> q;
	LL tot = n * (n + 1) / 2 % MOD;
	LL inv = mpow(tot, MOD - 2);
	if (m == 1 || q == 1) {
		return !printf("0\n");
	}
	LL ans = 0;
	for (LL i = 1; i <= n; i ++) {
		LL pro = i * (n - i + 1) % MOD * inv % MOD;
		LL p_move = m * mpow(2*m+1, MOD-2) % MOD * pro % MOD;
		LL p_n_move = (1 - p_move + MOD) % MOD;
		LL p_sum = mpow(2 * m + 1, MOD - 2);

		LL tmp = 0;
		
		LL f[2]; 
		f[0] = 0;
		f[1] = m * (m-1) / 2 % MOD * mpow(m, MOD - 2) % MOD; 

		LL p[2];
		//p[0] = 0; for (int x = 1; x <= q; x ++) p[0] = (p[0] + mpow(p_n_move, x-1)) % MOD;
		p[0] = (mpow(p_n_move, q) - 1 + MOD) % MOD * mpow(p_n_move-1,MOD-2) % MOD;
		p[1] = (q - p[0] + MOD) % MOD;
		
		/*
		printf("pro: "); look(pro); printf("\n");
		printf("p_move: "); look(p_move); printf("\n");
		printf("p_n_move: "); look(p_n_move); printf("\n");

		printf("i = %d\n", i);
		for (int x = 0; x < 2; x ++) {
			look(f[x]); printf(" : "); look(p[x]); printf("\n");
		}
*/
		tmp = f[1] * p[1] % MOD;
		//printf("#%lld\n", tmp);

		tmp = tmp * pro % MOD * p_sum % MOD;
		ans = (ans + tmp) % MOD;
	}
	LL M = n*(n+1)/2%MOD * (2*m+1) % MOD; M = mpow(M,q); ans = ans * M % MOD;
	cout << ans << endl;
	//dfs(1);
	//cout<<res<<endl;
}
