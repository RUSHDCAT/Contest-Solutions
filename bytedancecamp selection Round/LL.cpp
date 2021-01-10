#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20;
int n, k;
char s[1<<N][N + 5];
int cnt[N + 5];

bitset<1<<N> B[24];
int p[1<<21], nex[1<<23];

void solve(int mask) {
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
		p[val+1] = i+1;
	}
	printf("Yes\n");
	for(int i=1;i<=1<<n;i++) printf("%d ", p[i]); printf("\n");
	for(auto p: col) printf("%d ", p); printf("\n");	



	
	for(int i=1;i<=1<<n;i++){
		int sum = 0, id = n-1;
		for(int j=1;j<=n+k;j++){
			int r = p[i] - 1;
			int c = col[j-1] - 1;
			printf("%c", s[r][c]);
			if(s[r][c] == '1' && j<=n) {
				sum |= 1<<id; 
			}
			id--;
		}
		//printf(" %d\n", sum);
		assert(sum == i-1);
		printf("\n");
	}

}

int main() {
	scanf("%d%d", &n, &k);
	
	for(int i=0;i<1<<n;i++){
		scanf("%s", s[i]);
	}	
	for(int i=0;i<n+k;i++){
		for(int j=0;j<1<<n;j++){
			if(s[j][i]=='1') {
				B[i].set(j);
				cnt[i] ++;
			}
		}
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


	int tot=1<<n;
	for(int i=0;i<n+k;i++){
		if( cnt[i] != (1<<n)/2 ) continue;
		
		nex[i] |= (1<<i);
		for(int j=i+1;j<n+k;j++){
			if( cnt[j] != (1<<n)/2 ) continue;

			int c = (B[i]&B[j]).count();
			if(c == tot/4){
				//printf("link %d %d\n", i, j);
				nex[i] |= 1<<j;
				nex[j] |= 1<<i;
			}
		}
	}

	for(int i=0;i<1<<(n+k);i++){
		int s=(1<<(n+k)) - 1,c=0;
		for(int j=0;j<n+k;j++){
			if(i>>j&1){
				c++;
				s &= nex[j];
			}
		}
		//printf("i=%d, c=%d, s=%d\n", i, c, s);
		if(c==n && (i&s) == i) {
			solve(i);
			return 0;
		}
	}
	printf("No\n");
}		