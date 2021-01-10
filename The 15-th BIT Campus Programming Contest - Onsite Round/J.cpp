#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const double eps = 1e-7;
int T,f[6];

double a[6][6],x[6];
void gauss(){
	for(int i=0;i<5;i++){
		if(abs(a[i][i]) > eps) {
			for(int j=i+1;j<5;j++){
				double k=a[j][i]/a[i][i];
				for(int x=0;x<6;x++)
					a[j][x] -= k * a[i][x];
			}
		}
	}
	for(int i=4;i>=0;i--){
		a[i][5]/=a[i][i];
		for(int j=i-1;j>=0;j--){
			a[j][5] -= a[j][i] * a[i][5];
		}
	}
	for(int i=0;i<5;i++) x[i]=a[i][5];
	//for(int i=0;i<5;i++)printf("%.5f ", x[i]);printf("\n");
}
int d[5];
bool done=0;
int cei(double x){
	if(x>0) return (int)(x+0.5);
	return -((int)(-x+0.5));
}
bool check(){
	for(int i=0;i<5;i++)if(x[i]<-100||x[i]>100||abs(cei(x[i])-x[i])>eps)return false;
	for(int i=0;i<5;i++)printf("%d ", cei(x[i]));printf("\n");
	return true;
}
void dfs(int dep){
	if(done)return;
	if(dep==5){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)a[i][j]=pow(i+1,j);
			a[i][5]=f[i]+d[i];
		}		
		gauss();
		if(check()){
			done=1;
		}
		return;
	}
	d[dep]=-1; dfs(dep+1);
	d[dep]=0;  dfs(dep+1);
	d[dep]=1;  dfs(dep+1);
}
int main() {
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<5;i++){
			scanf("%d",&f[i]);
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)a[i][j]=pow(i+1,j);
			a[i][5]=f[i];
		}
		done=0;
		dfs(0);
	}
}