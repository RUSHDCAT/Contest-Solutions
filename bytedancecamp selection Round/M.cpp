#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
const int MOD = 998244353;
const int root = 15311432;   // root ^ (2^23) % MOD = 1
const int root_1 = 469870224; // root * root_1 = 1
const int root_pw = 1 << 23; // 998244353 = 119 * 2^23 + 1
LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL modinv(LL a){
    LL x0=0,x1=1,r0=MOD,r1=a;
    while(r1){
        LL q=r0/r1;
        x0-=q*x1;swap(x0,x1);
        r0-=q*r1;swap(r0,r1);
    }
    return x0<0?x0+MOD:x0;
}
void fft(vector<int> &a, bool inv) { // a.size()不为2的幂会原地爆炸。
    int n=(int)a.size();
    // 迷 の butterfly操作
    for(int i=1,j=0;i<n;i++) {
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit; j+=bit;   
        if(i<j)swap(a[i],a[j]);
    }
    // 施展 DFT
    for(int len=2;len<=n;len<<=1) {
        int wlen=inv?root_1:root;
        for(int i=len;i<root_pw;i<<=1) wlen=wlen*1LL*wlen%MOD;
        for(int i=0;i<n;i+=len) {
            int w=1;
            for(int j=0;j<len/2;j++) {
                int u=a[i+j],v=int(a[i+j+len/2]*1LL*w%MOD);
                a[i+j] = (u+v<MOD)?u+v:u+v-MOD;
                a[i+j+len/2] = (u-v>=0)?u-v:u-v+MOD;
                w = w*1LL*wlen%MOD;
            }
        }
    }
    if(inv) {
        int nrev = modinv(n);
        for(int i=0;i<n;i++) a[i]=a[i]*1LL*nrev%MOD;
    }
}
void pro(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<int> fa(a.begin(), a.end()),fb(b.begin(), b.end());
    int n=1; while (n<(int) max(a.size(), b.size())) n<<=1; n<<=1;
    fa.resize(n),fb.resize(n);
    fft(fa,false), fft(fb,false);
    for(int i=0;i<n;i++) fa[i] = 1LL*fa[i]*fb[i]%MOD;
    fft(fa,true);
    res = fa;
}

int n;
LL fac[N], inv[N];

int s[N], t[N], l[N], r[N];

int solve(vector< pair<int,int> > A, vector< pair<int,int> > B) {
	/*
	printf("interval A\n");
	for(auto p: A) {
		printf("[%d, %d]\n", p.first, p.second);
	}
	printf("interval B\n");
	for(auto p: B) {
		printf("[%d, %d]\n", p.first, p.second);
	}
	*/
	LL ans = 0;

	LL sa = 0, sb = 0;
	for(auto p: A) sa += p.first; sa %= MOD;
	for(auto p: B) sb += p.first; sb %= MOD;

	ans = sa * sb % MOD;
	
	vector<int> f1, f2;
	f1.resize(n + 1); for(int i=0;i<n+1;i++) f1[i]=0;
	f2.resize(n + 1); for(int i=0;i<n+1;i++) f2[i]=0;
	for(auto p: A) {
		int a = p.first, x = p.second;
		f1[x] = f1[x] + (1LL * a * fac[n - x] % MOD); f1[x] %= MOD;
	}
	for(auto p: B) {
		int b = p.first, y = p.second;
		f2[y] = f2[y] + (1LL * b * fac[n - y] % MOD); f2[y] %= MOD;
	}
	pro(f1, f2, f1);
	LL sub = 0;	

	for(int i=0;i<=n;i++) {
		LL tmp1 = f1[i];
		LL tmp2 = inv[n - i] * inv[n] % MOD;
		sub = sub + (tmp1 * tmp2 % MOD);
		sub %= MOD; 
	}
	ans = ((ans - sub) % MOD + MOD) % MOD;
	return ans;
}


vector<pair<int, int > > gao(vector<pair<int, int > > vec){
	vector<pair<int, int > > p;
	for (auto v : vec){
		p.push_back(make_pair(v.first, -1));
		p.push_back(make_pair(v.second, 1));
	}
	sort(p.begin(), p.end());
	vector<pair<int, int > > res;
	int num = 0, L = -1;
	for (auto v : p){
		if (L == -1){
			L = v.first;
			num ++;
			continue;
		}
		if (v.first - L > 0){
			res.push_back(make_pair(v.first - L, num));
		}
		num += -v.second;
		L = v.first;
	}
	return res;
}



LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}

int brt() {
	LL ans=0;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			int x=0,y=0;
			for(int k=1;k<=n;k++){
				if(s[k]<=i && i<t[k]) x++;
				if(l[k]<=j && j<r[k]) y++;
			}
			//printf("i=%d,j=%d,x=%d,y=%d,d=%d\n", i,j,x,y, 1 - (c(n-x,y) * mpow(c(n,y),MOD-2) % MOD));
			ans += (1 - c(n-x,y) * mpow(c(n,y),MOD-2) % MOD);
			ans = (ans % MOD +  MOD) % MOD;
		}
	}
	printf("%d\n", ans);
	return ans;
}

int main() {
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}

	scanf("%d", &n);
	vector< pair<int,int> > v1, v2;

 	for(int i=1;i<=n;i++){
		scanf("%d%d",&s[i],&t[i]); 
		//s[i] = rand() % 1000000000, t[i] = rand() % 1000000000; if(s[i]>t[i])swap(s[i],t[i]);
		v1.push_back(make_pair(s[i], t[i]));

	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]); 
		//l[i] = rand() % 1000000000, r[i] = rand() % 1000000000; if(l[i]>r[i])swap(l[i],r[i]);
		v2.push_back(make_pair(l[i], r[i]));
	}
	v1 = gao(v1); v2 = gao(v2);
	printf("%d\n", solve(v1, v2));
	//brt();
} 







