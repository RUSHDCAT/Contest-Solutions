#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
bool ok[N][N];
bool f[N][N];
int count(int x) {
	int ans=0;
	for(int i=0;i<30;i++)if(x>>i&1)ans++;
	return ans;
}
int main() {
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if((j&i)==j && (i+j<N)) f[i][i+j]=1;
		}
	}
	for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){
		if(f[i][k]&&f[k][j]) f[i][j]=1;
	}
	for(int i=1;i<32;i++){
		for(int j=1;j<32;j++){
			printf("%d", f[i][j]);
		}
		printf("\n");
	}*/
	int t; scanf("%d",&t);
	
	while(t--){
		int x,y; scanf("%d%d",&x,&y);
		
	//for(int x=1;x<100;x++)for(int y=x;y<100;y++){
		if(x>y) {
			printf("NO\n"); continue;
		}
		bool ok=true;
		for(int i=1;i<=30;i++){
			int m=(1<<i)-1;
			if(count(m&x)<count(m&y))ok=false;
		}
		printf("%s\n", ok?"YES":"NO");
		//assert(ok == f[x][y]);
	}
}