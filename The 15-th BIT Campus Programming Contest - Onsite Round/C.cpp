#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500 + 10;
int n,a[N];
int mx[N][N],dp[N][N];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}	
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			for(int x=0;x<j;x++)mx[i][j]=max(mx[i][j], a[(i+x)%n]);	
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			for(int m=j;m<j+i;m++){
				int mid=m%n;
				int l=(j-1+n)%n;
				int r=(j+i)%n;

				dp[i][j] = max(dp[m-j][j]+dp[i-(m-j)-1][(mid+1)%n]+a[mid]*a[l]*a[r],dp[i][j]);
			}
			//printf("dp[%d][%d]=%d\n", i,j,dp[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)ans=max(ans,dp[n-1][i]+a[(i-1+n)%n]);
	printf("%d\n", ans);
}