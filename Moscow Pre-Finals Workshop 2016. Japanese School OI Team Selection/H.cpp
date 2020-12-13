#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int n,m;
char s[N][N];

int dis[5000000 + 10];


int tmp[3];
int id(int x, int y) {
	return (x-1) * m + y;
}
pair<int,int> pos(int x) {
	return make_pair((x-1)/m + 1, (x-1)%m + 1);
}
int enc(int r1,int c1,int r2,int c2) {

	if(r1 == r2) {

		return n * m + (r1 - 1) * (m - 1) + min(c1, c2);
	}
	
	return n * m + n * (m - 1) + (min(r1, r2) - 1) * m + c1;
}

bool ok(int x,int y){
	return s[x][y] == '.';
}
void decode(int x) {
	x -= n * m;
	if (x <= n * (m-1)) {
		x -= 1;
		int r = x / (m - 1) + 1;
		int c = x % (m - 1) + 1;
		tmp[1] = id(r, c);
		tmp[2] = id(r, c + 1);
	} else {
		x -= n * (m-1);
		x -= 1;
		int r = x / m + 1;
		int c = x % m + 1;
		tmp[1] = id(r, c);
		tmp[2] = id(r + 1, c);
	}
}


int up[N][N],lef[N][N],rig[N][N],down[N][N];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}	

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j] == '.') {
				if(s[i][j-1] == '#') lef[i][j] = id(i, j); else lef[i][j] = lef[i][j-1];
				if(s[i-1][j] == '#') up[i][j] = id(i,j); else up[i][j] = up[i-1][j];
			}
		}
	}

	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(s[i][j]=='.') {
				if(s[i][j+1] == '#') rig[i][j] = id(i,j); else rig[i][j] = rig[i][j+1];
				if(s[i+1][j] == '#') down[i][j] = id(i,j); else down[i][j] = down[i+1][j];
			}
		}
	}
	int r1,c1,r2,c2; 
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	memset(dis,-1,sizeof(dis));

	queue<int> q;
	int s = id(r1, c1);
	int t = id(r2, c2);
	q.push(s); dis[s] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		//printf("u = %d, dis = %d\n", u, dis[u]);
		if(u==t) {
			return !printf("%d\n", dis[t]);
		}
		if (u > n * m) {
			decode(u);
			//printf("%d %d %d %d\n", pos(tmp[1]).first, pos(tmp[1]).second, pos(tmp[2]).first, pos(tmp[2]).second);
			if(dis[tmp[1]] == -1) {
				dis[tmp[1]] = dis[u] + 1; q.push(tmp[1]);
			}
			if(dis[tmp[2]] == -1) {
				dis[tmp[2]] = dis[u] + 1; q.push(tmp[2]);
			}
			
		} else {
			pair<int,int> p = pos(u);
			//printf("%d %d\n", p.first,p.second);
			int x = p.first, y = p.second;
			for(int i=0;i<4;i++){
				int nx=x+dx[i], ny=y+dy[i];
				if(ok(nx,ny)) {
					int v2 = enc(x,y,nx,ny);
					if(dis[v2]==-1){
						dis[v2]=dis[u]+1; q.push(v2);
					}
				}
			}

			{
				int v = up[x][y];
				if(dis[v]==-1) {
					dis[v]=dis[u]+1; q.push(v);
				}
				v=lef[x][y];
				if(dis[v]==-1) {
					dis[v]=dis[u]+1; q.push(v);
				}
				v=rig[x][y];
				if(dis[v]==-1) {
					dis[v]=dis[u]+1; q.push(v);
				}
				v=down[x][y];
				if(dis[v]==-1) {
					dis[v]=dis[u]+1; q.push(v);
				}
			}
		}
	}
	printf("-1\n");
}