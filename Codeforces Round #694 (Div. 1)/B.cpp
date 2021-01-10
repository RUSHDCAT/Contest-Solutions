#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
bool vis[N]; int mn[N],f[N];
int mp(int x) {
	int ans=1;
	while(x>1) {
		int cur=mn[x],cnt=0;
		while(x%cur==0){
			x/=cur; cnt++;
		}
		if(cnt%2==1) {
			ans*=cur;
		}
	}
	return ans;
}
void init() {
	for(int i=1;i<N;i++) mn[i]=i;
	for(int i=2;i<N;i++){
		if(vis[i]==0){
			for(int j=i+i;j<N;j+=i){
				vis[j]=1; mn[j]=min(mn[j], i);
			}
		}
	}
	for(int i=1;i<N;i++) f[i]=mp(i);
}


int t,cnt[N];
int main() {
	init();

	scanf("%d", &t);
	while(t--){
		int n; scanf("%d",&n); 
		vector<int> a(n+1);
		set<int> st;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); cnt[f[a[i]]] ++;
			st.insert(f[a[i]]);
		}

		int zero=0, mx_0 = 0, mx_1 = 0;

		for(auto x: st) {
			mx_0 = max(mx_0, cnt[x]);
			if(x==1) zero += cnt[x];
			else {
				if(cnt[x]%2==0) zero += cnt[x];
				else mx_1 = max(mx_1, cnt[x]);
			}
		}

		int q; scanf("%d",&q);
		while(q--){
			LL w; scanf("%lld",&w);
			if(w==0) {
				printf("%d\n", mx_0);
			}else{
				printf("%d\n", max(zero, mx_1));
			}
		}
		for(int i=1;i<=n;i++) cnt[f[a[i]]] = 0;
    }
}
