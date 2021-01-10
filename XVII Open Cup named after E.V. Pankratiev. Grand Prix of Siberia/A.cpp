#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000000 + 10;

int main() {
	int n; 
	scanf("%d", &n);
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	vector<bool> vis(N, 0);
	map<int, int> ans;

	sort(a.begin()+1, a.begin()+1+n);
	for(int i=1;i<=n;i++) vis[a[i]] = 1;
	for(int i=1;i<=n;i++) {
		bool ok=1;
		for(int j=a[i]*2;j<=10000000;j+=a[i])
			if(vis[j]){
				ok=0;
			}
		if(ok) printf("%d ", a[i]);
	}	
}