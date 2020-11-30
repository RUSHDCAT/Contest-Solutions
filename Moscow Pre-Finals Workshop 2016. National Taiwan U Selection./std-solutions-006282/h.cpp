#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

// }}}

const int MOD=1e6+3;
const int inv2=500002;

namespace Mul {
    typedef double Double;
    const Double pi=acosl(-1.0);
    const int SQ_MOD=1024;
    
    struct Complex {
        Double re,im;
        Complex( Double _re=0, Double _im=0 ):re(_re),im(_im) {}
        Complex operator +( const Complex &x ) const { return {re+x.re,im+x.im}; }
        Complex operator -( const Complex &x ) const { return {re-x.re,im-x.im}; }
        Complex operator *( const Complex &x ) const { return {re*x.re-im*x.im,re*x.im+im*x.re}; }
    };

    void fft( vector<Complex> &a, int dir ){
        int n=a.size();
		for ( int i=0,j=1; j<n-1; j++ ) {
			for ( int k=n>>1; k>(i^=k); k>>=1 );
			if ( i<j ) swap(a[i],a[j]);
		}
        for ( int m=1; m+m<=n; m<<=1 ) {
            Complex wm(cos(dir*pi/m),sin(dir*pi/m));
            for ( int k=0; k<n; k+=m+m ) {
                Complex w=1;
                for ( int j=k; j<k+m; j++ ) {
                    Complex u=a[j],v=a[j+m]*w;
                    a[j]=u+v;
                    a[j+m]=u-v;
                    w=w*wm;
                }
            }
        }
    }

    template<typename T>
    void mul( int na, const T *a, int nb, const T *b, T *c ) {
        static vector<Complex> x,y;
        assert(na>0 && nb>0);
        int n=1;
		while ( n<2*max(na,nb) ) n*=2;
        x.resize(n);
        y.resize(n);
		for ( int i=0; i<n; i++ ) x[i]=y[i]=0;
		for ( int i=0; i<na; i++ ) x[i]=a[i];
		for ( int i=0; i<nb; i++ ) y[i]=b[i];
        fft(x,+1);
        fft(y,+1);
        for ( int i=0; i<n; i++ ) x[i]=x[i]*y[i];
        fft(x,-1);
        for ( int i=0; i<n; i++ ) x[i].re/=n;
        Double max_diff=0;
		for ( int i=0; i<na+nb-1; i++ ) {
            c[i]=x[i].re+0.5;
            max_diff=max(max_diff,abs(c[i]-x[i].re));
        }
        // dump(max_diff);
        assert(max_diff<0.1);
    }

    template<typename T>
	vector<T> mul( const vector<T> &a, const vector<T> &b ) {
		int na=a.size(),nb=b.size();
        assert(na>0 && nb>0);
		vector<T> c(na+nb-1);
        mul(na,a.data(),nb,b.data(),c.data());
		return c;
	}

    template<typename T>
    void mul_mod( int na, const T *a, int nb, const T *b, T *c ) {
        assert(na>0 && nb>0);
        vector<T> a1(a,a+na),a2(a,a+na),b1(b,b+nb),b2(b,b+nb);

        // A * B = (KA1+A2) * (KB1 + B2) = K^2(A1 * B1) + K(A1 * B2 + A2 * B1) + A2 * B2
        for ( int i=0; i<na; i++ ) {
            a1[i]/=SQ_MOD;
            a2[i]%=SQ_MOD;
        }
        for ( int i=0; i<nb; i++ ) {
            b1[i]/=SQ_MOD;
            b2[i]%=SQ_MOD;
        }
        
        int nc=na+nb-1;
        auto c0=mul(a1,b1);
        auto c2=mul(a2,b2);
        for ( int i=0; i<na; i++ ) a1[i]+=a2[i];
        for ( int i=0; i<nb; i++ ) b1[i]+=b2[i];
        auto c1=mul(a1,b1);
        for ( int i=0; i<nc; i++ ) c1[i]=((c1[i]-c0[i]-c2[i])%MOD+MOD)%MOD;
        for ( int i=0; i<nc; i++ ) c0[i]=(c0[i]%MOD*SQ_MOD+c1[i])%MOD;
        for ( int i=0; i<nc; i++ ) c0[i]=(c0[i]%MOD*SQ_MOD+c2[i])%MOD;
        for ( int i=0; i<nc; i++ ) c[i]=c0[i];
    }

    template<typename T>
    vector<T> mul_mod( vector<T> a, vector<T> b ) {
		int na=a.size(),nb=b.size();
        assert(na==nb);
        vector<T> c(na+nb-1);
        mul_mod(na,a.data(),nb,b.data(),c.data());
		return c;
    }
};

using Mul::mul_mod;

int n,m,p;

struct XD {
    int q;
    vector<LL> v;
} tbl[20];

XD operator *( XD &a, XD &b ) {
    XD c{a.q*b.q%m,vector<LL>(m)};
    REP(i,m) c.v[i*b.q%m]=a.v[i];
    c.v=mul_mod(c.v,b.v);
    REP1(i,m,SZ(c.v)-1) {
        c.v[i-m]+=c.v[i];
        if ( c.v[i-m]>=MOD ) c.v[i-m]-=MOD;
    }
    c.v.resize(m);
    return c;
}

int main() {
    R(n,m,p);
    int lgn=0;
    while ( (1<<lgn)<=n ) lgn++;
    vector<LL> base(m);
    REP1(i,'A','Z') base[i%m]++;
    tbl[0]={p,base};
    REP(i,lgn-1) tbl[i+1]=tbl[i]*tbl[i];
    vector<LL> init(m);
    init[0]=1;
    XD s{1,init};
    REP(i,lgn) if ( (n>>i)&1 ) s=s*tbl[i];
    LL ans=0;
    REP(i,m) ans+=s.v[i]*(s.v[i]-1)*inv2%MOD;
    ans%=MOD;
    W(ans);
    return 0;
}
