#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
char s[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s);
		sort(s,s+n);
		printf("%s\n", s);
	}
}