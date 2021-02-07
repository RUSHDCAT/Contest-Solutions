#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1) {
			printf("1 1 1 2\n");
		} else if(n==2) {
			printf("1 1 1 2\n");
			printf("1 3 1 4\n");
			printf("1 5 1 6\n");
		} else if(n==3) {
			printf("1 1 1 2\n");
			printf("2 1 2 2\n");
			printf("3 1 3 2\n");
			printf("2 3 3 3\n");
			printf("4 3 4 2\n");
			printf("5 2 6 2\n");
		} else if (n==4) {
			printf("1 1 1 2\n");
			printf("2 1 2 2\n");
			printf("3 1 3 2\n");
			printf("2 3 3 3\n");
			printf("4 3 4 2\n");
			printf("5 2 6 2\n");
		} else {
			printf("impossible\n");
		}
	}
}