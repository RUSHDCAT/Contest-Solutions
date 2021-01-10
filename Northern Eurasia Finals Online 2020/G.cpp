#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long double LD;
const int N = 2000000 + 10;
const LD EPS = 1e-7;
const LD INF = 1e12;
int sgn(LD x) {
    if (x < -EPS) return -1;
    if (x > +EPS) return +1;
    return 0;
}
struct Vec {
    LD x,y;
    Vec() {}
    Vec(LD x, LD y) { 
        this->x = x, this->y = y; 
    }
    void read() { 
        scanf("%Lf %Lf", &x, &y); 
    }
    void prt() {
        printf("%.8Lf %.8Lf\n", x, y); 
    }
    LD len() { 
        return sqrt(x * x + y * y); 
    }
    LD len2() { 
        return x * x + y * y; 
    }
    bool operator <(const Vec& o)const {
        if(x == o.x)
            return y < o.y;
        return x < o.x;
    }
    Vec trans() {
    	return Vec((y-x)/2, (y+x)/2);
    }
 
};
 
typedef long long LL;
const LL MOD = 1e9 + 7;
LL fac[N],inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int cei(LD x) {
	if (abs(x - (int)x) < EPS) return (int)(x);
	return (int)x + 1;
}
int solve(int i, LD y_1, LD y_2) {
	if(y_1 > y_2) swap(y_1, y_2);
 
	y_1 = max(y_1, (LD)0.0);
 	if (y_2 < 0) return 0;
	int l = cei(y_1), r = (int)y_2;
	if(l>r)return 0;
	int ans = c(r+i+1, r) - (l>=1?c(l-1+i+1,l-1):0);
	return (ans % MOD + MOD) % MOD;
}
 
int t;
Vec p[3];
 
LD gety(Vec A, Vec B, LD pos) {
	return A.y + (pos - A.x) * (B.y - A.y) / (B.x - A.x);
}
 
int main() {
	// printf("%d\n", (int)(-0.1));
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}
 
	scanf("%d",&t);
	while(t--) {
		p[0].read(); p[1].read(); p[2].read();
		for(int i=0;i<3;i++) p[i]=p[i].trans();
		sort(p,p+3);
		LL ans=0;
		for(int i=0;i<=1000000;i++){
			if(i >= p[0].x - EPS && i <= p[2].x + EPS) {
				LD y_1, y_2;
				if (abs(p[0].x - p[1].x) < EPS && abs(i - p[0].x) < EPS) {
					y_1 = p[0].y;
					y_2 = p[1].y;
				} else if (abs(p[2].x - p[1].x) < EPS && abs(i - p[1].x) < EPS) {
					y_1 = p[1].y;
					y_2 = p[2].y;
				}else{
					y_1 = gety(p[0], p[2], i);
					if (i <= p[1].x) {
						y_2 = gety(p[0], p[1], i);
					}else{
						y_2 = gety(p[1], p[2], i);
					}
				}
				ans = (ans + solve(i,y_1,y_2)) % MOD;
			}
		}
		printf("%lld\n",ans);
	}
}
