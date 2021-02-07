#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
LL h,a,b,c,va,vb,vc;
double get(double x1,double x2){
	return sqrt(a*a+x1*x1)/va + sqrt(b*b+(x2-x1)*(x2-x1))/vb + sqrt(c*c+(h-x2)*(h-x2))/vc;
}
double p = (sqrt(5)-1)/2;
double solve(double x1) {
	double l=x1,r=h;
	for(int i=1;i<=20;i++){
		double mr=l+(r-l)*p;
		double ml=r-(r-l)*p;
		if((r-l)<1e-5)break;
		if(get(x1,ml)<get(x1,mr)){
			r=mr;
		}else{
			l=ml;
		}
	}
	return get(x1,l);
}

double solve(){
	double l=0,r=h;
	for(int i=1;i<=20;i++){
		double mr=l+(r-l)*p;
		double ml=r-(r-l)*p;
		if((r-l)<1e-5)break;
		if(solve(ml)<solve(mr)){
			r=mr;
		}else{
			l=ml;
		}
	}	
	return solve(l);
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld%lld",&h,&a,&b,&c,&va,&vb,&vc);
		printf("%.8f\n",solve());
	}
}