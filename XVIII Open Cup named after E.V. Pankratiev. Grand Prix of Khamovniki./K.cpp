#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N], u[N], v[N];
vector<int> g[N];

int main() {
	int xorsum=0;
	scanf("%d",&n); 
	xorsum ^= n;

	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]); 
	}	
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		xorsum ^= u[i]; xorsum ^= v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}

	vector<int> chicken;
	for(int i=1;i<=n;i++) if(a[i]==1) {
		if(g[i].size()%2 == 1) {
			chicken.push_back(i);
		}
	}

	if (xorsum == 0) {
		printf("%d\n", n);
		for(int i=1;i<n;i++){
			printf("%d %d\n", u[i],v[i]);
		}
		return 0;
	}

	if(chicken.size()==0) return !printf("-1\n");
	if(chicken.size()==1) {
		int to = chicken[0] ^ xorsum;
		if (to == 0) to |= 1<<28;
		if(to > n) {
			printf("%d\n", n);
			for(int i=1;i<n;i++){
				printf("%d %d\n", u[i]==chicken[0]?to:u[i], v[i]==chicken[0]?to:v[i]);
			}
		} else {
			if(a[to] == 1) {
				printf("%d\n", n);
				for(int i=1;i<n;i++){
					printf("%d %d\n", u[i]==chicken[0]?to:(u[i]==to?(u[i]|(1<<28)):u[i]), v[i]==chicken[0]?to:(v[i]==to?(v[i]|(1<<28)):v[i]));
				}
			} else {
				printf("-1\n");
			}
		}
		return 0;
	}

	int to = chicken[0] ^ xorsum, flag = false;
	if (to <= n) to |= 1<<28, flag = true;
	printf("%d\n", n);
	int bu = chicken[1];
	if ((chicken[0] ^ xorsum) == chicken[1]) {
		if (chicken.size()<=2) return !printf("-1\n");
		else {
			bu = chicken[2];
		}
	}
	for (int i=1;i<n;i++){
		if(u[i]==chicken[0]) printf("%d ", to);
		else if(flag && u[i]==bu) {
			printf("%d ", u[i]|(1<<28));
		} else printf("%d ", u[i]);

		if(v[i]==chicken[0]) printf("%d\n", to);
		else if(flag && v[i]==bu) printf("%d\n", v[i]|(1<<28));
		else printf("%d\n", v[i]);
	}
}