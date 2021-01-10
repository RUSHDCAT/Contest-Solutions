#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 300 + 10;
const double EPS = 1e-7;
const double INF = 1e12;
int sgn(double x) {
    if (x < -EPS) return -1;
    if (x > +EPS) return +1;
    return 0;
}
struct Vec {
    double x,y;
    Vec() {}
    Vec(double x, double y) { 
        this->x = x, this->y = y; 
    }
    void read() { 
        scanf("%lf %lf", &x, &y); 
    }
    void prt() {
        printf("%.8f %.8f\n", x, y); 
    }
    double len() { 
        return sqrt(x * x + y * y); 
    }
    double len2() { 
        return x * x + y * y; 
    }
    bool operator <(const Vec& o)const {
        if(x == o.x)
            return y < o.y;
        return x < o.x;
    }
    Vec operator +(const Vec& o)const { 
        return Vec(x + o.x, y + o.y); 
    }
    Vec operator -(const Vec& o)const { 
        return Vec(x - o.x, y - o.y); 
    }
    Vec operator *(const double& k)const { 
        return Vec(k * x, k * y); 
    }
    double operator *(const Vec& o)const {
        return x * o.x + y * o.y; 
    }
    double operator ^(const Vec& o)const {
        return x * o.y - y * o.x; 
    }
    Vec rotate(double ang){ 
        return Vec(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); 
    }
    Vec change(double l) { 
        if(len() < EPS) return *this; 
        return (*this) * (l/len()); 
    }
};

struct Line {
    Vec A1, A2;
    Line() {}
    Line(Vec A1, Vec A2) {
        this->A1 = A1, this->A2 = A2;
    }
    double len() {
        return (A2-A1).len();
    }
    double Len2() {
        return (A2-A1).len2();
    }
    double getAng() const {
        return atan2(A2.y-A1.y, A2.x-A1.x);
    }
    void prt() {
        printf("(%.5f %.5f) - (%.5f %.5f) %.7f\n", A1.x,A1.y,A2.x,A2.y,(*this).getAng());
    }
    bool operator <(const Line& o)const {
        Line l = o;
        double A = (*this).getAng();
        double B = l.getAng();
        if (abs(A-B) < EPS)
            return ((A2-A1)^(l.A1-A1)) > EPS;
        return A < B;
    }   
};

double disToLine(Vec P, Line L) {
    return abs((P-L.A1)^(L.A2-L.A1)) / L.len();
}
bool onseg(Vec P, Line L) {
    if(disToLine(P, L) > EPS) return 0;
    return (P-L.A1) * (P-L.A2) < -EPS;
}
Vec Lineintersect(Line L1, Line L2) {
    // 0 ~ (L2.A1 - L1.A1) ^ (L2.A2 - L1.A1);
    // 1 ~ (L2.A1 - L1.A2) ^ (L2.A2 - L1.A2);
    double F0 = (L2.A1 - L1.A1) ^ (L2.A2 - L1.A1);
    double F1 = (L2.A1 - L1.A2) ^ (L2.A2 - L1.A2);
    if (abs(F1 - F0) < EPS) return Vec(INF, INF);
    return L1.A1 + (L1.A2 - L1.A1) * (- F0 / (F1 - F0));
}
Vec Segintersect(Line L1, Line L2) {
    Vec P = Lineintersect(L1, L2);
    if (P.x == INF) return P;
    if (onseg(P, L1) && onseg(P, L2)) return P;
    return Vec(INF, INF);
}


vector<Vec> convexHull(vector<Vec> v) {
    sort(v.begin(), v.end());
    vector<Vec> ans; ans.resize(2*v.size());
    int top = 0, n = v.size();
    if(n <= 1) return v;

    for(int i = 0; i < n; ans[top++] = v[i++]) {
        while (top > 1 && ((ans[top-1] - ans[top-2]) ^ (v[i] - ans[top-1])) < EPS) -- top;
    }
    for(int i = n-2, t = top; i >= 0; ans[top++] = v[i--]) {
        while (top > t && ((ans[top-1] - ans[top-2]) ^ (v[i] - ans[top-1])) < EPS) -- top;
    } 
    while(ans.size() >= top) ans.pop_back();
    return ans;
}

int n;
Vec points[N];

bool ban[N][N];
void upd(int x,int y) {
    //printf("upd %d %d\n", x, y);
    if(x>y) swap(x,y);
    ban[x][y] = true;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ban[i][j] == true) continue;
            if(Segintersect(Line(points[x], points[y]), Line(points[i], points[j])).x != INF) {
                ban[i][j] = 1;
                //printf("! %d %d\n", i, j);
            }
        }
    }
}
void read() {
    int x,y; scanf("%d%d",&x,&y); 
    if(x==0 && y==0) exit(0);
    upd(x,y);
}
void doit(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ban[i][j] == true) continue;
            printf("%d %d\n", i,j); fflush(stdout);
            upd(i,j); return;
        }
    }    
}
int main() {
    scanf("%d", &n);
    vector<Vec> v;
    for(int i=1;i<=n;i++) {
        points[i].read(); v.push_back(points[i]);
    }

    int c1 = convexHull(v).size();
    int e = 3 * n - c1 - 3;
    if (e % 2 == 1) {
        printf("1\n"); fflush(stdout);
        while(true) {
            doit(); read();
        }
    } else {
        printf("2\n"); fflush(stdout);
        while(true) {
            read(); doit();
        }       
    }


}

