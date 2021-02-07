#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

struct Nod{
	int x,y,d;
};

int t;
set<pair<int,int> > get(Nod nod) {
	int x=nod.x,y=nod.y,d=nod.d;
	set< pair<int,int> > s;
	s.insert(make_pair(x,y));
	s.insert(make_pair(x+dx[d],y+dy[d]));
	s.insert(make_pair(x+dx[(d+1)%4], y+dy[(d+1)%4]));
	return s;
}

void read() {
	int ax,ay,bx,by,cx,cy;
	scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
	set< pair<int,int> > st;
	st.insert(make_pair(ax,ay));
	st.insert(make_pair(bx,by));
	st.insert(make_pair(cx,cy));

	Nod nod;
	for(auto p:st){
		for(int d=0;d<4;d++){
			if (get((Nod){p.first,p.second,d}) == st) {
				nod = (Nod){p.first,p.second,d};
			}
		}
	}
	int x=nod.x,y=nod.y,d=nod.d;
	LL ans=2*max(abs(x),abs(y));
	
	if(d==2) {
		if(abs(x)<abs(y)) {
			if(y<0) ans++; else ans--;	
		}
	}
}

int main() {
	
}