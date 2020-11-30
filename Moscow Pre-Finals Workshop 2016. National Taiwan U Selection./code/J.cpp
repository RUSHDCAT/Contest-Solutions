#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N], b[N], p1[N], p2[N], res[N];
int main() { 
	scanf("%d",&n);
	//for(int i=0;i<n;i++) {
	//	a[i]=i, b[i]=i;
	//}
	//random_shuffle(a,a+n);
	//random_shuffle(b,b+n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]); 
		p1[a[i]] = i;
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&b[i]); 
		p2[b[i]] = i;
	}

	memset(res,-1,sizeof(res));
	int c = 0;
	for(int i=2*n-2;i>=0;i--){
		for(int j=min(i,n-1);j>=0 && i-j<n; j--){
			int x=p1[j], y=p2[i-j];
			if(res[ (x+y)%n ] == -1) {
				++c;
				res[(x+y)%n] = i;
			}
			if(c==n) break;
		}
		if(c==n) break;
	}
	for(int i=0;i<n;i++) {
		printf("%d ", res[i]);
	}
}