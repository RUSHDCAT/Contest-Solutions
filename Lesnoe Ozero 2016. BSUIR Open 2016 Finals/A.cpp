#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL mod = 1e9 + 7;
char s[52], t[52];

LL dp[52][2];
int main() {
	scanf("%s%s",s+1,t+1);
	vector<char> n, m;
	for(int i=1;s[i];i++) n.push_back(s[i]);
	for(int i=1;t[i];i++) m.push_back(t[i]);
	if(m.size()>n.size()) return !printf("0\n"); 
	int d = n.size() - m.size();
	reverse(m.begin(),m.end());
	for(int i=0;i<d;i++) m.push_back('0');
	reverse(m.begin(),m.end());

	for(int i=0;i<n.size();i++){
		int x = n[i] - '0', y = m[i] - '0';
		// printf("x=%d,y=%d\n", x,y);
		if (x >= y) dp[i][1] = (i>=1?dp[i-1][1]:1);
		dp[i][0] = (i-1>=0?dp[i-1][0]:0) * (10 - y) % mod;
		if (x > y) {
			dp[i][0] += (i-1>=0?dp[i-1][1]:1) * (x - y) % mod; 
		}
		dp[i][0] %= mod;
	}

	cout<< (dp[n.size()-1][0] + dp[n.size()-1][1])%mod << endl;
}


