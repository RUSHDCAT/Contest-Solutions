#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300 + 10;
int n, t, sc[N];
vector<int> vec[N], g[N];


set<int> s, st[N];


bool taskVis[N];

void dfs(int u) {
	if(taskVis[u]) return;
	taskVis[u] = 1;
	for(auto x: vec[u])
		s.insert(x);

	for(auto v: g[u]) {
		dfs(v);
	}
}

int c = 0;
int ask(int x) {
	printf("%d\n", -(x - c)); c = x; fflush(stdout);
	int y; scanf("%d", &y); return y;
}
int main() {
	scanf("%d%d", &n, &t);

	for(int i=1;i<=n;i++){
		scanf("%d", &sc[i]);
		int x; scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y; scanf("%d",&y);
			vec[i].push_back(y);
		}
	}	
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y; scanf("%d",&y);
			g[i].push_back(y);
		}
	}

	for(int i=1;i<=n;i++){
		s.clear();
		memset(taskVis, 0, sizeof(taskVis));
		dfs(i);
		//printf("i=%d\n", i);
		//for(auto x: s) printf("%d ", x); printf("\n");
		st[i] = s;
	}


	memset(taskVis, 0, sizeof(taskVis));

	int score = 0;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			if(taskVis[j]) continue;
			if(st[j].count(i)) {
				if(ask(i)) {
					for(int k=1;k<=n;k++){
						if(taskVis[k]) continue;

						if(st[k].count(i)) {
							st[k].erase(i); 
							if(st[k].size() == 0) {
								score += sc[k];
								taskVis[k] = 1;
							}
						}
					}
				}else{
					for(int k=1;k<=n;k++){
						if(taskVis[k]) continue;

						if(st[k].count(i)) {
							score += 0;
							taskVis[k] = 1;
						}
					}
				}
				break;
			}
		}
	}
	printf("%d\n",score); fflush(stdout);
	return 0;
}