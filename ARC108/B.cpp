#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n; 
char s[N];
char stk[N]; int tot;
int main() {
	scanf("%d%s",&n,s+1);
	int ans = n;
	for(int i=1;i<=n;i++) {
		if(s[i]=='f' || s[i] == 'o') {
			stk[++tot] = s[i];
		} else if (s[i] == 'x') {
			if (tot >= 2 && stk[tot] == 'o' && stk[tot-1] == 'f') {
				tot -= 2; ans -= 3;
			} else {
				tot = 0;
			}
		} else {
			tot = 0;
		}
	}
	cout << ans << endl;
}