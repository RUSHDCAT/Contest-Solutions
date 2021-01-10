#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;
ll fa[1000000 + 10], inv[1000000 + 10];
namespace zyt
{
    const int N = 2e6;
    typedef long long ll;
    ll n, m, p;
    inline ll power(ll a, ll b, const ll p = LLONG_MAX)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                ans = ans * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return ans;
    }
    ll fac(const ll n, const ll p, const ll pk)
    {
        if (!n)
            return 1;

        if(n<=1000000) {
            ll ans = 1; 
            for(int i=1;i<=n;i++) {
                int x=i;
                while(x%p==0) x/=p;
                ans=ans*x%pk;
            }
            return ans;
        }

        ll ans = 1;
        for (int i = 1; i < pk; i++)
            if (i % p)
                ans = ans * i % pk;
        ans = power(ans, n / pk, pk);
        for (int i = 1; i <= n % pk; i++)
            if (i % p)
                ans = ans * i % pk;
        return ans * fac(n / p, p, pk) % pk;
    }
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
    ll inv(const ll a, const ll p)
    {
        ll x, y;
        exgcd(a, p, x, y);
        return (x % p + p) % p;
    }
    ll C(const ll n, const ll m, const ll p, const ll pk)
    {
       // printf("# %lld %lld %lld %lld\n", n,m,p,pk);
        if (p > 1000000) {
            fa[0]=1;
            for(int i=1;i<=n;i++) fa[i]=fa[i-1]*i%p;
            return fa[n] * power(fa[m],p-2,p) % p * power(fa[n-m],p-2,p) % p;
        }

        if (n < m)
            return 0;
        ll f1 = fac(n, p, pk), f2 = fac(m, p, pk), f3 = fac(n - m, p, pk), cnt = 0;

        for (ll i = n; i; i /= p)
            cnt += i / p;
        for (ll i = m; i; i /= p)
            cnt -= i / p;
        for (ll i = n - m; i; i /= p)
            cnt -= i / p;
        return f1 * inv(f2, pk) % pk * inv(f3, pk) % pk * power(p, cnt, pk) % pk;
    }
    ll a[N], c[N];
    int cnt;
    inline ll CRT()
    {
        ll M = 1, ans = 0;
        for (int i = 0; i < cnt; i++)
            M *= c[i];
        for (int i = 0; i < cnt; i++)
            ans = (ans + a[i] * (M / c[i]) % M * inv(M / c[i], c[i]) % M) % M;
        return ans;
    }
    ll exlucas(const ll n, const ll m, ll p)
    {
        //printf("n=%lld,m=%lld,p=%lld\n", n,m,p);
        ll tmp = sqrt(p); cnt = 0;
        for (int i = 2; p > 1 && i <= tmp; i++)
        {
            ll tmp = 1;
            while (p % i == 0)
                p /= i, tmp *= i;
            if (tmp > 1)
                a[cnt] = C(n, m, i, tmp), c[cnt++] = tmp;
        }
        if (p > 1)
            a[cnt] = C(n, m, p, p), c[cnt++] = p;
        return CRT();
    }

}





void solve(int n,int m) {
    if (n % 2 == 1) {
        printf("0\n");
    } else {
        ll b = n/2 + 1;
        ll x = zyt::exlucas(n,n/2,m);
        ll y = zyt::exlucas(n,n/2+1,m);
        ll a0 = x - y;
        
       // printf("# %lld %lld\n", zyt::exlucas(n,n/2,m), zyt::exlucas(n,n/2+1,m));

        ll a1 = 2 * y % m;
        ll tot = zyt::power(2,n,m);
        ll a2 = tot - a0 - a1;
        //printf("%lld %lld %lld\n", a0, a1, a2);

        ll ans = a0 * 1 + a1 * 2 + a2 * 3;
        ans = (ans % m + m) % m;
        printf("%lld\n", ans);
    }}

int main() {
    //printf("# %lld %lld\n", zyt::exlucas(12,6,1000), zyt::exlucas(12,7,1000));
    int n, m;
	cin >> n >> m;
    solve(n, m);
}

