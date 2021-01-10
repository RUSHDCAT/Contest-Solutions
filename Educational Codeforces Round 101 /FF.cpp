#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k, l[N];
int a[600000 + 10];

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	LL sum=1;
	for(int i=1;i<=n;i++){
		sum+=l[i]-2;
	}
	if(sum<k)return !printf("-1\n");
	sort(l+1,l+1+n); reverse(l+1,l+1+n);
	a[0]=1,a[1]=-1;
	for(int i=0,j=1;i<N-1;i++){
		a[i+1]+=a[i];
		if(a[i] + a[i+1]>=k){
			return !printf("%d\n", i+1);
		}
		while(a[i] > 0 && j<=n) {
			a[i]--;
			int l1 = l[j] / 2;
			int l2 = (l[j]-1) / 2;
			a[i+2]++;a[i+2+l1]--;
			a[i+2]++;a[i+2+l2]--;
			j++;
			sum--;
		}
	}
}