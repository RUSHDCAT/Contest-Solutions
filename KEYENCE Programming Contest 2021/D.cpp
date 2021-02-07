#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	bool ok[20]={0};
	for(int i=0;i<16;)
	for(int i=0;i<1<<16;i++){
		int f[5][5]={0};
		int c=0;
		for(int j=0;j<16;j++)if(i>>j&1)c++;
		if(c!=8)continue;
		for(int j=0;j<16;j++)if(i>>j){
			for(int x=0;x<4;x++)for(int y=x+1;y<4;y++){
				if((j>>x&1) && (j>>y&1)) f[x][y]++;
			}
		}
		bool ok=1;
		for(int j=0;j<4;j++)for(int k=j+1;k<4;k++)if(f[j][k]!=3)ok=0;
		if(ok) {
			for(int j=0;j<16;j++)if(i>>j&1)printf("# %d\n", j);
			return 0;
		}
	}	
}