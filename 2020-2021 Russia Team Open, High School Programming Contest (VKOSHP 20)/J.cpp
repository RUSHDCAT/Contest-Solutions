#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

vector<int> vv;
int id(int x) {
	return upper_bound(vv.begin(),vv.end(),x) - vv.begin();
}
int count(int l,int r){
	return id(r) - id(l-1);
}
int main() {
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	vector<int> v(m);
	for(int i=0;i<m;i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	vv = v;

	vector<int> key;
	for(int i=0;i<v.size();i++) {
		if (v[i] >= m) 
			key.push_back(v[i]);

		if(v[i]+1+m-1<=n)
			key.push_back(v[i] + 1 + m - 1);
		else
			key.push_back(n + 1);
	}

	key.push_back(m);
	key.push_back(n + 1);
	sort(key.begin(),key.end());
	key.erase(unique(key.begin(),key.end()), key.end());

	LL ans = 0;
	for(int i=0;i+1<key.size();i++){
		int l=key[i], r=key[i+1]-1;
		int cnt = count(l-m+1,l);
		// printf("[%d,%d] cnt=%d\n", l,r,cnt);
		if(m - cnt <= s) {
			ans += r-l+1;
		}
	}
	cout<<ans<<endl;
}