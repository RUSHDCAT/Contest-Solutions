#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1000000 + 10;

LL gcd(LL x, LL y) {
	return y==0?x:gcd(y,x%y);
}
LL exgcd(const LL a, const LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL xx, yy, g = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;
    return g;
}
LL inv(const LL a, const LL p)
{
    LL x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

LL n, m, k;
LL a[N], b[N], pa[N], pb[N];

namespace Dog {
	LL A, B, g, aa, bb;
	LL iv;
	void init() {
		A = n, B = m;
		g = gcd(A, B); bb = B / g;
		LL aa = A / g, bb = B / g;
		iv = inv(aa, bb);
	}
}
LL xx[N];

LL cal(LL C, LL P) {
	LL g = Dog::g;
	if (P % g) return 0;
	LL ans = 0;
	if (xx[P] > C) ans = 0;
	else ans = 1 + (C - xx[P]) / Dog::bb;
	return ans;	
}

vector< pair<int,int> > mem; 
bool check(LL x) {
	LL ans=x;
	for(auto p: mem){
		LL C = (x-1-p.first)/n;
		ans -= cal(C, p.second);
	}
	return ans >= k;
}	
int main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	Dog::init();
	for(int i=0;i<m;i++){
		LL g=Dog::g;
		if(i%g==0) {
			LL pp=i/g;
			xx[i] = 1LL * pp * Dog::iv % Dog::bb;
		}
	}
	for(int i=0;i<=1000000;i++)pa[i]=pb[i]=-1;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]); 
		pa[a[i]] = i;
	}
	for(int i=0;i<m;i++){
		scanf("%lld",&b[i]); 
		pb[b[i]] = i;
	}
	for(int i=0;i<n;i++){
		if(pb[a[i]]!=-1){
			pair<int,int> tmp; tmp.first=i; tmp.second=((pb[a[i]]-i)%m+m)%m;
			mem.push_back(tmp);
		}
	}
	LL rig=1e18, lef=k-1;
	while (rig-lef>1) {
		LL mid=(rig+lef)>>1;
		if(check(mid)){
			rig=mid;
		}else{
			lef=mid;
		}
	}
	printf("%lld\n", rig);
}