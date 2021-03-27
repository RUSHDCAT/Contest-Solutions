#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int N = 1000000+10;
int n, m, T;
vector<int> g[N];
struct SCC {
    int pre[N], low[N], sccno[N], dfs_clock, scc_cnt;
    int in[N], out[N], sz[N];
    stack<int> S;
    void dfs(int u) {
        pre[u] = low[u] = ++dfs_clock;
        S.push(u);
        for (int i = 0; i < g[u].size(); i ++) {
            int v = g[u][i];
            if (! pre[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (!sccno[v]) {
                low[u] = min(low[u], pre[v]);
            }
        }
        if (low[u] == pre[u]) {
            scc_cnt ++;
            for (;;) {
                int x = S.top(); S.pop();
                sccno[x] = scc_cnt;                                                                        
                if (x == u) break;
            }
        }
    }
    void Excalibur(int n) {
        memset(pre, 0, sizeof pre);
        memset(low, 0, sizeof low);
        memset(sccno, 0, sizeof sccno);
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        dfs_clock = scc_cnt = 0;

        for (int i = 1 ;i <= n; i ++)
            if (pre[i] == 0) dfs(i);
        
        for (int i = 1; i <= n; i ++) {
        	sz[sccno[i]] ++;
            for (int j = 0; j < g[i].size(); j ++) {
                if (sccno[i] != sccno[g[i][j]])
                    out[sccno[i]] ++, in[sccno[g[i][j]]] ++;
            }
        }
        int x = 0, y = 0;
        for (int i = 1; i <= scc_cnt; i ++) {
        	if (in[i] == 0) x ++; 
        	if (out[i] == 0) y ++;
        }
        if (scc_cnt == 1) {
        	cout << 0 << endl;
        } else {
        	cout << max(x, y) << endl;
        }
    }
} Saber;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	} 
	if (n == 1 || m == 0) {
		cout << -1 << endl; return 0;
	}
	Saber.Excalibur(n);
}