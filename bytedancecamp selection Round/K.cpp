#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int T,n;
char s[N],t[N];
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,s+1,t+1);
		int a=0,b=0;
		for(int i=1;i<=n;i++){
			if(s[i]>t[i])a++;else if(s[i]<t[i]) b++;
		}
		if(a>b) printf("RED\n");
		else if(a<b) printf("BLUE\n");
		else printf("EQUAL\n");
	}
}