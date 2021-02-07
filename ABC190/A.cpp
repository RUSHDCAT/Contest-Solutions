#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a,b,c; cin>>a>>b>>c;
	if(c==0) cout<<(a>b?"Takahashi":"Aoki")<<endl;
	else cout<<(a>=b?"Takahashi":"Aoki")<<endl;
}