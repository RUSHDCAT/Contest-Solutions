#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n;
char s[N], t[N];
int f(int x){
	int y=0;
	for(int i=1;i<=x;i++) y^=i;
	return y;
}
int main() {

	
	for(int i=1;i<=100;i++){
		printf("%d %d\n", i,f(i));
	}
	
	//scanf("%d%s%s", &n,s+1,t+1);
}