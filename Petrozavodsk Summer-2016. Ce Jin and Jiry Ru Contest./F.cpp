#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,C;
double t[N];
int main() {
	scanf("%d%d",&n,&C);
	for(int i=1;i<=n;i++){
		int v,x,d; 
		scanf("%d%d%d",&v,&x,&d);
		double a = sqrt(2 * C);
		t[i] = (v / a) * (v / a);
	}	
	sort(t+1,t+1+n);
	int q; scanf("%d",&q);
	while(q--) {
		int x,k; scanf("%d%d",&x,&k);
		printf("%.5f\n",sqrt(2*C) * sqrt(x + t[k]) );
	}
}
/*
av = c
v * v' = c


F(t) = A sqrt(t) = v
F'(t) = A / 2 / sqrt(t)
*/