#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,c,a[N];
int main() {
	scanf("%d%d",&n,&c);
	vector<int> dp(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]-a[i-2]<=c) {
			dp[i]=max(dp[i-3]+1,dp[i]);
		}
	}
	printf("%d\n", dp[n]);
}