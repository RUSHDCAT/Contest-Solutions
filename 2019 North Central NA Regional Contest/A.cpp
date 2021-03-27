#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int maxn=1e6+6;
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	Point operator + (Point v){
		return Point(x+v.x,y+v.y);
	}
	Point operator - (Point v){
		return Point(x-v.x,y-v.y);
	}
	Point operator * (double d){
		return Point (x*d,y*d);
	}
	Point operator / (double d){
		return Point (x/d,y/d);
	}
}Dots[maxn];
typedef Point Vector;
struct Circle
{
	double r;
	Point centre;
	Circle(Point centre1=Point(0,0),double r1=0)
	{
		centre=centre1;
		r=r1;
	}
}ansC;
struct Triangle
{
	Point p[3];
};
double cross(Vector a,Vector b)
{
	return (a.x*b.y-a.y*b.x);
}
double TriangleArea(Triangle t)
{
	return fabs(cross(t.p[1]-t.p[0],t.p[2]-t.p[0]))/2.0;
}
double Distance(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Circle CircumCircleofTriangle(Triangle t)
{
	Circle tmp;
	double a,b,c,c1,c2;
	double xa,ya,xb,yb,xc,yc;
	a=Distance(t.p[0],t.p[1]);
	b=Distance(t.p[1],t.p[2]);
	c=Distance(t.p[2],t.p[0]);
	tmp.r=a*b*c/TriangleArea(t)/4.0;
	xa=t.p[0].x;
	ya=t.p[0].y;
	xb=t.p[1].x;
	yb=t.p[1].y;
	xc=t.p[2].x;
	yc=t.p[2].y;
	c1=(xa*xa+ya*ya-xb*xb-yb*yb)/2.0;
	c2=(xa*xa+ya*ya-xc*xc-yc*yc)/2.0;
	tmp.centre.x=(c1*(ya-yc)-c2*(ya-yb))/((xa-xb)*(ya-yc)-(xa-xc)*(ya-yb));
	tmp.centre.y=(c1*(xa-xc)-c2*(xa-xb))/((ya-yb)*(xa-xc)-(ya-yc)*(xa-xb));
	return tmp;
}
Circle MinCircle2(int u,Triangle t)
{
	if(u==0) return Circle(Point(0,0),-2.0);
	else if(u==1) return Circle(t.p[0],0);
	else if(u==2) return Circle(Point((t.p[0].x+t.p[1].x)/2.0,(t.p[0].y+t.p[1].y)/2.0),Distance(t.p[0],t.p[1])/2.0);
	else if(u==3) return CircumCircleofTriangle(t); 
} 
void MinCircle(int n,int u,Triangle t)
{
	ansC=MinCircle2(u,t);
	if(u==3) return;
	for(int i=1;i<=n;i++)
	{
		if(Distance(Dots[i],ansC.centre)>ansC.r){
			t.p[u]=Dots[i];
			MinCircle(i-1,u+1,t);
			Point temp=Dots[i];
			for(int j=i;j>=2;j--)
			{
				Dots[j]=Dots[j-1];
			}
			Dots[1]=temp;
		}
	}
}


int n;
double x[N], y[N], z[N];


double solve(double xx[], double yy[]) {
	for(int i=1;i<=n;i++)
	{
		Dots[i].x = xx[i], Dots[i].y = yy[i];
	}
	Triangle t;
	MinCircle(n,0,t);
	return ansC.r;
}

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
	}	
	double ans = min(min(solve(x, y), solve(y,z)), solve(x,z));
	printf("%.9f\n", ans * 2);

}