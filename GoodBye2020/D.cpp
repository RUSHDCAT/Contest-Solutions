#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n; LL w[N];
vector<int> g[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);

		for(int i=1;i<=n;i++){
			scanf("%lld", &w[i]);
		}
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++) {
			int u,v; scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<LL> ans;
		LL sum=0;
		for(int i=1;i<=n;i++) {
			sum += 1LL * w[i] * g[i].size();
		}
		ans.push_back(sum);

		vector<int> d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=(int)g[i].size()-1;j++){
				d.push_back(w[i]);
			}
		}
		sort(d.begin(),d.end());
		for(auto x: d) {
			sum -= x; ans.push_back(sum);
		}
		reverse(ans.begin(),ans.end());
		for(auto x: ans) printf("%lld ", x);
		printf("\n");
	}
}