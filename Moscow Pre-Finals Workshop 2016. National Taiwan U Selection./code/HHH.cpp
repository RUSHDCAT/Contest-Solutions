#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define LL long long int
#define REP(i,n) for (int i = 1; i <= (n); i++)
#define Redge(u) for (int k = h[u],to; k; k = ed[k].nxt)
#define cls(s,v) memset(s,v,sizeof(s))
#define mp(a,b) make_pair<int,int>(a,b)
#define cp pair<int,int>
using namespace std;
const int maxn = 400005,maxm = 100005,INF = 0x3f3f3f3f;
inline int read(){
	int out = 0,flag = 1; char c = getchar();
	while (c < 48 || c > 57){if (c == '-') flag = 0; c = getchar();}
	while (c >= 48 && c <= 57){out = (out << 1) + (out << 3) + c - 48; c = getchar();}
	return flag ? out : -out;
}
int pr[]={469762049,998244353,1004535809};
int R[maxn];
inline LL qpow(LL a,LL b,LL p){
	LL re = 1; a %= p;
	for (; b; b >>= 1,a = a * a % p)
		if (b & 1) re = re * a % p;
	return re;
}
struct FFT{
	int G,P,A[maxn];
	void NTT(int* a,int n,int f){
		for (int i = 0; i < n; i++) if (i < R[i]) swap(a[i],a[R[i]]);
		for (int i = 1; i < n; i <<= 1){
			int gn = qpow(G,(P - 1) / (i << 1),P);
			for (int j = 0; j < n; j += (i << 1)){
				int g = 1,x,y;
				for (int k = 0; k < i; k++,g = 1ll * g * gn % P){
					x = a[j + k],y = 1ll * g * a[j + k + i] % P;
					a[j + k] = (x + y) % P,a[j + k + i] = (x + P - y) % P;
				}
			}
		}
		if (f == 1) return;
		int nv = qpow(n,P - 2,P); reverse(a + 1,a + n);
		for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * nv % P;
	}
}fft[3];
int F[maxn],G[maxn],B[maxn],deg1,deg2,deg,md;
LL ans[maxn];
LL inv(LL n,LL p){return qpow(n % p,p - 2,p);}
LL mul(LL a,LL b,LL p){
	LL re = 0;
	for (; b; b >>= 1,a = (a + a) % p)
		if (b & 1) re = (re + a) % p;
	return re;
}
void CRT(){
	deg = deg1 + deg2;
	LL a,b,c,t,k,M = 1ll * pr[0] * pr[1];
	LL inv1 = inv(pr[1],pr[0]),inv0 = inv(pr[0],pr[1]),inv3 = inv(M % pr[2],pr[2]);
	for (int i = 0; i <= deg; i++){
		a = fft[0].A[i],b = fft[1].A[i],c = fft[2].A[i];
		t = (mul(a * pr[1] % M,inv1,M) + mul(b * pr[0] % M,inv0,M)) % M;
		k = ((c - t % pr[2]) % pr[2] + pr[2]) % pr[2] * inv3 % pr[2];
		ans[i] = ((k % md) * (M % md) % md + t % md) % md;
	}
}
void conv(){
	int n = 1,L = 0;
	while (n <= (deg1 + deg2)) n <<= 1,L++;
	for (int i = 1; i < n; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
	for (int u = 0; u <= 2; u++){
		fft[u].G = 3; fft[u].P = pr[u];
		for (int i = 0; i <= deg1; i++) fft[u].A[i] = F[i];
		for (int i = 0; i <= deg2; i++) B[i] = G[i];
		for (int i = deg2 + 1; i < n; i++) B[i] = 0;
		fft[u].NTT(fft[u].A,n,1); fft[u].NTT(B,n,1);
		for (int i = 0; i < n; i++) fft[u].A[i] = 1ll * fft[u].A[i] * B[i] % pr[u];
		fft[u].NTT(fft[u].A,n,-1);
	}
}
int main(){
	deg1 = read(); deg2 = read(); md = read();
	for (int i = 0; i <= deg1; i++) F[i] = read();
	for (int i = 0; i <= deg2; i++) G[i] = read();
	conv(); CRT();
	for (int i = 0; i <= deg; i++) printf("%lld ",ans[i]);
	return 0;
}