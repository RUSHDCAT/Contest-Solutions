#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(N+1),L(N,N+1),R(N+1,0),c(N,0);
 
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		L[a[i]]=min(L[a[i]],i);
		R[a[i]]=max(R[a[i]],i);
		c[a[i]] ++;
	}
 
	auto upd = [](int &x,int y) {
		x=min(x,y);
	};
 
	int pos = n;
	while (pos >= 1 && a[pos] == a[n]) --pos;
 
	vector<int> dp(N+1,1e9);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		if(i == L[a[i]]) {	
			upd(dp[R[a[i]]], dp[i-1] + R[a[i]] - L[a[i]] + 1 - c[a[i]]);
		}
		upd(dp[i], dp[i-1] + 1);
	}
	cout << dp[n] << endl;
}