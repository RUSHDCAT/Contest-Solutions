#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
char s[N];
int q, n, l, r;
int nex[N][27], f[N][27];
int go(int x) {
	x = nex[x]['e' - 'a'];
	x = nex[x]['a' - 'a'];
	x = nex[x]['s' - 'a'];
	x = nex[x]['y' - 'a'];
	return x;
}
int main() {
	scanf("%s", s+1);
	scanf("%d", &q);
	n = strlen(s + 1);

	for(int i=0;i<26;i++) nex[n+1][i] = n+1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<26;j++) nex[i][j] = nex[i+1][j];
		nex[i][s[i] - 'a'] = i;
	}

	for(int i=1;i<=n;i++) {
		f[i][0] = go(i);
		//printf("%d %d\n", i, f[i][0]);
	}
	for(int i=0;i<20;i++) f[n+1][i] = n+1;
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			f[j][i] = f[ f[j][i-1] ][i-1];
		}
	}
	while(q--) {
		scanf("%d%d",&l,&r);
		int res = 0;
		for(int i=19;i>=0;i--) {
			if(f[l][i] <= r) {
				//printf("l=%d, i=%d, nex=%d\n", l,i,f[l][i]);
				l = f[l][i]; res |= 1<<i;
			}
		}
		printf("%d\n", res);
	}
}
