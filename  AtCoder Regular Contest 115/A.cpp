#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1 << 20;

void FWT(LL a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                LL x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y),a[i+j+d]=(x-y);
                //xor:a[i+j]=x+y,a[i+j+d]=(x-y+mod)%mod;
                //and:a[i+j]=x+y;
                //or:a[i+j+d]=x+y;
            }
}
  
void UFWT(LL a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                LL x=a[i+j],y=a[i+j+d];
                //a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
                a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
                //and:a[i+j]=x-y;
                //or:a[i+j+d]=y-x;
            }
}
  
void solve(LL a[],LL b[],int n) {
    FWT(a,n);
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*a[i];
    UFWT(a,n);
}
LL a[1<<20];
int main() {
	ios::sync_with_stdio(false);
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		string s; cin >> s;
		int sum = 0;
		for (int j = 0; j < m; j ++) sum = (sum << 1 | (s[j] == '1'));
		a[sum] ++;
	}
	solve(a, a, 1<<m);
	LL ans = 0;
	for (int i = 0; i < 1<<m; i ++) {
		int c = 0;
		for (int j = 0; j < m; j ++) if (i >> j & 1) c ++;
		if (c & 1) ans += a[i];
	}
	cout << ans / 2 << endl;
}