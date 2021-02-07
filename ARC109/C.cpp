#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int n, k, pw[N];
char s[N];
int dp[N][N];
char tp(int x){
	if(x==0)return 'R';
	if(x==1)return 'S';
	return 'P';
}
int id(char c){
	if(c=='R')return 0;
	if(c=='S')return 1;
	return 2;
}
int win(int x,int y){
	if((x+1)%3==y)return x;
	if((y+1)%3==x)return y;
	return x;
}
int brute(int l,int r){
	if(l==r) return id(s[l]);
	int mid=(l+r)>>1;
	return win(brute(l,mid), brute(mid+1,r)); 
}
int solve(int suf,int k){
	if(dp[suf][k]!=-1)return dp[suf][k];
	if(k<=10 && suf>=1<<k)
		return brute(n-suf,n-suf+(1<<k)-1);
	 int l=solve(suf,k-1);
	 int pre=((pw[k-1]-suf)%n+n)%n;
	 int nexsuf=(n-pre)%n; if(nexsuf==0) nexsuf=n;
	 int r=solve(nexsuf,k-1);
	 return dp[suf][k]=win(l,r);
}
int main() {
	scanf("%d%d%s",&n,&k,s);
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%n;
	memset(dp,-1,sizeof(dp));
	cout<<tp(solve(n,k))<<endl;
}