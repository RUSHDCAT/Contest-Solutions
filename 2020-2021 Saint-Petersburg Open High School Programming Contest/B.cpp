#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 600000 + 10;

int main() {
	int n,L; 
	scanf("%d%d",&n,&L);
	vector<int> x(2*n,0);
	for(int i=0;i<n;i++) 
		scanf("%d",&x[i]);

	sort(x.begin(),x.begin()+n);
	for(int i=n;i<2*n;i++) x[i]=x[i-n]+L;
	int d=(L-1)/2;
	
	int j=n-1;
	while(j>=0 && x[n]-x[j]<=d) --j;
	LL cnt=0;
	//for(int i=0;i<2*n;i++) printf("%d ", x[i]); printf("\n");
	for(int i=n;i<2*n;i++) {
		while(x[i]-x[j]>d) ++j;
		int len=i-j+1;
		//printf("i=%d,j=%d\n", i,j);
		if(len>=3){
			cnt += 1LL*(len-2)*(len-1)/2;
		}
	}
	LL tot=1LL*n*(n-1)*(n-2)/6;
	LL ans=tot-cnt;
	cout<<ans<<endl;
}