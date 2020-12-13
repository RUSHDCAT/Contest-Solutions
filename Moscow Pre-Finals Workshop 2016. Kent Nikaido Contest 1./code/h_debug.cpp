#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
/*
const int N = 50 + 10;
int f[N][N][N], g[N][N][N];
int n;


void look(int x) {
	printf("---start-----\n");
	printf("dep = %d, mxdep = %d\n", x, n);
	printf("F\n");
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			printf("%d", f[x][i][j]);
		}
		printf("\n");
	}

	printf("G\n");
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			printf("%d", g[x][i][j]);
		}
		printf("\n");
	}
	printf("----end----\n");
}

int main() {
	n = 10;
	for(int i=1;i<=10;i++){
		int a=rand()%n+1,b=rand()%a+1;
		f[n][a][b] = g[n][a][b] = 1;
	}
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=j;k++){
				f[i][j][k] = f[i+1][j][k] + f[i+1][j+1][k] + f[i+1][j+1][k+1]; f[i][j][k] %= 2;
				g[i][j][k] = g[i+1][j][k] + g[i+1][j+1][k] + g[i+1][j+1][k+1] + 1; g[i][j][k] %= 2; 
			}
		}
	}

	look(n);
	look(n-1);
	look(3);
	look(2);
}
*/
const int N = 52;
int f[N][N][N], g[N][N][N];

int L,n;
int a[N],b[N];
int c(int x, int y){
	LL A=y,B=x-y;
	for(int i=0;i<32;i++){
		//printf("i=%d\n", i);
		if((A>>i&1) && (B>>i&1)) return 2;
	}
	return 1;
} 
void brt() {
	for(int i=L-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			for(int k=1;k<=j;k++){
				f[i][j][k] = f[i+1][j][k] + f[i+1][j+1][k] + f[i+1][j+1][k+1]; 
				g[i][j][k] = g[i+1][j][k] + g[i+1][j+1][k] + g[i+1][j+1][k+1] + 1; g[i][j][k] %= 2; 
			}
		}
	}
}
void look(int x) {
	printf("---start-----\n");
	printf("dep = %d, mxdep = %d\n", x, L);
	printf("F\n");
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			printf("%d ", f[x][i][j]);
		}
		printf("\n");
	}

	printf("G\n");
	for(int i=1;i<=x;i++){
		for(int j=1;j<=i;j++){
			printf("%d", g[x][i][j]);
		}
		printf("\n");
	}
	printf("----end----\n");
}


int solve(int k,int x,int y){
	if(x+y<k)return 0;
	int ins=x+y-k;
	return c(k,ins) * c(k-ins,x-ins); 
}
int main() {
	scanf("%d%d",&L,&n);
	int ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		f[L][a[i]][b[i]] = g[L][a[i]][b[i]] = 1;
		ans += c(L-1, a[i]-1) * c(a[i]-1, b[i]-1);
		//ans += solve(L-1,a[i]-1,b[i]-1);
		//printf("c %d %d => %d\n", L-1,a[i]-1,c(L-1,a[i]-1));
		//printf("c %d %d => %d\n", L-1,b[i]-1,c(L-1,b[i]-1));
		ans %= 2;
	}

	printf("ans = %lld\n", ans);
	if(L%2==0) ans ^= 1;
	printf("%s\n", ans==1?"Iori":"Yayoi");
	brt();
	for(int i=L;i>=1;i--) look(i);

}



