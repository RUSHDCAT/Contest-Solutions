#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int t,n,x[N],y[N];
double X,Y;
double get(double a, double b){
	double sum=0;
	for(int i=1;i<=n;i++){
		sum += sqrt( (a-x[i])*(a-x[i]) + (b-y[i])*(b-y[i]) );
	}
	return sum;
}
double solve(double x_) {
	double l=-1e6,r=1e6;
	for(int i=1;i<=100;i++){
		double ml=(l+r)/2;
		double mr=(ml+r)/2;
		double sl = get(x_, ml);
		double sr = get(x_, mr);
		if (sl < sr) {
			r = mr;
		}else{
			l = ml;
		}
	}
	Y=l; 
	return get(x_, l);
}
double solve() {
	double l=-1e6,r=1e6;
	for(int i=1;i<=100;i++){
		double ml=(l+r)/2;
		double mr=(ml+r)/2;
		if(solve(ml)<solve(mr)){
			r=mr;
		}else{
			l=ml;
		}
	}
	X=l;
	return l;
}

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		solve();
		printf("%.8f %.8f\n", X,Y);
	}	
}