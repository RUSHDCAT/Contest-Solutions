#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	map<int,int> mp;
	for(int i=0;i<n;i++) mp[a[i]]++;
	LL ans=0;
	int mn=k;
	for(int i=0;;i++){
		if(mn==0) break;
		mn=min(mn,mp[i]);
		ans+=mn;
	}
	cout<<ans<<endl;
}