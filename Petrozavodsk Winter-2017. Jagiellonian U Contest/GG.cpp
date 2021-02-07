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


int T;
int n,m,t,a[N];
vector<int> mul(vector<int>&f) {
	vector<int> g;
	pro(f,f,g);
	vector<int> ans(n,0);
	for(int i=0;i<g.size();i++)(ans[i%n]+=g[i])%=m;
	return ans;
}
vector<int> pw(int x) {
	if (x == 0) {
		vector<int> res(n, 0); res[0]=1; return res;
	}
	if (x == 1) {
		vector<int> res(n, 0); res[0]=m-1; res[1]=2; return res;
	}
	vector<int> tmp = pw(x>>1);
	vector<int> tmp2 = mul(tmp);
	if (x % 2 == 0) 
		return tmp2;

	vector<int> nex(n,0);
	for(int i=0;i<n;i++){
		nex[i] = ((tmp2[(i-1+n)%n] * 2 - tmp2[i]) % m + m) % m;
	}
	return nex;
}
vector<int> getnex(vector<int> tmp2) {
	vector<int> nex(n,0);
	for(int i=0;i<n;i++){
		nex[i] = ((tmp2[(i+1+n)%n] * 2 - tmp2[i]) % m + m) % m;
	}
	return nex;
}
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&t);
		vector<int> a(n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		vector<int> f=pw(t);
		//for(auto x: f) printf("%d ", x);printf("\n");
		reverse(f.begin(),f.end());
		vector<int> tmp,res(n,0);
		pro(a,f,tmp);
		for(int i=0;i<tmp.size();i++){
			int pos=((i-(n-1))%n+n)%n;
			res[pos]+=tmp[i];
			res[pos]=res[pos]%m;
			if(res[pos]==0) res[pos]=m;
		}
	
		for(int i=0;i<n;i++)printf("%d ",res[i]);printf("\n");
		//for(int i=1;i<=t;i++) a=getnex(a);
		//for(int i=0;i<n;i++)printf("%d ", a[i]==0?m:a[i]);printf("\n");
	}
}


