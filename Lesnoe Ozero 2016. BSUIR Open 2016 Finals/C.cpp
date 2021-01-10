#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

int main() {
	int n=100;
	set<int> s;
	vector<int> f(n+1);
	f[0]=1; f[1]=2; s.insert(1); s.insert(2);
	for(int i=2;i<=n;i++){
		for(int j=1;;j++){
			if(gcd(j,f[i-1])>1 && !s.count(j)) {
				f[i]=j; s.insert(j); break;
			}
		}
	}
	for(int i=1;i<=50;i++){
		printf("f[%d]=%d\n", i,f[i]);
	}
}