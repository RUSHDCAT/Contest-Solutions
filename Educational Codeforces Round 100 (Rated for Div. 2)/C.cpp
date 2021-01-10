#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T,n;
int t[N],x[N];
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&t[i],&x[i]);
		}
		int inf = -1e9 - 7;
		int pos=0, tar=inf, ans=0;
		t[n + 1] = 2e9;
		for(int i=1;i<=n;i++){
			if(tar == inf) {
				tar=x[i];
			} 
			//printf("i=%d,tar=%d,pos=%d\n", i,tar,pos);

			int need = abs(tar - pos);
			if (t[i+1] - t[i] <= need) {
				int l = pos, r;
				if (pos > tar) {
					pos -= (t[i] - t[i-1]);
					r = pos;
				} else {
					pos += (t[i] - t[i-1]);
					r = pos;
				}
				if(r > l) swap(l,r);
				if(l<=x[i] && x[i]<=r) ans ++;
			} else {
				int l = pos, r = tar;
				if(l>r)swap(l,r);
				pos = tar;
				if(l<=x[i] && x[i]<=r) ans ++;
				tar = inf; 
			}
			//printf("%d\n", ans);
		}
		printf("%d\n", ans);

	}
}