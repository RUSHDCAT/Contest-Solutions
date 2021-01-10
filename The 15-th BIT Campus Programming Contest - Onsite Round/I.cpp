#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,t;
int x[N],y[N];
int main() {
	scanf("%d%d",&n,&t);
	int done=0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]<y[i]) done++;
		else v.push_back((x[i]-y[i]+1)/2);
	}
	int need = (n+1)/2 - done;
	if(need <= 0) printf("Make Byteland Great Again!\n");
	else {
		sort(v.begin(),v.end());
		for(int i=0;i<need;i++) t-=v[i];
		printf("%s\n", t>=0?"Make Byteland Great Again!":"Fake Polls!");
	}
}