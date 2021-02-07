#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 10;
const ll mod = 98765431;
vector<int> g[N];
int vis[N],stk[N],top,in[N];
void dfs(int u,int p,vector<int> &r){
	vis[u] = 1; stk[++top] = u;
	for(int v: g[u]) if(v!=p){
		if(!vis[v]) dfs(v,u,r);
		else if(vis[v]==1){
			for(int i=top;stk[i]!=v;i--){
				r.push_back(stk[i]);
			}
			r.push_back(v);
		}
	}
	vis[u] = 2; stk[top--] = 0;
}
ll func(ll x){
	static unordered_map<ll,ll> m;
	if(m.count(x)) return m[x];
	return m[x] = ((1ll*rand()<<16|rand())<<16|rand())<<16|rand();
}
ll dfs_hash(int u,int p){
	ll ans = 0;
	for(int v: g[u]) if(v!=p&&!in[v]){
		ans ^= dfs_hash(v,u);
	}
	return func(ans);
}
vector<ll> min_rep(vector<ll> s){
	int n = s.size();
	for(int i=0;i<n;i++) s.push_back(s[i]);
	int i,j,k,l;
	for(i=0,j=1;j<n;){
		for(k=0;k<n&&s[i+k]==s[j+k];k++);
		if(k>=n) break;
		if(s[i+k]<s[j+k]) j += k + 1;
		else{
			l = i + k, i = j, j = max(l,j) + 1;
		}
	}
	return vector<ll>(s.begin()+i,s.begin()+i+n);
}
ll hashi(vector<ll> s){
	ll x = 1, ans = 0;
	for(ll i: s){
		(ans += i % mod * x % mod) %= mod;
		(x *= 233) %= mod;
	}
	return ans;
}
ll calc(int n){
	vector<int> ring;
	dfs(1,0,ring);
	// cout<<"ring: ";
	// for(int i: ring) cout<<i<<','; cout<<endl;
	for(int i: ring) in[i] = 1;
	vector<ll> s;
	for(int i: ring) s.push_back(dfs_hash(i,0));
	// cout<<"string: ";
	// for(ll i: s) cout<<i<<','; cout<<endl;
	s = min_rep(s);
	// cout<<"string: ";
	// for(ll i: s) cout<<i<<','; cout<<endl;
	ll x = hashi(s);
	reverse(s.begin(),s.end());
	s = min_rep(s);
	ll y = hashi(s);
	if(x>y) swap(x,y);
	return (x * 233 % mod + y) % mod;
}
int main(){
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin>>T;
	while(T--){
		int t; cin>>t;
		set<ll> s;
		while(t--){
			int n; cin>>n;
			for(int i=1;i<=n;i++){
				int u,v; cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			s.insert(calc(n));
			for(int i=1;i<=n;i++) g[i].clear(), in[i] = vis[i] = 0;
		}
		cout<<s.size()<<endl;
	}
}