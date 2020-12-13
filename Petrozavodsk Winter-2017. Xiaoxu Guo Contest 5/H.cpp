#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int p[N];
int gen(int n) {
	int c=0,r=0;
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		vector<int> v;
		for(int i=1;i<=n;i++)v.push_back(p[i]);
		for(int i=n;i>=1;i--)v.push_back(p[i]);
		int sz=v.size();
		bool ok=1;
		for(int i=0;i<sz;i++)for(int j=i+1;j<sz;j++)for(int k=j+1;k<sz;k++)for(int l=k+1;l<sz;l++)
			if(v[i]<v[k]&&v[k]<v[l]&&v[l]<v[j])ok=0;
		if(ok){
			//for(int i=1;i<=n;i++)printf("%d ",p[i]);
			//printf("\n");
			if(p[1] == n-1) c++;
			r++;
		}
	}while(next_permutation(p+1,p+1+n));
	//printf("n=%d,c=%d\n", n,c);
	return r;
}
int main() {
	
	for(int i=1;i<=9;i++) {
		printf("%d %d\n", i, gen(i));
		//gen(i);
	}
	return 0;
	int f[100]={0};
	f[1]=1,f[2]=2,f[3]=6;
	for(int i=4;i<=20;i++){
		for(int j=2;j<=i-3;j++) f[i]+=f[j];
		f[i]+=i;
		f[i]*=2;

		f[i]+=f[i-1];
		f[i]+=f[i-2];
		
		printf("%d %d\n", i,f[i]);
	}	


	for(int n=4;n<=10;n++){
		int x = f[n] - f[n-1] - f[n-2];
		int y = f[n+1] - f[n] - f[n-1];
		//printf("n=%d, y-x=%d\n", n,(y-x-2)/2);
		printf("# %d %d\n", f[n], 2 + f[n-3] + 2 * f[n-1]);

	}

	int g[100]={0};
	g[1]=1,g[2]=2,g[3]=6;g[4]=16;
	for(int i=5;i<=12;i++){
		g[i]=2*g[i-1]+g[i-3]+2;
		printf("g[%d] = %d\n", i,g[i]);
	}

}