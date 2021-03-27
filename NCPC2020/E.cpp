#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#define pij pair<pair<int, int >, int >
using namespace std;
const int N = 5e5 + 7;

int x[N], y[N], t[N];
pij p[N];
bool f[N][3], vis[N];

bool cmp(pij a, pij b){
	return a.first > b.first;
}

bool check(pair<int, int > a, pair<int, int > b){
	return a.first <= b.first && a.second <= b.second;
}

int main(){
	int n; 
	scanf("%d", &n);
	vector<int > vec;
	for (int i = 1; i <= n; i++){
		char op[5]; int xt, yt; scanf("%d%d%s", &xt, &yt, op);
		if (op[0] == 'P') t[i] = 0;
		else if (op[0] == 'N') t[i] = 1;
		else t[i] = 2;
		xt *= 2;
		x[i] = yt + xt;
		y[i] = yt - xt;
		vec.push_back(x[i]); vec.push_back(y[i]);
	}		
	sort(vec.begin(), vec.end());
	map<int, int > ma; int cnt = 0;
	for (auto x : vec){
		if (!ma[x]) ma[x] = ++cnt;
	}
	for (int i = 1; i <= n; i++){
		x[i] = ma[x[i]], y[i] = ma[y[i]];
		p[i] = make_pair(make_pair(x[i], y[i]), t[i]);
	}
	sort(p + 1, p + n + 1, cmp);
	int gao[3];
	for (int i = 0; i < 3; i++) gao[i] = -1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 3; j++){
			if (p[i].first.second <= gao[j]){
				f[i][j] = true;
			} else f[i][j] = false;
		}
		gao[p[i].second] = max(gao[p[i].second], p[i].first.second);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (p[i].second == 0){
			if (f[i][0]) {
				vis[i] = true;
				continue;
			}
			if (!f[i][2]){
				vis[i] = true;
				ans++;
			}
		}
		if (p[i].second == 1){
			if (f[i][0]){
				printf("impossible\n");
				return 0;
			}
			vis[i] = true;
		}
		if (p[i].second == 2){
			if (f[i][0] || f[i][1]) {
				vis[i] = true;
			}
		}
	}
	int gou = 1e9;
	for (int i = n; i >= 1; i--){
		int o = p[i].second;
		if (o == 1){
			gou = min(gou, p[i].first.second);
		} else if (o == 2){
			if (p[i].first.second >= gou){
				vis[i] = true;
			}
		}
	}

	vector<pair<int, int > > vec1;
	vector<pair<int, int > > vec2, vec3; 


	for (int i = 1; i <= n; i++) if (!vis[i]){
		if (p[i].second == 0){
			vec1.push_back(p[i].first);
		} else if (p[i].second == 2){
			vec2.push_back(p[i].first);
		}
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	if (vec1.size() == 0){
		printf("%d", ans);
		return 0;
	}
	int l = 0, r = -1;
	
	for (int i = 0; i < (int)vec1.size(); i++){
		while (l < (int)vec2.size() && !check(vec1[i], vec2[l])) l++;
		r = max(r, l - 1);
		while (r + 1 < (int)vec2.size() && check(vec1[i], vec2[r + 1])) r++;
		
		if (l > r){
			ans++;
		} else vec3.push_back(make_pair(l, r));
	}
	sort(vec3.begin(), vec3.end());
	int R = -1;
	for (int i = 0; i < (int)vec3.size(); i++){
		if (vec3[i].first <= R) continue;
		ans++;
		R = vec3[i].second;
	}

	printf("%d", ans);
	return 0;	
}