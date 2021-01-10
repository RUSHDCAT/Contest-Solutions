#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	int k, n;
	scanf("%d%d",&k,&n);
	vector<int> a(k+1);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}

	int cnt=0,cur=n,las=-1;
	for(int i=1;i<=k;i++){
		if(a[i] <= cur) {
			cur -= a[i];
			if (cur == 0) {
				las = i;
				cur += n; cnt ++;
			}
		} else {
			continue;
		}
	}
	if(las == k) cur = 0;
	printf("%d\n%d\n", cnt,cur);
}