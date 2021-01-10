#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
char s[N][N],ss[N][N];
int n,m,l,r,t;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
bool in(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}

int main() {
	scanf("%d%d%d%d%d",&n,&m,&l,&r,&t);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	--t;
	while(t--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int c=0;
				for(int x=0;x<8;x++){
					if(in(i+dx[x],j+dy[x]) && s[i+dx[x]][j+dy[x]]=='*')c++;
				}
				if(c<l||c>r)ss[i][j]='.';else ss[i][j]='*';
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) s[i][j]=ss[i][j];
		//for(int i=1;i<=n;i++)printf("%s\n",s[i]+1);
		//printf("\n");
	}
	for(int i=1;i<=n;i++)printf("%s\n",s[i]+1);
}