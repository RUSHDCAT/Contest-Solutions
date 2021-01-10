#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n,a[N],b[N],p[N];
bool vis[N];


vector< pair<int,int> > ans;

void solve(vector<int> v) {
	int pos=-1,mx=-1,n=v.size();
	for(int i=0;i<n;i++){;
		if(a[v[i]]>mx){
			mx=a[v[i]]; pos=i;
		}
	}
	for(int i=pos+1;;i++){
		int tmp=i%n;
		if(tmp==pos) break;
		ans.push_back(make_pair(v[pos],v[tmp]));
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		if(a[i]<=b[p[i]] && i!=p[i]) return !printf("-1\n");
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vector<int> v;
			int now=i;
			while(vis[now]==0){
				vis[now]=1; v.push_back(now);
				now=p[now];
			}
			if(v.size()>1){
				solve(v);
			}
		}		
	}
	printf("%d\n", ans.size());
	for(auto p: ans) {
		printf("%d %d\n", p.first, p.second);
	}
}
