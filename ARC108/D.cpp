#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL mod = 1e9 + 7;

int n;
char aa,ab,ba,bb;

string ins(string s,int pos,char c) {
	int n=s.length();
	string res="";
	for(int i=0;i<=pos;i++)res+=s[i];
	res+=c;
	for(int i=pos+1;i<n;i++)res+=s[i];
	return res;
}

void brt() {
	string s = "AB";
	int ans=0;
	map<string,int> vis; queue<string> q; q.push("AB");
	while(q.size()){
		string now=q.front(); q.pop();
		if(now.length()==n) {
			cout<<now<<endl; ans++; continue;
		}
		for(int i=0;i+1<now.length();i++){
			string nex;
			if(now[i]=='A'&&now[i+1]=='A'){
				nex=ins(now,i,aa); 
				if(vis[nex]==0) {
					q.push(nex); vis[nex]=1;
				}
			}
			if(now[i]=='A'&&now[i+1]=='B'){
				nex=ins(now,i,ab); 
				if(vis[nex]==0) {
					q.push(nex); vis[nex]=1;
				}
			}
			if(now[i]=='B'&&now[i+1]=='A'){
				nex=ins(now,i,ba); 
				if(vis[nex]==0) {
					q.push(nex); vis[nex]=1;
				}
			}
			if(now[i]=='B'&&now[i+1]=='B'){
				nex=ins(now,i,bb); 
				if(vis[nex]==0) {
					q.push(nex); vis[nex]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
}

int main() {
	cin>>n>>aa>>ab>>ba>>bb;
	//brt();
	if(ab == 'B') {
		if (bb == 'B') printf("1\n");
		else {
			if (ab == 'B' && ba == 'B') {
				vector<int> dp(n+2);
				//printf("#\n");

				for (int i = 2; i <= n; i ++) {
					dp[i]=1;
					for (int j = i - 2; j >= 2; j --) {
						dp[i] += dp[j];
						dp[i] %= mod;
					}
				}
				cout << dp[n] % mod << endl;
			} else {
				//printf("!\n");
				int f = 1;
				for (int i = 1; i <= n - 3; i ++) f = f * 2 % mod;
				cout << f << endl;
			}
		}
		return 0;
	}

	if(aa == 'A') printf("1\n");
	else {
		if (ba == 'A' && ab == 'A') {
			vector<int> dp(n+2);
			dp[2] = 1;
			for (int i = 3; i <= n; i ++) {
				dp[i]=1;
				for (int j = i - 2; j >= 2; j --) {
					dp[i] += dp[j];
					dp[i] %= mod;
				}
			}
			cout << dp[n] % mod << endl;
		} else {
			int f = 1;
			for (int i = 1; i <= n - 3; i ++) f = f * 2 % mod;
			cout << f << endl;
		}
	}
}