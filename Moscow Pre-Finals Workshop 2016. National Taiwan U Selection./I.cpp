#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int m;

LL f[22][10][4][2];
LL b[22];

LL cac(int bit, int las, int state, int lim) {
	if (bit == -1) {
		return 1;
	}
	if(f[bit][las][state][lim] != -1) {
		//printf("[%d,%d,%d,%d] %d\n", bit,las,state,lim, f[bit][las][state][lim]);
		return f[bit][las][state][lim];
	}

	f[bit][las][state][lim] = 0;
	int mx = (lim?b[bit]:9);
	for(int i=0;i <= mx; i++){
		int nexstate;
		if (state == 0) {
			if(i) nexstate = 1;
			else nexstate = 0;
		} else if (state == 1){
			if (i == las) nexstate = 1;
			if (i > las) nexstate = 3;
			if (i < las) nexstate = 2;
		} else if (state == 2) {
			if (i <= las) nexstate = 2;
			else continue;
		} else if (state == 3) {
			if (i >= las) nexstate = 3;
			else continue;
		}

		f[bit][las][state][lim] += cac(bit - 1, i, nexstate, lim && i==mx);
	}
	return f[bit][las][state][lim];
}
LL solve(LL x) {
	memset(b,0,sizeof(b));
	int cur=0;
	while(x) {
		b[cur++]=x%10; x/=10;
	}
	for(int i=0;i<20;i++) for(int j=0;j<10;j++) for(int k=0;k<4;k++) f[i][b[i+1]][k][1] = -1;
	return cac(cur - 1, 0, 0, 1);
}

int main() {
	memset(f,-1,sizeof(f));
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		//printf("test %d\n", i);
		LL l, r; 
		scanf("%lld%lld",&l,&r);
		//l=1LL*rand()*rand(), r=1LL*rand()*rand();
		//if(l>r) swap(l,r);
		printf("%lld\n", solve(r) - solve(l-1));
	}	
}