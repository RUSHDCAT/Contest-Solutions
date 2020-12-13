#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 50 + 10;
int n;
char s[N][N],f[200];

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}	
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]=='o'){
				f[i-j+n]++; tot++;
			}
		}
	}
	tot/=4;

	n=2*n-1;
	for(int i=1;i<=n;i++) f[i]%=2;
	for(int i=1;i<=n;i++){
		if(f[i]%2==1){
			tot--;
			for(int j=i;j<i+4;j++) f[j]^=1;
		}
	}
	printf("%d\n", tot%2==0?0:1);
}