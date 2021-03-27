#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);	
    int t;
    cin >> t;
    while (t --) {
    	int n; cin >> n;
    	vector<int> s(n+1),d(n+1,0);
    	for (int i=1;i<=n;i++) cin>>s[i];
    	
    	LL ans=0;
    	for (int i=1;i<=n;i++) {
    		if(s[i]==1) continue;
    		if(s[i]>max(n-i,1)){
    			d[i] += s[i]-max(n-i,1);
    			s[i]=max(n-i,1);
    		}
    		d[i]+=s[i]-1;
    		ans+=max(d[i],0);
    		for(int j=i+2;j<=i+s[i];j++) d[j]--;
    	}
    	cout<<ans<<endl;
    }	
}