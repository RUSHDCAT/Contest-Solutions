#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int k, a[N], n, m;
void chk(int l,int r){
	vector<bool> ok(k+2);
	for(int i=1;i<=k+1;i++) ok[i]=0;
	for(int i=l;i<=r;i++){
		for(int j=i+1;j<=r;j++){
			int x=a[i],y=a[j];
			printf("c %d %d\n", x,y); fflush(stdout);
			char s[6]; scanf("%s",s);	
			if(s[0]=='y') {
				ok[i]=ok[j]=1;
				//printf("win %d %d\n", l,r);
			}			
		}
	}
	for(int i=l;i<=r;i++)if(!ok[i]){
		printf("! %d\n", a[i]); fflush(stdout); exit(0);
	}
}
int main() {
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+k);

	for(int p=3;p<=k;p++) {
		int val=p-1;
		if((k-1)%val && (k-1)%(val-1))continue;
		int x=a[1],y=a[p];
		printf("r %d %d\n", x,y); fflush(stdout);
		char s[6]; scanf("%s",s);
		if(s[0]=='y'){
			n=p-1,m=(k-1)/n; break;
		}
	}

	if(n==0) {
		printf("! %d\n", a[1]); fflush(stdout);
	}
	
	for(int i=1;i+n<=k;i+=n){
		int x=a[i], y=a[i+n];
		printf("r %d %d\n", x,y); fflush(stdout);
		char s[6]; scanf("%s",s);
		if(s[0]=='n') {
			chk(i,i+n);
			break;
		}
	}
	chk(k-n,k);
}