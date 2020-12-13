#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400 + 10;
int t,n;
char s[N][N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%s",s[i]);
		int c[2][4];
		memset(c,0,sizeof(c));
		int d[4]={0}; int tot=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='X'||s[i][j]=='O'){
					d[(i+j)%3]++; tot++;
				}
				if(s[i][j]=='X')c[1][(i+j)%3]++;
				if(s[i][j]=='O')c[0][(i+j)%3]++;
			}
		}
		int lim=tot/3;
		bool find = 0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==j)continue;
				int dt = d[i]-c[0][i] + d[j]-c[1][j];
				if(dt<=lim) {

					for(int x=0;x<n;x++){
						for(int y=0;y<n;y++){
							if(s[x][y]=='.')printf(".");
							else {
								if(s[x][y]=='X'){
									if((x+y)%3 == i)printf("O");else printf("X");
								}
								if(s[x][y]=='O'){
									if((x+y)%3 == j)printf("X");else printf("O");
								}
							}
						}
						printf("\n");
					}
					find = 1;
					break;
				}
			}
			if(find) break;
		}
	}
}