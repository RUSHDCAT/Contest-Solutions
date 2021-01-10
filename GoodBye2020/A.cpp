#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, x[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		set<int> s;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s.insert(x[j] - x[i]);
			}
		}
		printf("%d\n", s.size());
	}
}