#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	int n; 	cin >> n;
	vector<int> a(n+1,0),pos(n+1,0);
	for(int i=1;i<=n;i++) {
		cin>>a[i]; pos[a[i]]=i;
	}

	vector<bool> vis(n+1, false);
	vector<int> ans;

	for(int i=1;i<=n;i++){
		int cur = pos[i];
		for(int j=cur-1;j>=i;j--) {
			if(vis[j]==1) {
				cout<<-1<<endl; return 0;
			}
			ans.push_back(j); vis[j]=1;
			swap(a[j],a[j+1]);
			pos[a[j]]=j,pos[a[j+1]]=j+1;
		}
	}

	if(ans.size() != n-1) {
		cout<<-1<<endl; return 0;
	}

	for(auto x: ans) {
		cout<<x<<endl;
	}
}