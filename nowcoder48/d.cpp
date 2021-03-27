#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int f[20];
int g[20];

int main() {
	for (int i=1;i<=18;i++){
		int mid=(1+i)>>1;
		for(int j=1;j<=i;j++) f[i]+=abs(j-mid);
		f[i]+=1;
		printf("f[%d]=%d\n", i,f[i]);
	}
	g[1]=1;
	for(int i=2;i<=18;i++){
		g[i]=f[i];
		for(int j=1;j<i;j++){
			g[i]=max(g[i], g[j]*f[i-j]);
		}
		printf("g[%d]=%d\n", i,g[i]);
	}
	int s=0;
	for(int i=1;i<1<<18;i++){
		int c=0;
		for(int j=0;j<18;j++)if(i>>j&1)c++;
		s += pow(3,c);
	}
	cout<<s<<endl;
}