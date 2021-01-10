#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int n,m,d;
int id(int r,int c){
	return (r-1)*m + c;
}
int par[N*N],sz[N*N];
bool in(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
char s[N][N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	if(find(x)!=find(y)){
		sz[find(y)]+=sz[find(x)];
		par[find(x)]=find(y);
	}
}
bool ban[N*N];
int main() {
	for(int i=0;i<N*N;i++){
		par[i]=i,sz[i]=1;
	}
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int x=0;x<4;x++){
				int ni=i+dx[x];
				int nj=j+dy[x];
				if(in(ni,nj) && s[i][j]=='.' && s[ni][nj]=='.')
					unite(id(i,j),id(ni,nj));
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(i==1||i==n||j==1||j==m){
			if(s[i][j]=='.')ban[find(id(i,j))]=1;
		}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'&&ban[find(id(i,j))]==0&&sz[find(id(i,j))]<d) s[i][j]='#';
		}
		printf("%s\n",s[i]+1);
	}
}