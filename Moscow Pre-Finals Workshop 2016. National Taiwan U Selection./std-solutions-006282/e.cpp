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

const int N=1e7+10;

bitset<N> p_tbl;
vector<int> primes;
int mu[N],smu[N];
void sieve() {
    mu[1]=p_tbl[1]=1;
    for ( int i=2; i<N; i++ ) {
        if ( !p_tbl[i] ) {
            primes.push_back(i);
            mu[i]=-1;
        }
        for ( int p:primes ) {
            int x=i*p;
            if ( x>=N ) break;
            p_tbl[x]=1;
            mu[x]=-mu[i];
            if ( i%p==0 ) {
                mu[x]=0;
                break;
            }
        }
    }
    REP1(i,1,N-1) smu[i]=smu[i-1]+(i%2==1?mu[i]:0);
}

LL sum( LL n ) {
    return n*(n+1)/2;
}

LL f( int n, int m ) {
    assert(n<=m);
    LL ans=0;
    LL g=max(n-m/2,0);
    ans+=(m+2)/4*g;
    if ( m/2%2==1 ) ans-=(g+1)/2;
    ans-=2*sum(g/2);
    if ( g%2==0 ) ans+=g/2;
    ans+=sum((n-1)/2-g);
    return ans;
}

LL solve( int n, int m ) {
    if ( n>m ) swap(n,m);
    if ( n==1 && m==1 ) return 1;
    LL ans=0;
    for ( int i=1,j; i<=n; i=j+1 ) {
        j=min(n/(n/i),m/(m/i));
        ans+=(smu[j]-smu[i-1])*f(n/i,m/i);
    }
    return ans;
}

int main() {
    sieve();
    int t;
    R(t);
    while ( t-- ) {
        int n,m;
        R(n,m);
        LL ans=solve(n,m);
        W(ans);
    }
    return 0;
}
