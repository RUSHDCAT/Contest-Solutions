#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

struct Nod{
	int x,y,d;
};
set<pair<int,int> > get(Nod nod) {
	int x=nod.x,y=nod.y,d=nod.d;
	set< pair<int,int> > s;
	s.insert(make_pair(x,y));
	s.insert(make_pair(x+dx[d],y+dy[d]));
	s.insert(make_pair(x+dx[(d+1)%4], y+dy[(d+1)%4]));
	return s;
}
map< pair<pair<int,int>,int>, int > vis;
bool in(Nod nod) {
	if(vis.find(make_pair(make_pair(nod.x,nod.y),nod.d)) != vis.end()) return false;
	return nod.x>=-10&&nod.x<=10&&nod.y<=10&&nod.y>=-10;
}
int ok(Nod A, Nod B) {
	set<pair<int,int> > sa = get(A);
	set<pair<int,int> > sb = get(B);
	int ins = 0;
	for(auto x: sa) {
		if (sb.count(x)) ins++;
	}
	return ins==2;
}

void brt() {
	vis[ make_pair(make_pair(0,0),3) ] = 0; 
	Nod nod = (Nod){0,0,3};
	queue<Nod> q; q.push(nod);
	while(q.size()) {
		Nod now = q.front(); q.pop();
		if(now.x==-3&&now.y==2) {
			printf("%d %d %d / %d\n", now.x,now.y,now.d, vis[make_pair(make_pair(now.x,now.y),now.d)] - 2*max(abs(now.x),abs(now.y)));
		}
		for(int x=now.x-1;x<=now.x+1;x++){
			for(int y=now.y-1;y<=now.y+1;y++){
				for(int d=0;d<4;d++){
					Nod nod = (Nod){x,y,d};
					if(in(nod) && ok(now,nod)){
						q.push((Nod){x,y,d});
						vis[make_pair(make_pair(nod.x,nod.y),nod.d)] = vis[make_pair(make_pair(now.x,now.y),now.d)] + 1;
					}
				}
			}
		}
	}
}


int main() {
	//freopen("out.txt","w",stdout);
	brt();
}