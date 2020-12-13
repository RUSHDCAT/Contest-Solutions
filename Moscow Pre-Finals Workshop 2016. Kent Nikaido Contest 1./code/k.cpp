#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,a[N];
int main() {
	scanf("%d",&n);
	int sum=0,mn=1e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); sum+=a[i];
		mn=min(mn,a[i]);
	}
	if(n%2==1){
		if(sum%2==1) printf("Iori\n"); else printf("Yayoi\n");
	}else{
		if(mn==1) printf("Iori\n");
		else {
			if(mn%2==1) {
				printf("%s\n", "Iori");
			}else{
				printf("%s\n", sum%2==1?"Iori":"Yayoi" );
			}
		}
	}
}