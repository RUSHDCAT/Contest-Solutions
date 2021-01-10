#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t;
int n, m;
int k[N], c[N];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%d",&k[i]);
		}

		
		vector<int> v;
		for(int i=1;i<=m;i++) {
			scanf("%d",&c[i]);
		}

		LL ans=0;
		for(int i=1;i<=n;i++) {
			v.push_back(c[k[i]]); ans+=c[k[i]];
		}

		sort(v.begin(), v.end());
		reverse(v.begin(),v.end());
		LL pos=1;
		for(int i=0;i<v.size();i++) {
			if(pos <= m && c[pos] < v[i]) {
				ans -= (v[i] - c[pos]); pos++;
			} else {
				break;
			}
		}
		printf("%lld\n", ans);
	}	
}