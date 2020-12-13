#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int N = 1e5 + 7;
bool vis[N];
int a[N];
vector<int > p[N];

void gao(int x, multiset<int > &s){
	vis[x] = true; s.insert(a[x]);
	for (int v : p[x]) if (!vis[v]){
		gao(v, s);
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++){
		int u, v; scanf("%d%d", &u, &v); ++u; ++v;
		p[u].push_back(v); p[v].push_back(u);
	}
	if(n==1) {
		return !printf("0\n");
	}

	int num = 0;
	long long ans = 0;
	vector<multiset<int> > vec;
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			multiset<int > s;
			gao(i, s);
			//printf("i=%d %d\n", i,s.size());
			if (s.size() == 1){
				ans += a[i]; 
				num ++;
			} else {
				vec.push_back(s);
			}
		}
	}
	if(n==2){
		return !printf("%lld\n", ans);
	}
	priority_queue<pair<int, int >, vector<pair<int, int > >, greater<pair<int, int > > > Q;
	for (int i = 0; i < (int)vec.size(); i++){
		Q.push(make_pair(*vec[i].begin(), i));
	}
	//printf("%d\n", vec.size());
	while (Q.size() >= 2){
		//printf("! %lld\n", ans);
		pair<int, int > now1 = Q.top(); Q.pop();
		pair<int, int > now2 = Q.top(); Q.pop();
		ans += now1.first + now2.first;
		int s = now1.second, t = now2.second;
		vec[s].erase(vec[s].find(now1.first));
		vec[t].erase(vec[t].find(now2.first));
		if (vec[s].size() > vec[t].size()){
			swap(s, t);
		}
		for (auto x : vec[s]) vec[t].insert(x);
		vec[s].clear();
		Q.push(make_pair(*vec[t].begin(), t));
	}
	priority_queue<int, vector<int >, greater<int > > P;
	for (auto v : vec){
		for (auto x : v){
			P.push(x);
		}
	}
	while (P.size() && num){
		ans += P.top(); P.pop(); num--;
	}
	if (num) printf("Impossible");
	else printf("%lld", ans);
	return 0;
}