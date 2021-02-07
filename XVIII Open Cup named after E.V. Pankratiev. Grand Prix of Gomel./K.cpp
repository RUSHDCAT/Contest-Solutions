#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;

typedef long long LL;
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
    for(i=0;i<100;i++){//5次足够AC了
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
const int M = 1000000 + 10;
LL m;
LL dp[17][M][2];
const LL mod = 998244353;

void add(LL &x, LL y) {
    x += y; if (x >= mod) x -= mod; 
}
int main() {
    vector<int> vec;
    cin >> m;
    
    for (int i = 2; i <= 1000000;i ++) {
        if (m % i == 0) {
            int cnt = 1;
            while (m % i == 0) {
                m /= i; cnt ++;
            }
            vec.push_back(cnt);
        }
    }
    

    if (m > 1) {
        LL x = sqrt(m); x = max(x-2, 0LL);
        while (x*x<m) ++x;
        if(x*x==m) {
            vec.push_back(3);
        } else {
            if (miller_rabin(m)) {
                vec.push_back(2);
            } else {
                vec.push_back(2); vec.push_back(2);
            }
        }
    }

    sort(vec.begin(), vec.end());
    dp[0][1][0] = 1;

    for (int i = 0; i < vec.size(); i ++) {
        for (int j = 1; j < M; j ++) {      
            for (int k = 0; k < 2; k ++) {
                if (dp[i][j][k]==0) continue;
                assert(j * vec[i] < M);
                if (j * vec[i] < M)
                    add(dp[i+1][j * vec[i]][k], dp[i][j][k]);
                if (j * (vec[i] - 1) < M)
                    add(dp[i+1][j * (vec[i] - 1) ][k^1], 2 * dp[i][j][k]);
                if (j * (vec[i] - 2) < M && vec[i] > 2)
                    add(dp[i+1][j * (vec[i] - 2) ][k], dp[i][j][k]);

            }
        }
    }   
    LL pw[M]; pw[0] = 1; for (int i = 1; i < M; i ++) pw[i] = pw[i-1] * 2 % mod;
    LL ans = 0;
    for (int j = 1; j < M; j ++) {
        //if (j <= 6)
        //printf("%d # %d %d\n", j, dp[vec.size()][j][0], dp[vec.size()][j][1]);
        add(ans, dp[vec.size()][j][0] * (pw[j]-1) % mod);
        add(ans, - dp[vec.size()][j][1] * (pw[j]-1) % mod);
    }
    ans = (ans % mod + mod) % mod;
    cout << ans  << endl;
}

