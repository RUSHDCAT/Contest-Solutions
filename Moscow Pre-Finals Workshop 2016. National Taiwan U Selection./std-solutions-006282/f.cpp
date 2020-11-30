#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
// by shik
#include <bits/stdc++.h>
using namespace std;
const int MOD1=26880696;
const int MOD2=20160519;
struct Mat {
    int x[2][2];
    Mat() { memset(x,0,sizeof(x)); }
    int* operator[]( int i ) { return x[i]; }
};
Mat mul( Mat a, Mat b, int m ) {
    Mat c;
    for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ )
        for ( int k=0; k<2; k++ ) c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%m;
    return c;
}
int get_fib( int n, int m ) {
    Mat A,X;
    A[0][1]=A[1][0]=A[1][1]=X[0][0]=X[1][1]=1;
    while ( n ) {
        if ( n&1 ) X=mul(X,A,m);
        A=mul(A,A,m);
        n>>=1;
    }
    return X[0][1];
}
int main() {
    int t,n;
    scanf("%d",&t);
    while ( t-- ) {
        scanf("%d",&n);
        printf("%d\n",get_fib(get_fib(n,MOD1),MOD2));
    }
    return 0;
}
