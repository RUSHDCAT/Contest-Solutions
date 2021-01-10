#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k;
int pw[22];

string gen(int x) {
	string ans = "";
	for(int i=0;i<k;i++){
		if(x>>i&1) ans += "0"; else ans += "1";
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main() {
	pw[0]=1;
	for(int i=1;i<=20;i++) pw[i]=pw[i-1]*2;

	scanf("%d", &n);

	for(int i=n;i>=0;i--) {
		if (pw[(int)log2(i)] != i) continue; 
		if(pw[i] * i <= pw[n]) {
			k = i; break;
		}
	}
	vector<int> v;

	int need = ((1<<n) / k) - (1<<k);
	for(int i=0;i<1<<k;i++) {
		v.push_back(i);
	}

	for(int i=0;i<1<<k;i++){
		if(need == 0) break;
		for(int j=0;j<1<<k;j++){
			if(j==i+1) continue;
			if(need == 0) break;
			v.push_back(i);
			v.push_back(j);
			need -= 2;
		}
	}	
	string ans = "";
	for(auto x: v) ans += gen(x);
	for(int i=0;ans[i];i++) printf("%c", ans[i]);

		
	printf("\n");
}