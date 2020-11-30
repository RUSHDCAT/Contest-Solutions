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

const int N=1010;

struct P {
    int x,y;
} p[N];

P operator -( P a, P b ) { return {a.x-b.x,a.y-b.y}; }
bool operator <( P a, P b ) { return tie(a.x,a.y)<tie(b.x,b.y); }
int operator *( P a, P b ) { return a.x*b.y-b.x*a.y; }
int X( P o, P a, P b ) { return (a-o)*(b-o); }

ostream& operator <<( ostream &o, const P &x ) { return o<<"("<<x.x<<","<<x.y<<")"; }

int main() {
    int t;
    R(t);
    while ( t-- ) {
        int n;
        R(n);
        REP(i,n) R(p[i].x,p[i].y);
        sort(p,p+n);
        vector<P> q1,q2;
        REP(i,n) {
            while ( SZ(q1)>=2 && X(q1[q1.size()-2],q1.back(),p[i])>0 ) q1.pop_back();
            while ( SZ(q2)>=2 && X(q2[q2.size()-2],q2.back(),p[i])<0 ) q2.pop_back();
            q1.push_back(p[i]);
            q2.push_back(p[i]);
        }
        if ( SZ(q1)==n && SZ(q2)==n ) { // line
            W((n-1)%2==0?"OwO":"T^T");
        } else {
            int c=SZ(q1)+SZ(q2)-2;
            // dump(n,c);
            int e=3*n-3-c;
            // dump(q1,q2,e);
            W(e%2==0?"OwO":"T^T");
        }
    }
    return 0;
}

