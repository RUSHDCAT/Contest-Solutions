#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 70 + 1;
const int M = 10000 + 10;
const int MOD = 1e9 + 7;

LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
LL inv(LL x){
	return mpow(x,MOD-2);
}
int n,m,T;
char s[N][N];
int t[M],v[M];

const int D = 169;
void add(int &x,int y){
	x+=y;
	if(x>=MOD) x-=MOD;
}
void input(){
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&t[i],&v[i]);
	}	
}
void rand_(){
	n=70,m=10000,T=2000000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)s[i][j]='1';
			else s[i][j]='0'+rand()%2;
		}
	}

	int p[2000000+10];
	for(int i=1;i<=T;i++)p[i]=i;
	random_shuffle(p+1,p+1+T);
	sort(p+1,p+1+m);
	for(int i=1;i<=m;i++){
		t[i]=p[i]; v[i]=rand()%n+1;
		//printf("%d %d\n", p[i],rand()%n+1);
	}
}
clock_t S;
void C() {
	clock_t T=clock();
	printf("%.2f\n", 1.0*(T-S)/CLOCKS_PER_SEC);
}


int A[D + 2][N][N];
int cal(int g[], int f[]) {
	unsigned long long ans=0;
	for(int i=1;i<=n;i++){
		ans += (unsigned long long)f[i] * g[i];
		if(!(i&15)) ans %= MOD;
	}
	return ans % MOD;
}
int main() {
	//S=clock();
	//rand_();
	input();
	int deg[N]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='1') deg[i]++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)A[0][i][j]=i==j?1:0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='1'){
				A[1][j][i] = inv(deg[i]);
			}
		}
	}
	//C();
	for(int i=2;i<=D;i++){
		for(int k=1;k<=n;k++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=n;y++){
					add(A[i][x][y],1LL * A[1][x][k] * A[i-1][k][y] % MOD);
				}
			}
		}
	}	
	//C();
	int f[N]={0},ans=0;
	m++; t[m]=T+1; v[m]=-1;
	for(int i=1;i<m;i++){
		add(f[v[i]], 1);
		// tackle [t[i], t[i+1])
		// printf("tackle [%d,%d)\n", t[i],t[i+1]);
		for(int now=t[i];now<=t[i+1];now += D){
			// [now,now+D)
			bool finished = false;
			for(int x=now;x<now+D;x++){
				if(x==t[i+1]) {
					int g[N]={0};
					for(int r=1;r<=n;r++) g[r]=cal(A[x-now][r],f);
					for(int r=1;r<=n;r++) f[r]=g[r];
					finished = true;
					break;
				}
				ans ^= cal(A[x-now][n], f);
			}
			if(finished) break;

			int g[N]={0};
			for(int x=1;x<=n;x++) g[x] = cal(A[D][x], f); 
			for(int x=1;x<=n;x++) f[x] = g[x];
		}
	}
	printf("%d\n", ans);
	//C();

}