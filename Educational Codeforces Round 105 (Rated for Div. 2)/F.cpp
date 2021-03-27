#include <bits/stdc++.h>
using namespace std;
const int N=3002;
namespace FindEulerPath {
    int n,m,deg[N],par[N];
    int head[N<<1],eCnt;
    int find(int x) {
        return par[x]==x?x:par[x]=find(par[x]);
    }
    struct Edge {
        int u,v,nex,fg;
    } edge[N<<1];
    void addEdge(int u,int v){
        edge[eCnt].u=u, edge[eCnt].v=v, edge[eCnt].nex=head[u], edge[eCnt].fg=0;
        head[u]=eCnt++;
    }
    int vStk[N],vTop;
    int eStk[N],eTop;
    vector<int> vPath, ePath;
    void init(int n, int m) {
        eCnt=vTop=eTop=0;
        vPath.clear(); ePath.clear();
        for(int i=0;i<=n;i++) par[i]=i,deg[i]=0,head[i]=-1;
    }
    void eulerpath(int src){
        vPath.clear(); vStk[vTop=1]=src;
        ePath.clear(); eTop = 0;
        while(vTop){
            int u=vStk[vTop];
            if(head[u]==-1){
                {
                    vPath.push_back(u); --vTop;
                }
                if(eTop) {
                    ePath.push_back(eStk[eTop]); --eTop;
                }
                continue;
            }
            int v=edge[head[u]].v;
            if(edge[head[u]].fg) {
                head[u]=edge[head[u]].nex; continue;
            }
            edge[head[u]].fg = edge[head[u]^1].fg = 1;
            vStk[++vTop] = edge[head[u]].v; 
            eStk[++eTop] = head[u];
        }
    }
}

int n,m,mm;
vector<int> g[N], gg[N];

int par[N],sz[N];
int find(int x) {
    return par[x]==x?x:par[x]=find(par[x]);
}
bool ban[N][N],link[N][N];
void solve(int src){
   // printf("init %d %d\n", n,mm);
    FindEulerPath::init(n,mm);
    int deg[N]={0};
    for(int i=1;i<=n;i++) par[i]=i,sz[i]=1;

    for(int i=1;i<=n;i++){
        for(auto j:g[i]) if(!ban[i][j] && i<=j) {
            deg[i]++, deg[j]++;
            if(find(i)!=find(j)){
                sz[find(j)]+=sz[find(i)];
                par[find(i)]=find(j);
            }
            FindEulerPath::addEdge(i,j); FindEulerPath::addEdge(j,i);
        }
    }
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)if(deg[i]&1){
        cnt1++; 
    }
    for(int i=1;i<=n;i++)if(find(i)==i&&sz[find(i)]>1)cnt2++;
    if(cnt1>=3 || cnt2>=2) return;

    FindEulerPath::eulerpath(src);
    vector<int> ans;
    for(auto x: FindEulerPath::vPath) {
        ans.push_back(x);
    }
    assert(ans.back() == src);
    vector<int> res;
    for(int i=1;i<=n;i++) if(ban[i][src]) res.push_back(i);
    ans.push_back(-1);
    for(auto x: res) {
        ans.push_back(x); ans.push_back(src);
    }
    if(ans.back()==-1) ans.pop_back();
    printf("%d\n", ans.size());
    for(auto p: ans) {
        printf("%d ", p);
    }

    printf("\n");
    exit(0);
}
int main() {
    scanf("%d%d",&n,&m); mm=m;
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u); link[u][v]=link[v][u]=true;
    }

    int tot=0;
    for(int i=1;i<=n;i++){
        if(g[i].size()%2) {
            ++tot;
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j: g[i]) {
            if(g[j].size()%2) {
                gg[i].push_back(j);
            }
        }
    }
    int src=1;
    for(int i=1;i<=n;i++)if(g[i].size()%2)src=i;
    mm=m;
    solve(src);

    for(int i=1;i<=n;i++){
        if(gg[i].size()+1 >= tot) {
            mm=m;
            for(auto x:gg[i]) ban[i][x]=ban[x][i]=true, mm--;
            solve(i);
            for(auto x:gg[i]) ban[i][x]=ban[x][i]=false, mm++;
        }
        if(g[i].size()%2==0)continue;
        for(int j=1;j<=n;j++)if(g[j].size()%2 && i!=j) {
            // i->j, back
            if(gg[j].size()-link[i][j]+2 < tot) continue;
            mm = m;
            for(auto x:gg[j]) if(i!=x) ban[j][x]=ban[x][j]=true, mm--;
            solve(j);
            for(auto x:gg[j]) if(i!=x) ban[j][x]=ban[x][j]=false, mm++;
        }
    }
    printf("0\n");
}
