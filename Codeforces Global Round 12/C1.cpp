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
			int c[4]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='X')c[(i+j)%3]++;
			}
		}
		int mn=-1,val=1e9;
		for(int i=0;i<3;i++){
			if(c[i]<val){
				val=c[i]; mn=i;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='.') printf(".");
				else if(s[i][j]=='X'){
					if((i+j)%3==mn) printf("O");else printf("X");
				}
			}
			printf("\n");
		}
	}
}