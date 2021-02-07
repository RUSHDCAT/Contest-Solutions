#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
const int N = 200000 + 10;
const int Mod = 13;
int n;

struct Matrix
{
    int a[15][15];
    Matrix()
    {
        memset(a,0,sizeof(a));
    }
    void init()
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=(i==j);
    }
    Matrix operator * (const Matrix &B)const
    {
        Matrix C;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
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
            if(t&1)res=res*A;
            A=A*A;
            t>>=1;
        }
        return res;
    }
    void prt() {
    	printf("#############\n");
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			printf("%d ", (a[i][j]%Mod+Mod)%Mod);
    		}
    		printf("\n");
    	}
    }
};

int main() {
	n=5;
	Matrix M = Matrix(); 
	for(int i=0;i<n;i++){
		M.a[i][i] = -1;
		M.a[i][(i+1+n)%n] = 2;
	}
	for(int i=0;i<100;i++){
		(M^i).prt();
	}
}