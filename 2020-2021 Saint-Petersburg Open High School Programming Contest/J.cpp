#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;

string str[N];
int d[N][N];

int dis(string& s, string& t) {
	int n = s.length();
	int m = t.length();
	vector< vector<int> > dp(n+1, vector<int>(m+1,1e9) );
	
	for(int i=0;i<=n;i++) dp[i][0]=i;
	for(int i=0;i<=m;i++) dp[0][i]=i;
	
	for (int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) {
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
		}
	}
	return dp[n][m];
}
bool cmp(int x,int y){
	return d[0][x] < d[0][y];
}
int main() {
	ios::sync_with_stdio(0);
	cin >> str[0] >> str[1];
	int n; cin >> n;
	for(int i=2;i<=n+1;i++){
		cin >> str[i];
	}
	for (int i = 0; i <= n+1; i ++){
		for (int j = i + 1; j <= n+1; j ++) {
			d[j][i] = d[i][j] = dis(str[i], str[j]);
			//printf("%d %d $ %d\n", i, j, d[i][j]);
		}
	}

	vector<int> vec;
	for(int i=2;i<=n+1;i++){
		if(d[0][i] + d[i][1] == d[0][1]) {
			vec.push_back(i);
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	for(auto x: vec) {
		//printf("! %d\n", x);
	}
	vector<int> dp(n+2,0), pre(n+2,-1);

	int mx=-1, pos=-1;
	for(int i=0;i<vec.size();i++) {
		dp[i]=1; 
		for(int j=0;j<i;j++){
			int u=vec[j], v=vec[i];
			if(d[u][1] == d[u][v] + d[v][1]) {
				if(dp[j]+1 > dp[i]){
					dp[i]=dp[j]+1; pre[i]=j;
				}
			}
		}
		if(dp[i]>mx){
			mx=dp[i]; pos=i;
		}
	}	

	vector<string> id;
	while(pos>=0) {
		id.push_back(str[vec[pos]]);
		pos=pre[pos];
	}
	reverse(id.begin(),id.end());
	//sort(id.begin(),id.end());

	// printf("%d %d\n", dis[0][1], id.size());
	cout<<d[0][1]<<" "<<id.size()<<endl;
	for(auto p:id) cout<<p<<endl;
}

