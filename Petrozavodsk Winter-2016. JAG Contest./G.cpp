#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int a, b, c, n;

int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

set< pair<pair<int,int>, int> > st;
set< pair<pair<int,int>, int> > vis;

int compnent_count( set< pair<pair<int,int>, int> > nods) {

	for (auto p: nods) {
		//printf("[%d,%d,%d] ", p.first.first,p.first.second,p.second);
	}
	//printf("\n");
	if (nods.size() == 0) return 0;
	set< pair<pair<int,int>, int> > vis;

	int ans = 0;	
	for (auto p: nods) {
		if (vis.count(p)) continue;
		ans ++;
		queue< pair<pair<int,int>, int> > q;
		q.push(p); vis.insert(p);
		while (q.size()) {
			pair<pair<int,int>,int> now = q.front(); q.pop();

			int x = now.first.first;
			int y = now.first.second;
			int z = now.second;

			for(int i=0;i<6;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				int nz=z+dz[i];
				pair<pair<int,int>,int>  nex = make_pair(make_pair(nx,ny),nz);
				if (nods.count(nex) && !vis.count(nex)) {
					vis.insert(nex); q.push(nex);
				}
			}			
		}
	}
	return ans;
}
bool in(int x,int y,int z){
	return x>=0&&x<a && y>=0 && y<b && z>=0 && z<c;
}

int main() {
	scanf("%d%d%d%d",&a,&b,&c,&n);
	for(int i=0;i<n;i++){
		int x,y,z; 
		scanf("%d%d%d",&x,&y,&z);
		st.insert(make_pair(make_pair(x,y),z));
	}		
	if(1LL*a*b*c == n) {
		return !printf("0\n"); 
	}

	int ans = 1;
	for(auto p: st) {
		int x=p.first.first;
		int y=p.first.second;
		int z=p.second;
		if (vis.count( make_pair(make_pair(x,y),z) )) continue;

		set< pair<pair<int,int>, int> > nods;
		vector< pair<pair<int,int>, int> > tmp;

		queue< pair<pair<int,int>,int> > q;
		q.push(make_pair(make_pair(x,y),z)); vis.insert(make_pair(make_pair(x,y),z));
		while (q.size()) {
			pair<pair<int,int>,int> now = q.front(); q.pop();
			tmp.push_back(now);
			int x = now.first.first;
			int y = now.first.second;
			int z = now.second;

			for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++)for(int k=-1;k<=1;k++){
				if(i==0&&j==0&&k==0) continue;
				int nx=x+i;
				int ny=y+j;
				int nz=z+k;
				pair<pair<int,int>,int>  nex = make_pair(make_pair(nx,ny),nz);
				if (st.count(nex) && !vis.count(nex)) {
					vis.insert(nex); q.push(nex);
				}
			}
		}

		for (auto p: tmp) {
			//printf("(%d,%d,%d)", p.first.first,p.first.second,p.second);
			for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++)for(int k=-1;k<=1;k++){
				if(i==0&&j==0&&k==0) continue;
				int nx = p.first.first + i;
				int ny = p.first.second + j;
				int nz = p.second + k;
				if(in(nx,ny,nz) && !st.count(make_pair(make_pair(nx,ny),nz))){
					//printf("ins {%d,%d,%d}\n", nx,ny,nz);
					nods.insert( make_pair(make_pair(nx,ny),nz) );
				}
			}
		}
		//printf("\n");
		ans += compnent_count(nods) - 1;
	}
	cout << ans << endl;
}