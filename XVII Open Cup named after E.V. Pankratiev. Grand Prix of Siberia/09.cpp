#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, k, a[N];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	LL sum=0;
	multiset<int> s;
	for(int i=1;i<=k;i++){
		sum += a[i]; s.insert(a[i]);
	}
	printf("%lld", sum);
	for(int i=k+1;i<=n;i++){
		int mn = (*s.begin());
		if(a[i] > mn) {
			s.erase(s.find(mn)); sum -= mn;
			s.insert(a[i]); sum += a[i];
		} 
		printf(" %lld", sum);
	}
	printf("\n");
}