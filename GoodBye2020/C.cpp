#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const int inf = 1e9;

int t, n; char s[N];
int dp[N][2][2];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1); n = strlen(s + 1);

		for (int i = 0; i <= n; i ++)
			for (int j = 0; j < 2; j ++)
				for (int k = 0; k < 2; k ++)
					dp[i][j][k] = inf;
		
		if (n == 1) {
			printf("0\n"); continue;
		}

		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if (i==0 && j==0 && s[1]==s[2]) continue;
				dp[2][i][j] = i+j;
			}
		}
	
		for (int i = 2; i < n; i ++) {
			for (int x = 0; x < 2; x ++) {
				for (int y = 0; y < 2; y ++) {
					// printf("dp[%d][%d][%d] = %d\n", i,x,y,dp[i][x][y]);
					vector<char> ban;
					if (x == 0) ban.push_back(s[i-1]);
					if (y == 0) ban.push_back(s[i]);


					bool find = false;
					for (auto c: ban) if (c == s[i + 1]) find = true;

					if (find == false) {
						dp[i+1][y][0] = min(dp[i+1][y][0], dp[i][x][y]);
						dp[i+1][y][1] = min(dp[i+1][y][1], dp[i][x][y] + 1);
					} else {
						dp[i+1][y][1] = min(dp[i+1][y][1], dp[i][x][y] + 1);
					}
				}
			}
		}
		int ans = inf;
		for (int i = 0; i < 2; i ++) for (int j = 0; j < 2; j ++) ans = min(ans, dp[n][i][j]);
		printf("%d\n", ans);
	}
}