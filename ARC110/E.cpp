#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
const LL mod = 1e9 + 7;

int n;
char s[N];
int sum[N], nex[N], dp[N], pd[N];
vector<int> vec[8];
int main() {
	scanf("%d%s",&n,s+1);
	int ok=1;
	for(int i=1;i<=n;i++)if(s[i]!=s[1])ok=0;
	if(ok){
		return !printf("1\n"); return 0;
	}	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^(1<<(s[i]-'A'));
	}
	for(int i=0;i<=n;i++) {
		vec[sum[i]].push_back(i);
	}

	for(int i=n;i>=1;i--){
		if(s[i]!=s[i+1]) nex[i]=i+1;
		else nex[i]=nex[i+1];
	}

	int f[7] = {0}; dp[n+1]=1; pd[n+1] = 1;
	f[1] = f[6] = 0; 
	f[2] = f[5] = 1;
	f[4] = f[3] = 2;

	for(int i=n;i>=1;i--) {
		int pre = sum[i-1];
		vector<int> mn(3,n+2);
		for(int mask=0;mask<8;mask++){
			int val = mask ^ pre;
			//printf("dp[%d]=%d\n", i,dp[i]);
			if(sum[n] == val) {
				(pd[i] += 1) %= MOD;
			}
			if (val!=0 && val!=7){
				auto it = lower_bound(vec[mask].begin(),vec[mask].end(),i);
				if (it != vec[mask].end()) {
					int pos = (*it);
					mn[f[val]] = min(mn[f[val]], pos+1);
				}
			}
		}
		for(int x=0;x<3;x++){
			if(mn[x]<=n+1) {
				printf("i=%d,x=%d,mn=%d\n", i,x,mn[x]);
				if(mn[x] > i + 1)
					(dp[i]+=pd[mn[x]]) %= mod;
			}
		}
	}
	cout<<dp[1]<<endl;
}