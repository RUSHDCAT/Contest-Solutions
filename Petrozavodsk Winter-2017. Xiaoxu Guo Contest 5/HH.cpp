#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
const int Mod = 1000000007;
struct Matrix
{
    int a[5][5];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                for(int k=0;k<4;k++)
                    C.a[i][j]=(C.a[i][j]+1LL*a[i][k]*B.a[k][j])%Mod;
        return C;
    }
    Matrix operator ^ (const ll &p)const
    {
        Matrix A=(*this),res;
        res.init();
        ll t=p;
        while(t)
        {
            if(t&1)
            t>>=1;
        }
        return res;
    }
};

int g[100]={0};

int main() {
	g[1]=1,g[2]=2,g[3]=6;g[4]=16;
	//g[i]=2*g[i-1]+g[i-3]+2;	

	Matrix A;
	memset(A.a,0,sizeof(A.a));
	A.a[0][0] = 2, A.a[0][2] = 1, A.a[0][3] = 2;
	A.a[1][0] = 1;
	A.a[2][1] = 1;
	A.a[3][3] = 1;
	//int t; scanf("%d", &t);
	int x; 
	while (~scanf("%d", &x)) {
		
		if (x <= 4) printf("%d\n", g[x]);
		else {
			int d = x - 4;
			Matrix B = A ^ d;
			LL ans = 1LL * 16 * B.a[0][0] + 1LL * 6 * B.a[0][1] + 1LL * 2 * B.a[0][2] + B.a[0][3];
			ans %= Mod;
			printf("%lld\n", ans);
		}
	}
}