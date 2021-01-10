#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
vector<int> g[N], bcc[N];
int par[N], sz[N];

int find(int x) {
	return par[x] == x ? x: par[x]=find(par[x]);
}
set< pair<int, int> > bridge;

struct BCC {
    int pre[N], low[N], iscut[N], bccno[N], par[N], sz[N];
    int dfs_clock, bcc_cnt;
    stack< pair<int,int> > S;
	set<int> gg[N];

	int sum[N], fat[N], cnt[N];

    int dfs(int u, int p) 
    {
        int lowu = pre[u] = ++ dfs_clock;
        int child = 0;
        for (int i = 0; i < g[u].size(); i ++) 
        {
            int v = g[u][i]; 
            pair<int, int> edge = make_pair(u, v);
            if (! pre[v])
            {   
                S.push(edge);
                child ++;
                int lowv = dfs(v, u);
                lowu = min(lowu, lowv);
                if (lowv > pre[u]) { 
                	bridge.insert(make_pair(u, v));
                	bridge.insert(make_pair(v, u));
                    bcc[++ bcc_cnt].clear();
                    iscut[u] = 1;
                    for (;;) {
                        pair<int, int> x = S.top(); S.pop();
                        if (bccno[x.first] != bcc_cnt) {
                            bccno[x.first] = bcc_cnt;
                            bcc[bcc_cnt].push_back(x.first);
                        }
                        if (bccno[x.second] != bcc_cnt) {
                            bccno[x.second] = bcc_cnt;
                            bcc[bcc_cnt].push_back(x.second);
                        }
                        if (x.first == u && x.second == v)
                            break;
                    }
                } 
            } else 
            if (pre[v] < pre[u] && v != p) {
                S.push(edge);
                lowu = min(lowu, pre[v]);
            }
        }
        if (p == -1 && child <= 1) iscut[u] = 0;
        return lowu;
    }

    bool vis[N];

    void getsz(int u, int p) {
    	sum[u] = cnt[u] + 1; vis[u] = 1; fat[u] = p;
    	for (auto v: gg[u]) {
    		if (v == p) continue;
    		getsz(v, u);
    		sum[u] += sum[v];
    	}
    }
    int find(int x) {
    	return bccno[x] == x?x: bccno[x] = find(bccno[x]);
    }
    void Excalibur(int n) 
    {
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        memset(vis, 0, sizeof(vis));
        dfs_clock = bcc_cnt = 0;
        
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        }   

        for (auto p: bridge) {
        	// printf("# %d %d\n", p.first, p.second);
        }
        for(int i=1;i<=n;i++) bccno[i]=i;
        for (int i = 1; i <= n; i ++) {
        	for (auto j: g[i]) {
        		if (!bridge.count(make_pair(i, j))) {
        			bccno[find(i)] = find(j);
        		}
        	}
        }
        for(int i=1;i<=n;i++) bccno[i]=find(i);

        for (int i = 1; i <= n; i ++) {
        	for (auto j: g[i]) {
        		if (bccno[i] != bccno[j]) {
        			gg[ bccno[i] ].insert( bccno[j] );
        		}
        	}
        }
        for (int i = 1; i <= n; i ++) {
        	sum[i] = 0; cnt[i] = 0;
        } 
        for (int i = 1; i <= n; i ++) {
        	for (auto j: g[i]) {
        		if (i < j && bccno[i] == bccno[j]) {
        			cnt[bccno[i]] ++;
        		}
        	}
        }
        for(int i=1;i<=n;i++) {
        	if(vis[i]==0) getsz(i, i);
        }
    }
} Saber;

int m, n, u[N], v[N];
int main() {
	scanf("%d", &n); m = n<<1|1;
	for(int i=1;i<=2*m;i++) par[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u[i],&v[i]); 
		g[u[i]].push_back(v[i] + m);
		g[v[i] + m].push_back(u[i]);

		//printf("link %d %d\n", u[i], v[i] + m);
		if (find(u[i]) == find(v[i] + m)) {
			sz[find(u[i])] ++;
		} else {
			sz[find(v[i] + m)] += sz[find(u[i])] + 1;
			par[find(u[i])] = find(v[i] + m); 
		}
		v[i] += m;
	}		
	Saber.Excalibur(2 * m);//

	int cnt = 0, root = -1;
	for(int i=1;i<=2*m;i++){
		if(find(i) == i) {
			if (sz[find(i)] % 2 == 1) {
				cnt ++; root = find(i);
			}
		}
	}
	// printf("root = %d\n", root);
	//printf("!! %d\n", cnt);
	for (int i = 1; i <= m; i ++) {
		int x = u[i], y = v[i];
		//printf("## %d %d\n", u[i], v[i]);
		if (bridge.count(make_pair(x, y))) {
			//printf("@@\n");
			int nex = cnt;
			if (sz[find(x)] % 2 == 1) {
				if (cnt > 1) printf("NG\n");
				else {
					int u1 = Saber.bccno[x];
					int u2 = Saber.bccno[y];
					if (Saber.fat[u1] == u2) swap(u1, u2);//
					//printf("%d -> %d\n", u1, u2);
					if ((Saber.sum[u2]-1) % 2 == 0) { 
						printf("OK\n");
					} else {
						printf("NG\n");
					}
				}
			} else {
				printf("NG\n");
			}
		} else {
			// printf("!\n");
			if (cnt == 1 && find(x) == find(root)) printf("OK\n");
			else printf("NG\n");
		}
	}
}