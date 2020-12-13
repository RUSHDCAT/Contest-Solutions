#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,f[N];
int ask(int x) {
	if(f[x])return f[x];
	printf("%d\n", x); fflush(stdout);
	char s[10]; scanf("%s", s);
	if(s[0]=='V') {
		printf("%d\n", x); fflush(stdout); exit(0);
	}
	if(s[0]=='M') return f[x]=1;
	if(s[0]=='F') return f[x]=2;
}

int main() {
	scanf("%d", &n);
	int l=0,r=n-1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(ask(mid)==ask(l) && (mid-l)%2){
			r=mid; continue;
		}
		if(ask(mid)!=ask(l) && (mid-l)%2==0){
			r=mid; continue;
		}
		if(ask(mid)==ask(r) && (r-mid)%2) {
			l=mid; continue;
		}
		if(ask(mid)!=ask(r) && (r-mid)%2==0){
			l=mid; continue;
		}
	}
	ask(l); ask(r);
}
/*
F   M

F   F
  F
*/