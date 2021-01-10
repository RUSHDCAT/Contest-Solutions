
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;
const int N = 1e3 + 7;
 
char s[N][N];
int ans[N][N], col[N * N];
bool flag[N * N], vis[N * N], gou[N * N];
vector<int> p[N][N], g[N * N];
 
vector<int > tmp[2];
void gao(int x, int y){
	tmp[y].push_back(x); col[x] = y;
	vis[x] = true;
	for (auto v : g[x]) if (!vis[v]){
		gao(v, y ^ 1);
	}
}

int n, m;
bool in(int x, int y) {
	return x>=1 && x<=n && y>=1 && y<=m;
}
 
int main(){
	scanf("%d%d", &n, &m);
 
	for (int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
	}
 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] != '.'){
				int t = (i - 1) * m + j;
				if (s[i][j] == s[i][j - 1]){
					if (s[i][j] - 'A' >= 0 && s[i][j] - 'A' < 26){
						//printf("%d ^*^^*^\n", t);
						if (s[i + 1][j] == '.' && s[i + 1][j - 1] == '.'){
						//	printf("%d ^*^^*^*\n", t);
							p[i + 1][j].push_back(t);
							p[i + 1][j - 1].push_back(t);
							gou[t] = true;
						}
 
					} else {
						if (s[i - 1][j] == '.' && s[i - 1][j - 1] == '.'){
							p[i - 1][j].push_back(t);
							p[i - 1][j - 1].push_back(t);
							gou[t] = true;
						}						
					}
				}
				if (s[i][j] == s[i - 1][j]){
					if (s[i][j] - 'A' >= 0 && s[i][j] - 'A' < 26){
						
						if (s[i][j + 1] == '.' && s[i - 1][j + 1] == '.'){
							p[i][j + 1].push_back(t);
							p[i - 1][j + 1].push_back(t);
							gou[t] = true;
						}
 
					} else {
						
						if (s[i][j - 1] == '.' && s[i - 1][j - 1] == '.'){
							p[i][j - 1].push_back(t);
							p[i - 1][j - 1].push_back(t);
							gou[t] = true;
						}
 
					}	
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == '.'){
				for (auto u : p[i][j]) if (gou[u]){
					for (auto v : p[i][j]) if (gou[v]){
						if (u != v){
							//printf("%d %daaa\n", u, v);
							g[u].push_back(v);
							g[v].push_back(u);
						}
					}
				}
			}
		}
	}	
 
	int mao = 0;
	for (int i = 1; i <= n * m; i++){
		if (!vis[i] && gou[i]){
			//printf("%d ^*^^*^\n", i);
			tmp[0].clear(); tmp[1].clear();
			gao(i, 0);
			if (tmp[0].size() < tmp[1].size()){
				for (auto x : tmp[1]){
					mao ++; 
					flag[x] = true;
					//printf("%d ^*^\n", x);
				}
			} else {
				for (auto x : tmp[0]){
					mao ++;
					flag[x] = true; 
					//printf("%d ^*^\n", x);
				}
			}
		}
	}
	printf("%d\n", mao);
 
	for (int i = 1; i <= n * m; i++){
		if (gou[i]){
			for (auto x : g[i]){
				if (gou[x]){
					assert(col[i] != col[x]);
				}
			}
		}
	}
 
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int o = (i - 1) * m + j;
			if (s[i][j] != '.'){
				bool tong[10] = {false};
				for (int i1 = i - 2; i1 <= i + 2; i1++){
					for (int j1 = j - 2; j1 <= j + 2; j1++){
						if (i1 < 0 || j1 < 0) continue;
						if (i1 == i - 2 && j1 == j - 2) continue;
						if (ans[i1][j1] >= 0 && ans[i1][j1] <= 9){
							tong[ans[i1][j1]] = true;
						}
					}
				}
 
				int t = -1;
				for (int k = 0; k < 10; k++) if (!tong[k]) {t = k; break;}
				assert(t != -1);
				if (s[i][j] == s[i - 1][j]){
					if (s[i][j] >= 'A' && s[i][j] <= 'Z'){
						ans[i][j] = ans[i - 1][j] = t;
						if (flag[o]) ans[i][j + 1] = ans[i - 1][j + 1] = t;
					} else {
						ans[i][j] = ans[i - 1][j] = t;
						if (flag[o]) ans[i][j - 1] = ans[i - 1][j - 1] = t; 
					}
				} 
				if (s[i][j] == s[i][j - 1]){
					if (s[i][j] >= 'A' && s[i][j] <= 'Z'){
						ans[i][j] = ans[i][j - 1] = t;
						if (flag[o]) ans[i + 1][j] = ans[i + 1][j - 1] = t;
					} else {
						ans[i][j] = ans[i][j - 1] = t;
						if (flag[o]) ans[i - 1][j] = ans[i - 1][j - 1] = t;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (ans[i][j] == -1) printf(".");
			else printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}