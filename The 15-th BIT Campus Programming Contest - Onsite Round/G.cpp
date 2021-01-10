#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,m,a[N],b[N];
bool f[N][2];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}

	f[0][0]=0,f[0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i>=a[j] && f[i-a[j]][1] == 0) f[i][0]=1;
			if(i>=b[j] && f[i-b[j]][0] == 0) f[i][1]=1;
		}
	}
	printf("%s\n", f[n][0]?"Long Long nb!":"Mao Mao nb!");
}