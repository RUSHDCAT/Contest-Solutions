#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t1,v1,t2,v2;
int main() {
	scanf("%d%d%d%d",&t1,&v1,&t2,&v2);
	if(t2<0 && v2>=10) printf("A storm warning for tomorrow! Be careful and stay home if possible!\n");
	else if(t2 < t1) printf("MCHS warns! Low temperature is expected tomorrow.\n");
	else if(v2 > v1) printf("MCHS warns! Strong wind is expected tomorrow.\n");
	else printf("No message\n");
} _