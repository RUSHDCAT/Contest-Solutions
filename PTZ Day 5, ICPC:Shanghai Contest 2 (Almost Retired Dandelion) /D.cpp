#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000;
ll mod_mul(ll a,ll b,ll n){
    ll res=0;
    while(b){
        if(b&1)res=(res+a)%n;
        a=(a+a)%n;
        b>>=1;
    }
    return res;
}
ll mod_exp(ll a,ll b,ll n){
    ll res=1;
    while(b){
        if(b&1)res=mod_mul(res,a,n);
        a=mod_mul(a,a,n);
        b>>=1;
    }
    return res;
}
bool miller_rabin(ll n){
    if(n==2||n==3||n==5||n==7||n==11)return true;
    if(n==1||!(n%2)||!(n%3)||!(n%5)||!(n%7)||!(n%11))return false;
    ll x,pre,u;
    int i,j,k=0;
    u=n-1;
    while(!(u&1)){
        k++;u>>=1;
    }
    srand((ll)time(0));
    for(i=0;i<10;i++){//5次足够AC了
        x=rand()%(n-2)+2;
        if((x%n)==0)continue;
        x=mod_exp(x,u,n);
        pre=x;
        for(j=0;j<k;j++){
            x=mod_mul(x,x,n);
            if(x==1&&pre!=1&&pre!=n-1)return false;
            pre=x;
        }
        if(x!=1)return false;
    }
    return true;
}


map<ll, int> match;
map<ll, bool> us;
vector<ll> g[N];
bool dfs(int x) {
    for(int i=0;i<g[x].size();i++){
        if(us[g[x][i]]) continue;
        us[g[x][i]] = 1;
        if(match.find(g[x][i]) == match.end() || dfs(match[g[x][i]]))
        {
            match[g[x][i]] = x; 
            return 1;
        }
    }
    return 0;
}
int hungary(ll n) {
    match.clear();
    int tot = 0;
    for(int i=1;i<=n;i++) {
        us.clear();
        if(dfs(i)) tot ++;
    }
    return tot;
}

void print(vector< pair<int,ll> > v){
	vector<vector<int> > ans;
	for(int i=1;i<60;i++) ans.push_back({i-(i==1),i-(i==1)});
    vector<int> res;
	for(auto i : v){
		if(i.second==1){
            res.push_back(i.first);
		}
		else{
			assert(i.first==0);
			vector<int> a;
			ll x = i.second;
			for(int y=0;y<60;y++){
				if(x>>y&1) a.push_back(y==0 ? 0 : y+1);
			}
		    for (auto val: a) res.push_back(val);
		}
	}
    ans.push_back(res);
	cout<<ans.size() + 1<<endl;
	for(auto i: ans){
		cout<<i.size()<<" ";
		for(int j: i) cout<<j<<' '; cout<<endl;
	}
}

ll n;
vector<ll> res;
void add(ll x) {
	//printf("add %lld\n", x);
	for (ll i = 1; i <= x; i ++) g[i].clear();

	for (ll i = 1; i <= x; i ++) {
		for (ll j = n; j >= n - x + 1; j --) {
			if (j % i == 0) {
				g[i].push_back(j);
				//printf("# %lld - %lld\n", i, j);
			}
		}
	}
	if (hungary(x) == x)  res.push_back(1); else res.push_back(0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    if (n <= 4) {
        cout << "2" << endl;
        cout << n+1;
        for (int i=1;i<=n+1;i++) cout << " 1";
        cout << endl; return 0;
    }


    ll pos = 1; int cnt = 0;
    for (ll x = n; x >= 1; x --) {
    	if (miller_rabin(x) == true) {
    		cnt ++;
    	}
    	if (cnt >= 2) {
    		pos = x; break;
    	}
    }

    ll cnt_ = n - pos + 1;
    //printf("# %d\n", pos);
    for (ll i = 1; i <= n - pos; i ++) add(i);
    ll rem = n + 1 - 2 * cnt_;
	
	vector< pair<int,ll> > vec;
    vec.push_back(make_pair(1, 1));
	for (auto x: res) vec.push_back(make_pair(x, 1));
	if (rem > 0) vec.push_back(make_pair(0, rem));
	reverse(res.begin(), res.end());
	for (auto x: res) vec.push_back(make_pair(x, 1));
	vec.push_back(make_pair(1,1));
	for (auto p: vec) {
		printf("# %lld %lld\n", p.first, p.second);
	}
	
	print(vec);
}