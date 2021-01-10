#include <bits/stdc++.h>
using namespace std;
typedef __int128 LL;
LL gcd(LL x,LL y){
	if(x==0) return y;
	return gcd(y%x,x);
}
struct point{
	LL x,y;
	void unify(){
		LL d = gcd(x,y);
		x /= d, y /= d;
	}
	point(){}
	point(LL x,LL y):x(x),y(y){unify();}
	point operator * (LL b){
		LL d = gcd(b,y);
		return point(b/d*x,y/d);
	}
	point operator + (point p){
		return point(x * p.y + y * p.x, y * p.y);
	}
	point operator - (point p){
		return point(x * p.y - y * p.x, y * p.y);
	}
	point operator * (point p){
		return point(x * p.x, y * p.y);
	}
};
void print(LL x){
	if(x==0) printf("0");
	vector<int> v;
	while(x) v.push_back(x%10), x /= 10;
	reverse(v.begin(),v.end());
	for(int i: v) printf("%d",i);
}
int n;
LL dot(int a[],int b[]){
	LL ans = 0;
	for(int i=1;i<=n;i++) ans += (LL) a[i] * b[i];
	return ans;
}
const int N = 100000 + 10;
int a[N],b[N],c[N],d[N];
int R() {
	int x = rand()%200000 - 100000;
	printf("%d\n", x); 
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i]=R();
	for(int i=1;i<=n;i++) b[i]=R(), b[i] -= a[i];
	for(int i=1;i<=n;i++) c[i]=R();
	for(int i=1;i<=n;i++) d[i]=R(), d[i] -= c[i];
	LL A = dot(b,b), B = dot(b,d);
	LL C = dot(d,b), D = dot(d,d);
	LL X = dot(b,a) - dot(b,c), Y = dot(d,a) - dot(d,c);
	point x,y;
	LL det = A * D - B * C;
	if(det==0){
		x = point(X,A), y = point(0,1);
	}
	else{
		x = point(D*X-B*Y,det);
		y = point(A*Y-C*X,det);
	}
	point ans(0,1);
	for(int i=1;i<=n;i++){
		point dis = point(a[i]-c[i],1) - x * b[i] - y * d[i];
		ans = ans + dis * dis;
	}
	print(ans.x), printf("/"), print(ans.y), printf("\n");
}