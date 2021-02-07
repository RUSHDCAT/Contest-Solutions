#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

const double PI = acos(-1.0);
const double EPS = 1e-8;

inline int sgn(double x) {
    return (x > EPS) - (x < -EPS);
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    double angle() {
        return atan2(y, x);
    }
    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator * (double t) const {
        return Point(x * t, y * t);
    }
    Point operator / (double t) const {
        return Point(x / t, y / t);
    }
    double length() const {
        return sqrt(x * x + y * y);
    }
    Point unit() const {
        double l = length();
        return Point(x / l, y / l);
    }
};

double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double dist(const Point &p1, const Point &p2) {
    return (p1 - p2).length();
}

Point rotate(const Point &p, double angle, const Point &o = Point(0, 0)) {
    Point t = p - o;
    double x = t.x * cos(angle) - t.y * sin(angle);
    double y = t.y * cos(angle) + t.x * sin(angle);
    return Point(x, y) + o;
}

struct Region {
    double st, ed;
    Region() {}
    Region(double st, double ed): st(st), ed(ed) {}
    bool operator < (const Region &rhs) const {
        if(sgn(st - rhs.st)) return st < rhs.st;
        return ed < rhs.ed;
    }
};

struct Circle {
    Point c;
    double r;
    vector<Region> reg;
    Circle() {}
    Circle(Point c, double r): c(c), r(r) {}
    void read() {
        c.read();
        scanf("%lf", &r);
    }
    void add(const Region &r) {
        reg.push_back(r);
    }
    bool contain(const Circle &cir) const {
        return sgn(dist(cir.c, c) + cir.r - r) <= 0;
    }
    bool intersect(const Circle &cir) const {
        return sgn(dist(cir.c, c) - cir.r - r) < 0;
    }
};

double sqr(double x) {
    return x * x;
}

void intersection(const Circle &cir1, const Circle &cir2, Point &p1, Point &p2) {
    double l = dist(cir1.c, cir2.c);
    double d = (sqr(l) - sqr(cir2.r) + sqr(cir1.r)) / (2 * l);
    double d2 = sqrt(sqr(cir1.r) - sqr(d));
    Point mid = cir1.c + (cir2.c - cir1.c).unit() * d;
    Point v = rotate(cir2.c - cir1.c, PI / 2).unit() * d2;
    p1 = mid + v, p2 = mid - v;
}

Point calc(const Circle &cir, double angle) {
    Point p = Point(cir.c.x + cir.r, cir.c.y);
    return rotate(p, angle, cir.c);
}

const int MAXN = 1010;

Circle cir[MAXN];
bool del[MAXN];
int n;

double solve() {
    double ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) if(!del[j]) {
            if(i == j) continue;
            if(cir[j].contain(cir[i])) {
                del[i] = true;
                break;
            }
        }
    }
    for(int i = 0; i < n; ++i) if(!del[i]) {
        Circle &mc = cir[i];
        Point p1, p2;
        bool flag = false;
        for(int j = 0; j < n; ++j) if(!del[j]) {
            if(i == j) continue;
            if(!mc.intersect(cir[j])) continue;
            flag = true;
            intersection(mc, cir[j], p1, p2);
            double rs = (p2 - mc.c).angle(), rt = (p1 - mc.c).angle();
            if(sgn(rs) < 0) rs += 2 * PI;
            if(sgn(rt) < 0) rt += 2 * PI;
            if(sgn(rs - rt) > 0) mc.add(Region(rs, PI * 2)), mc.add(Region(0, rt));
            else mc.add(Region(rs, rt));
        }
        if(!flag) {
            ans += PI * sqr(mc.r);
            continue;
        }
        sort(mc.reg.begin(), mc.reg.end());
        int cnt = 1;
        for(int j = 1; j < int(mc.reg.size()); ++j) {
            if(sgn(mc.reg[cnt - 1].ed - mc.reg[j].st) >= 0) {
                mc.reg[cnt - 1].ed = max(mc.reg[cnt - 1].ed, mc.reg[j].ed);
            } else mc.reg[cnt++] = mc.reg[j];
        }
        mc.add(Region());
        mc.reg[cnt] = mc.reg[0];
        for(int j = 0; j < cnt; ++j) {
            p1 = calc(mc, mc.reg[j].ed);
            p2 = calc(mc, mc.reg[j + 1].st);
            ans += cross(p1, p2) / 2;
            double angle = mc.reg[j + 1].st - mc.reg[j].ed;
            if(sgn(angle) < 0) angle += 2 * PI;
            ans += 0.5 * sqr(mc.r) * (angle - sin(angle));
        }
    }
    return ans;
}
Point p[2002];

int main() {
    int a,b; scanf("%d%d",&a,&b);
    for(int i=0;i<a+b;i++){
        p[i].read();
    }

    double lef=0,rig=2e9;
    for(int x=1;x<50;x++){
        double mid=(lef+rig)/2;

        double s1=0,s2=0,s12=0;
         
        n=a; memset(del,0,sizeof(del));
        for(int i=0;i<a;i++) {
            cir[i].c = p[i]; cir[i].r = mid; cir[i].reg.clear();
        }
        s1=solve();

        n=b; memset(del,0,sizeof(del));
        for(int i=a;i<a+b;i++){
            cir[i-a].c = p[i]; cir[i-a].r = mid; cir[i-a].reg.clear();
        }
        s2 = solve();

        n=a+b; memset(del,0,sizeof(del));
        for(int i=0;i<a+b;i++){
            cir[i].c = p[i]; cir[i].r = mid; cir[i].reg.clear();
        }
        s12 = solve();
        //printf("mid=%.5f, (%.5f,%.5f,%.5f)\n", mid,s1,s2,s12);
        if(s12 - s2 > 1e-9) {
            lef = mid;
        } else {
            rig = mid;
        }
    }
    if(lef>=2e9-EPS) printf("-1\n"); 
    else printf("%.8f\n",lef);
}