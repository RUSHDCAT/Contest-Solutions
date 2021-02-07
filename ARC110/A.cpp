 #include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL gcd(LL x,LL y){
	return y==0?x:gcd(y,x%y);
}
LL lcm(LL x,LL y){
	return x/gcd(x,y)*y;
}

int main() {
	int n;cin>>n;
	LL ans=1;
	for(int i=2;i<=n;i++) ans=lcm(ans,i);
	cout<<ans+1<<endl;	
}