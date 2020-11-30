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

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

const int N=1e5+10;

struct Trie {
    int sz;
    Trie *c[2];
    static Trie mem[30*N],*pmem;
    void ins( int x, int v, int p=29 ) {
        sz+=v;
        if ( p<0 ) return;
        auto &ch=c[bit(x,p)];
        if ( !ch ) ch=new (pmem++) Trie();
        ch->ins(x,v,p-1);
    }
    int ask( int x, int p=29 ) {
        assert(sz>0);
        if ( p<0 ) return 0;
        int b=bit(x,p);
        if ( !c[b] || c[b]->sz==0 ) b^=1;
        return (b<<p)|c[b]->ask(x,p-1);
    }
} Trie::mem[30*N],*Trie::pmem=mem;

struct E {
    int a,b,c;
};

int n,a[N],g[N];
VI v[N];

void merge( int x, int y ) {
    if ( SZ(v[x])>SZ(v[y]) ) swap(x,y);
    v[y].insert(v[y].end(),ALL(v[x]));
    for ( int i:v[x] ) g[i]=y;
    v[x].clear();
}

int main() {
    R(n);
    REP(i,n) R(a[i]);
    sort(a,a+n);
    n=unique(a,a+n)-a;
    auto trie=new Trie();
    REP(i,n) trie->ins(a[i],+1);
    REP(i,n) v[i].PB(i);
    REP(i,n) g[i]=i;
    LL ans=0;
    int rem=n;
    while ( rem>1 ) {
        vector<E> tom;
        REP(i,n) if ( !v[i].empty() ) {
            for ( int j:v[i] ) trie->ins(a[j],-1);
            int mi=-1,x=-1,y=-1;
            for ( int j:v[i] ) {
                int ak=trie->ask(a[j]);
                int k=lower_bound(a,a+n,ak)-a;
                int now=a[j]^ak;
                // dump(j,k,a[j],a[k],now);
                if ( mi==-1 || now<mi ) tie(mi,x,y)=tie(now,j,k);
            }
            tom.PB({x,y,mi});
            for ( int j:v[i] ) trie->ins(a[j],+1);
        }
        for ( auto j:tom ) {
            int x=g[j.a],y=g[j.b];
            if ( x==y ) continue;
            // dump(j.a,j.b,j.c);
            ans+=j.c;
            merge(x,y);
            rem--;
        }
    }
    W(ans);
    return 0;
}

