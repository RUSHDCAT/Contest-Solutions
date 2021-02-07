#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int n, p[N];
bool check() {
	vector<bool> vis(N, false);
	int now=0,c=0;
	while(vis[now]==0){
		c++; vis[now]=1; now=p[now];
	}
	return c==n;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	}

	vector<int> ans;
	while(check() == false) {
		int x=rand()%n; ans.push_back(x);
		swap(p[x],p[(x+p[x])%n]);
	}

	int f=0;
	while(p[0]){
		f++;
		ans.push_back(0); int to=p[0]; swap(p[0], p[to]);
	}
	assert(f==n-1);
	printf("%d\n", ans.size());
	for(auto x: ans) printf("%d\n", x);
}