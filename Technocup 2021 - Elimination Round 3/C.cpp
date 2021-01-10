#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n;
LL T, pw[N];
char s[N];

int main() {
	pw[0]=1; for(int i=1;i<=27;i++) pw[i]=pw[i-1]*2;
	scanf("%d%lld%s",&n,&T,s+1);
	// printf("# %lld\n", pw[s[n] - 'a']);
	T -= pw[s[n] - 'a'];
	T += pw[s[n-1] - 'a'];

	int c[26] = {0};
	LL sum = 0;
	for(int i=1;i<n-1;i++){
		c[s[i] - 'a'] ++; sum += pw[s[i] - 'a'];
	}
	T += sum;
	//printf("sum = %lld, T = %lld\n", sum, T);
	if (T < 0) {
		return !printf("No\n");
	}
	for(int i=25;i>=0;i--){
		LL val = pw[i+1];
		LL cnt = min(T / val, 1LL * c[i]);
		T -= cnt * val;
	}
	printf("%s\n", T==0?"Yes":"No");
}