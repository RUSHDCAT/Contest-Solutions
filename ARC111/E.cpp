#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

/* 
计算 $\sum_{i=0}^{n} [(ai+b)/c]$, a,b,c 为整数，a>=0,c>=1$ 
*/
LL f(LL a, LL b, LL c, LL n) {
    if (b  < 0) return f(a, c - ((-b) % c), c, n) - ((-b) / c + 1) * (n + 1);
    if (a == 0) return (b / c) * ((n + 1));
    if (a >= c || b >= c) {
        return f(a%c, b%c, c, n) + (b/c) * (n+1) + (a/c) * (n* (n+1) / 2);
    }
    LL m = (a * n + b) / c;
    return n * m- f(c, c-b-1, a, m-1);
}

int T,a,b,c,d; 
int check(int lim) {
	int ans=0;
	for(int i=1;i<=lim;i++){
		printf("# %d %d\n", (a+b*i-1)/d, (a+c*i)/d);
		if((a+b*i-1)/d == (a+c*i)/d) ans++;
	}
	return ans;
}
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int mx=(d-1)/(c-b);

		LL sl = f(b,a-1,d,mx);
		LL sr = f(c,a,d,mx);
		LL ans=(mx+1) - (sr-sl);
		if(a/d == (a-1)/d) ans--;
		printf("%lld\n", ans);

		//printf("mx=%d\n", mx);
		//assert(ans == check(mx));
	}
}