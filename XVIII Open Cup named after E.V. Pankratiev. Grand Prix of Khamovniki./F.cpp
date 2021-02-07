#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n;

int nex(int x) {
	if (x % 2 == 0) return x / 2;
	return n / 2 + x / 2;
}

char s[N],t[N],x[N]; int ans=0;
void p() {
	for(int i=0;i<n;i++) if(s[i]!=t[i])return;
	printf("%d\n", ans);exit(0);
}
void f(char s[]) {
	for(int i=0;i<n;i++){
		x[nex(i)]=s[i];
	}
	for(int i=0;i<n;i++)s[i]=x[i];
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
} 
int main() {
	for(n=1000000-300;n<=1000000;n+=2){
		vector<int> in(n,0);
		for(int x=0;x<n;x++){
			in[nex(x)]++;
		}
		printf("%d: ", n);
		int A=1;
		vector<int> vis(n,0);
		for(int x=0;x<n;x++){
			if(vis[x])continue;
			int now=x,len=0;
			while(1) {
				vis[now]=1;
				now=nex(now); len++;
				if(now==x) break;
			}
			printf("%d ", len);
			A=lcm(A,len);
		}
		printf("\n%d\n", A);
		
	}
	scanf("%s%s",s,t);n=strlen(s);
	for(int i=1;i<=23;i++){
		//printf("%s\n", s);
		p(); f(s);  ans++;
	}
	printf("-1\n");
}