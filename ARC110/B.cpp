#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n; char s[N];
int main() {
	scanf("%d%s",&n,s);
	LL ans=0;
	LL B=1e10;
	for(int bias=0;bias<3;bias++){
		char t[4] = "110";
		bool ok=1;
		set<int> st;
		for(int i=0;i<n;i++){
			st.insert((i+bias)/3);
			if(s[i]!=t[(i+bias)%3])ok=0;
		}
		if(ok){
			LL cnt=st.size();
			ans+=B-cnt+1;
		}
	}
	cout<<ans<<endl;
}