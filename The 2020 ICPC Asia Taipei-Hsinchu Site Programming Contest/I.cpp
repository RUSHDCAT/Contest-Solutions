#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
vector<int> g[N], bcc[N];
int n, m;

struct BCC1 {
    int pre[N], low[N], iscut[N], bccno[N];
    int dfs_clock, bcc_cnt;
    stack< pair<int,int> > S;
    
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
                if (lowv >= pre[u]) { 
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

    int Excalibur(int n) 
    {
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        while (S.size()) S.pop();
        dfs_clock = bcc_cnt = 0;
        
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        }   
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            if (iscut[i]) ans ++;
        }
        return ans;
    }
} Saber1;


struct BCC2 {
    int pre[N], low[N], iscut[N], bccno[N];
    int dfs_clock, bcc_cnt, bridge, P, Q;
    stack< pair<int,int> > S;
    set< pair<int,int> > br;

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
                    bcc[++ bcc_cnt].clear();
                    bridge ++;
                    br.insert(make_pair(u,v));
                    br.insert(make_pair(v,u));
                    int tmp = 0;
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
                        tmp ++;
                    }
                    Q = max(tmp, Q);
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
    int gcd(int x,int y){
        return y == 0 ? x : gcd(y,x%y);
    }
    int Excalibur(int n) 
    {
        br.clear();
        while (S.size()) S.pop();
        bridge = 0; P = Q = 0;
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        
        for (int i = 1; i <= n; i ++) {
            if (pre[i] == 0)
                dfs(i, -1);
        }   
        P = bridge;

        vector<int> vis(n+1, 0); Q = 0;
        for (auto e: br) {
        //    printf("bridge %d %d\n", e.first, e.second);
        }
        for (int i = 1; i <= n; i ++) {
            if (vis[i] == 0) {
               // printf("i = %d\n", i);
                int tmp = 0; 
                queue<int> q; vis[i] = 1; q.push(i);
                while (q.size()) {
                    int u = q.front(); q.pop();
                    for (auto v: g[u]) {
                        if (br.find(make_pair(u,v)) != br.end()) continue;
                        tmp ++;
                        if (vis[v]) continue;
                        vis[v] = 1; q.push(v); 
                    }
                }
                tmp /= 2; if (tmp) P ++;
                Q = max(tmp, Q);
            }
        }
        Q = max(Q, 1);
        //printf("Q = %d\n", Q);


        int g = gcd(P, Q); P /= g, Q /= g;
        return 0;
    }
} Saber2;

int main() {
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) bcc[i].clear();
        for (int i = 1; i <= n; i ++) g[i].clear();
        for (int i = 1; i <= m; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        } 
        printf("%d ", Saber1.Excalibur(n));
        Saber2.Excalibur(n);
        printf("%d %d %d\n", Saber2.bridge,Saber2.P,Saber2.Q);
    }
}

