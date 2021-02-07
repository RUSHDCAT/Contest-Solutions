#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int k, n, m;
int a[N];
int main() {
	scanf("%d%d%d", &k,&n,&m);
	a[0]=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
		if(a[i]==-1) a[i]=a[i-1];
		if(a[i]<a[i-1]) return !printf("-1\n");
	}
	vector<int> ans;
	int need=n-k;
	if(need < 0) return !printf("-1\n");
	for(int i=1;i<=k;i++){
		int r=m;
		int x=min(need, m-a[i]);
		need -= x;
		for(int j=m;j>m-x;j--) ans.push_back(j);
		ans.push_back(a[i]);
	}
	if(need != 0) printf("-1\n");
	else {
		for(auto x:ans) printf("%d ", x);
	}
}