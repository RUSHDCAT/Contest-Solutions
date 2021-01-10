#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,a,b,c;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		int l=0,r=1e9;
		while(r-l>1){
			int mid=(l+r)>>1;
			int x=mid/7;
			int aa=max(a-x,0),bb=max(b-x,0),cc=max(c-x,0);
			int res=mid-x;
			if(res >= aa+bb+cc) r=mid; else l=mid;
		}

		int x=r/7;
		if(a>=x && b>=x && c>=x && x>=1 && r%7==0) printf("YES\n");
		else printf("NO\n");
	}
}