#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000000 + 10;

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
    for(i=0;i<5;i++){//5次足够AC了
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

int prime[N], tot;
bool vis[N];

int n;
ll a[N];
map<ll, vector<int> > vec;
set<ll> big;
void fac(ll x, int pos) {
	for (int i = 1; i <= tot; i ++) {
		if (x % prime[i] == 0) {
			vec[prime[i]].push_back(pos);
			while (x % prime[i] == 0) x /= prime[i];
		}
	}

	if (x == 1) return;

	ll sq = max((ll)sqrt(x) - 2LL, 0LL);
	while (sq * sq < x) sq ++;
	if (sq * sq == x) {
		big.insert(sq);
	} else {
		big.insert(x);
	}
}

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}
int solve(vector<int> & vec) {
	int sg = 0;
	for (int i = 0, j = 0; i < vec.size(); i = j) {
		while (j < vec.size() && vec[j] == vec[i] + (j - i)) j ++;
		sg ^= (j - i);
	}
	return sg;
}
int main() {
	for (int i = 2; i < N; i ++) {
		if (vis[i] == 0) {
			prime[++tot] = i;
			for (int j = i + i; j < N; j += i) vis[j] = 1;
		}
	}

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	//a[i] = 998244359987710471;
    	fac(a[i], i);
    }

    set<ll> all;
    vector<ll> big_vec;
    for (auto x: big) big_vec.push_back(x);

    for (auto x: big_vec) {
    	bool ok = 0;
    	for (auto y: big_vec) {
    		ll g = gcd(x, y);
    		if (g != 1 && g != x) {
    			all.insert(g); all.insert(x / g); ok = true;
    			break;
    		} 
    	}	
    	if (ok == false) all.insert(x);
    }	
    for (int i = 1; i <= n; i ++) {
    	for (auto x: all) {
    		if (a[i] % x == 0)
    			vec[x].push_back(i);
    	}
    }
    int ans = 0;
    for (auto p: vec) {
    	if (p.first >= N && miller_rabin(p.first) == false) continue;
 
    	ans ^= solve(p.second); 
    }
    printf("%s\n", ans ? "First" : "Second");
}

