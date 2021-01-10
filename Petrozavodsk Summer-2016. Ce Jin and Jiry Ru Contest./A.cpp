#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int T,n,m;
int a[N],b[N],l[N],r[N];



int match[N];
bool us[N];
vector<int> g[N];
bool dfs(int x)
{
    for(int i=0;i<g[x].size();i++)
    {
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
int hungary()
{
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
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n;i++) scanf("%d",&b[i]);
		for(int i=0;i<m;i++) {
			scanf("%d%d",&l[i],&r[i]);l[i]--,r[i]--;
		}
		for(int i=0;i<n;i++) g[i].clear();
		for(int i=0;i<n;i++){
			int lef=i,rig=i;
			for(int j=0;j<m;j++){
				if(min(rig, r[j]) >= max(lef, l[j])) {
					lef = min(lef, l[j]); rig = max(rig, r[j]);
				}
			}
			//printf("i=%d,lef=%d,rig=%d\n", i,lef,rig);
			for(int j=lef;j<=rig;j++){
				if(a[i] == b[j]) {
					g[i].push_back(j);
				}
			}
		}
		printf("%s\n", hungary()==n?"Yes":"No");
	}	
}