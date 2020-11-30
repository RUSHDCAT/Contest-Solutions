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

bool can( VI l ) {
    int s=0;
    for ( int i:l ) s+=i;

    int max_even=0;
    for ( int i:l ) {
        if ( i==1 ) max_even++;
        else max_even+=i/2;
    }

    return s/2<=max_even;
}

int main() {
    int t;
    R(t); while ( getchar()!='\n' );
    while ( t-- ) {
        int n=0,l[4];
        char buf[100];
        fgets(buf,sizeof(buf),stdin);
        for ( char *p=strtok(buf," "); p; p=strtok(NULL," ") ) sscanf(p,"%d",&l[n++]);
        REP(i,n-1) assert(l[i]<=l[i+1]);

        int s=0;
        REP(i,n) s+=l[i];

        int max_even=0;
        REP(i,n) {
            if ( l[i]==1 ) max_even++;
            else max_even+=l[i]/2;
        }
        if ( s/2>max_even ) {
            puts("QQ");
            continue;
        }


        VI sol[4];

        int ori_n=n;
        while ( 1 ) {
            bool found=0;
            REP(i,n) if ( l[i]==1 || __gcd(s-l[i]+1,s)==1 ) {
                VI v;
                REP(j,n) if ( i!=j ) v.PB(l[j]);
                if ( !can(v) ) continue;
                found=1;
                REP(j,l[i]) sol[i].PB(s--);
                swap(l[i],l[n-1]);
                swap(sol[i],sol[n-1]);
                n--;
                break;
            }
            if ( !found ) break;
        }
        sort(l,l+n);

        auto go=[&]( VI ord ) {
            int last=0;
            REP(i,n) if ( !sol[i].empty() ) last=max(last,sol[i].back());
            for ( int i:ord ) {
                while ( SZ(sol[i])<l[i] ) sol[i].PB(++last);
            }
        };

        if ( n==1 ) {
            go({0});
        } else if ( n==2 ) {
            if ( l[1]%2==1 ) swap(l[0],l[1]);
            sol[0]={1};
            go({1,0});
        } else if ( n==3 ) {
            if ( l[0]==1 && l[1]%2==1 && l[2]%2==1 ) {
                sol[1]={1};
                REP(i,l[2]-1) sol[2].PB(2+i);
                sol[0].PB(sol[2].back()+1);
                sol[2].PB(sol[2].back()+2);
                go({1});
            } else {
                REP(i,n) if ( l[i]%2==1 ) swap(l[0],l[i]);
                int cnt_r1=0;
                REP1(i,1,n-1) if ( l[i]%3==1 ) cnt_r1++;
                if ( cnt_r1==n-1 ) {
                    if ( l[1]==4 ) {
                        sol[0]={1};
                        sol[1]={2,3,8,9};
                        sol[2]={4,5,6,7};
                    } else {
                        sol[0]={1};
                        sol[1]={2,5,6,7,8};
                        sol[2]={3,4};
                    }
                    go({2,1,0});
                } else {
                    REP1(i,1,n-1) if ( l[i]%3==1 ) swap(l[i],l[1]);
                    sol[0]={1};
                    sol[1]={2};
                    sol[2]={3};
                    go({2,1,0});
                }
            }
        } else if ( n==4 ) {
            if ( l[0]==1 && (l[1]%2+l[2]%2+l[3]%2)==2 ) {
                REP1(i,1,3) if ( l[i]%2==1 ) swap(l[1],l[i]);
                if ( l[2]%2!=1 ) swap(l[2],l[3]);
                sol[1]={1};
                sol[2]={2,3};
                sol[3]={4};
                go({2,0,3,1});
            } else {
                REP(i,n) if ( l[i]%2==1 ) swap(l[0],l[i]);
                int cnt_r2=0;
                REP1(i,1,n-1) if ( l[i]%3==2 ) cnt_r2++;

                if ( cnt_r2==n-1 ) {
                    sol[0]={1};
                    sol[1]={2,9};
                    sol[2]={3,8};
                    sol[3]={4,5,6,7};
                    int x=10;
                    while ( SZ(sol[3])<l[3] ) sol[3].PB(x++);
                    while ( SZ(sol[1])<l[1] ) sol[1].PB(x++);
                    while ( SZ(sol[2])<l[2] ) sol[2].PB(x++);
                    reverse(sol[2].begin()+2,sol[2].end());
                    while ( SZ(sol[0])<l[0] ) sol[0].PB(x++);
                } else {
                    while ( l[3]%3==2 || (l[2]+l[3])%3==1 ) next_permutation(l+1,l+n);
                    sol[0]={1};
                    sol[1]={2};
                    sol[2]={3};
                    sol[3]={4};
                    go({3,2,1,0});
                }
            }
        }

        n=ori_n;
        REP(i,n) REP(j,n-1) if ( l[j]>l[j+1] ) {
            swap(l[j],l[j+1]);
            swap(sol[j],sol[j+1]);
        }

        // dump(n,VI(l,l+n));
        // REP(i,n) dump(i,sol[i]);

        REP(i,n) {
            assert(SZ(sol[i])==l[i]);
            if ( l[i]>1 ) REP(j,l[i]) assert(__gcd(sol[i][j],sol[i][(j+1)%l[i]])==1);
        }

        puts("^_<");
        REP(i,n) W(sol[i]);
    }
    return 0;
}

