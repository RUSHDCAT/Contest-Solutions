#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;

ll exgcd(const ll a, const ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll xx, yy, g = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;
    return g;
}

ll down(ll x, ll y) {
	if(x%y==0) return x/y;
	if(x>=0)return x/y;
	return - ((-x+y-1)/y);
}
ll up(ll x,ll y){
	if(x%y==0) return x/y;
	if(x>=0)return (x+y-1)/y;
	return -(-x/y);
}

int main() {
	int n; ll b, d;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&b,&d);
		ll x,y;
		ll g = exgcd(b,d,x,y);

		ll ans = max(b / (d/g), 0LL);
		if (b % (d/g) == 0) ans --;
		printf("%lld\n", max(ans,0LL));
	}	
}