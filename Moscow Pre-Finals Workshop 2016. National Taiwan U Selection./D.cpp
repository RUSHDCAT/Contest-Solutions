#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1000 + 10;
const double EPS = 1e-9;
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
bool cmpang(Vec A, Vec B) {
    if ((A ^ B) == 0) {
        return A < B;
    }
    return (A ^ B) > 0;
}


vector<Vec> convexHull(vector<Vec> v) {
    sort(v.begin(), v.end());
    vector<Vec> ans; ans.resize(2*v.size());
    int top = 0, n = v.size();
    if(n <= 1) return v;

    for(int i = 0; i < n; ans[top++] = v[i++]) {
        while (top > 1 && ((ans[top-1] - ans[top-2]) ^ (v[i] - ans[top-1])) < -EPS) -- top;
    }
    for(int i = n-2, t = top; i >= 0; ans[top++] = v[i--]) {
        while (top > t && ((ans[top-1] - ans[top-2]) ^ (v[i] - ans[top-1])) < -EPS) -- top;
    } 
    while(ans.size() >= top) ans.pop_back();
    return ans;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		vector<Vec> v;
		int n; scanf("%d", &n);

		for(int i=1;i<=n;i++) {
			Vec p; p.read();
			v.push_back(p);
		}
		if(n==1) {
			printf("OwO\n"); continue;
		}
		bool ok = 1;
		for(int i=1;i<n;i++){
			if(abs((v[1] - v[0]) ^ (v[i] - v[0])) > EPS) ok = 0;
		}
		if (ok) {
			printf("%s\n", n%2==0?"T^T":"OwO"); continue;
		}
		int c = convexHull(v).size();
		int k2 = (3 * n - 3) % 2;
		int k1 = c % 2;
		printf("%s\n", (k1+k2)%2?"T^T":"OwO");
	}
}