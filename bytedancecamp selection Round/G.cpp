#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int t, n, m;
int a[N][N], ans[N][N];
char s[100000 + 10];
int main() {
	scanf("%d", &t);
	while(t --) {
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
			scanf("%d", &a[i][j]); a[i][j] --;
		}
		scanf("%s", s+1);

		vector< pair<int,int> > v;
		v.push_back( make_pair(0,0) );
		v.push_back( make_pair(1,0) );
		v.push_back( make_pair(2,0) );

		for(int i=1;i<=m;i++){
			if(s[i] == 'U') v[0].second --;
			if(s[i] == 'D') v[0].second ++;
			if(s[i] == 'L') v[1].second --;
			if(s[i] == 'R') v[1].second ++;
			if(s[i] == 'I') swap(v[1], v[2]);
			if(s[i] == 'C') swap(v[0], v[2]);
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int p[3];
				p[0] = i, p[1] = j, p[2] = a[i][j];

				int r[3];
				r[0] = p[v[0].first] + v[0].second; r[0] = (r[0] % n + n) % n;
				r[1] = p[v[1].first] + v[1].second; r[1] = (r[1] % n + n) % n;
				r[2] = p[v[2].first] + v[2].second; r[2] = (r[2] % n + n) % n;

				ans[r[0]][r[1]] = r[2];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d ", ans[i][j] + 1);
			}
			printf("\n");
		}
		//printf("\n");
	}	
}