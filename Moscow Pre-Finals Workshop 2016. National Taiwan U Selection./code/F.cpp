#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 30000000 + 10;
const int mod = 20160519;
int f[N];
map< pair<int,int> ,int> mp;

const int M = 26880696;
struct Matrix
{
    int a[2][2];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%M;
        return C;
    }
    Matrix operator ^ (const LL &p)const
    {
        Matrix A=(*this),res;
        res.init();
        LL t=p;
        while(t)
        {
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
};
LL F(int n) {
	// cal f(n) % p
	Matrix p;
	p.a[0][0] = 1, p.a[0][1] = 1;
	p.a[1][0] = 1, p.a[1][1] = 0;
	p = p ^ (n - 1);
	return p.a[0][0];
	// [1, 0]
}
int main() {
	//printf("%lld\n", F(3));
	int p = 26880696;
	f[0]=0, f[1]=1;
	for(int i=2;i<N;i++) {
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		printf("%d\n", f[ F(n) ]);
	}

	/*
	f[0]=0,f[1]=1;
	for(int i=2;i<N;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
		if(mp[make_pair(f[i-1],f[i])]) {
			printf("%d %d\n", i, mp[make_pair(f[i-1], f[i])]); return 0;
		}
		mp[make_pair(f[i-1],f[i])] = i;
	}
	*/
}
/*
f[n] = f[n%p]
f[f[n]%p]
*/