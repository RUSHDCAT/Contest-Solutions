#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 2;


string s[N];

int n, m, match[N];
bool us[N];
vector<int> g[N];

bool dfs(int x) {
    for(int i=0;i<g[x].size();i++) {
        if(us[g[x][i]]) continue;
        us[g[x][i]] = 1;
        if(match[g[x][i]] == -1 || dfs(match[g[x][i]]))
        {
            match[g[x][i]] = x; 
            return 1;
        }
    }
    return 0;
}

// 0 - index
int hungary() {
    memset(match, -1, sizeof(match));
    int tot = 0;
    for(int i=0;i<n;i++)
    {
        memset(us, 0, sizeof(us));
        if(dfs(i)) tot ++;
    }
    return tot;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) 
		cin >> s[i];

	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			int diff = 0;
			for (int x = 0; s[i][x]; x ++) if (s[i][x] != s[j][x]) diff ++;
			if (diff == 2) {
				g[i].push_back(j);  g[j].push_back(i);
			}
		}
	}
	int ans = (2 * n - hungary()) / 2;
	printf("%d\n", ans);
}



