#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
typedef long long LL;
const LL mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n+1);	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	LL ans=0;
	LL s=0, cnt=0; 

	for(int i=n;i>=1;i--) {
		if(a[i]==1) {
			ans += s - cnt;
			ans = (ans % mod + mod) % mod;
		}
		if(a[i]==2) {
			s = s * 2 % mod;
		}
		if(a[i]==3) {
			cnt ++; cnt%=mod; s ++; s %= mod;
		}
	}
	cout << ans << endl;
}

