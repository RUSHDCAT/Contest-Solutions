#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20;
int n, k, C=0;
char s[1<<N][N + 5];
int cnt[N + 5];


int p[1<<21], nex[1<<23],las[1<<21];

void solve(int mask) {
	++ C;
	vector<int> col, row;
	bool vis[30] = {0};
	for(int i=0;i<n+k;i++){
		if(mask>>i&1) {
			col.push_back(i+1); vis[i+1] = 1;
		}
	}
	for(int i=1;i<=n+k;i++) if(!vis[i]) col.push_back(i);

	for(int i=0;i<1<<n;i++){
		int id=n-1, val=0;
		for(int j=0;j<n+k;j++){
			if(mask>>j&1) {
				if(s[i][j]=='1') val |= 1<<id;
				--id;
			}
		}
		//printf("i=%d, val=%d\n", val);
		if(las[val+1] == C) return;
		p[val+1] = i+1; las[val+1] = C;
	}  

	printf("Yes\n");
	for(int i=1;i<=1<<n;i++) printf("%d ", p[i]); printf("\n");
	for(auto p: col) printf("%d ", p); printf("\n");	
	exit(0);
}


int B = 131;
const LL MOD = 998244353;

LL pw[1<<N], sum[30];

int main() {

	pw[0] = 1;
	for(int i=1;i<1<<N;i++) {
		pw[i] = pw[i-1] * B % MOD;
	}

	scanf("%d%d", &n, &k);
	
	for(int i=0;i<1<<n;i++){
		scanf("%s", s[i]);
	}	

	for(int j=0;j<n+k;j++){
		for(int i=0;i<1<<n;i++){
			if(s[i][j] == '1') {
				sum[j] = (sum[j] + pw[i]) % MOD;
			}
		}
		// printf("sum[%d] = %lld\n", j, sum[j]);
	}


	if(n==1) {
		for(int j=0;j<n+k;j++){
			if(s[0][j]=='0' && s[1][j]=='1') {
				printf("Yes\n");
				printf("%d %d\n", 1,2);
				printf("%d", j+1);
				for(int x=1;x<=n+k;x++) {
					if(x==j+1) continue;
					printf(" %d", x);
				}
				printf("\n");
				
				return 0;
			}else if(s[0][j]=='1' && s[1][j]=='0'){
				printf("Yes\n");
				printf("%d %d\n", 2,1);
				printf("%d", j+1);
				for(int x=1;x<=n+k;x++) {
					if(x==j+1) continue;
					printf(" %d", x);
				}
				printf("\n");
				return 0;
			}
		}
		printf("No\n");
		return 0;
	}

	LL accepted = 0;
	for(int i=0;i<1<<n;i++) {
		int c=0;
		for(int j=0;j<n;j++) {
			if(i>>j&1) c++;
		}
		//printf("i=%d, c=%d\n", i,c);
		accepted += (1LL*c*pw[i]%MOD);
		accepted = accepted % MOD;
	}	
	//printf("accepted = %lld\n", accepted);

	for(int i=0;i<1<<(n+k);i++) {
		LL now = 0; int c=0;
		
		for(int j=0;j<(n+k);j++){
			if(i>>j&1) {
				c++; now += sum[j];
				now %= MOD;
			}
		}

		//printf("i = %d, now = %lld\n", i, now);
		if(c == n && now == accepted) {
			//printf("now=%d\n", now);
			solve(now);
		}
	}

	printf("No\n");
}		