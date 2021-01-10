#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m, k;

int main() {
	scanf("%d%d%d",&n,&m,&k);

	vector< pair<int,int> > vec;

	vec.push_back(make_pair(1,1));
	vec.push_back(make_pair(n,m));
	for(int i=1;i<=k;i++){
		int x,y; scanf("%d%d",&x,&y);
		vec.push_back( make_pair(x,y) );
	}	
	sort(vec.begin(),vec.end());

	for(int i=1;i<vec.size();i++){
		if(vec[i].second < vec[i-1].second) return !printf("Impossible\n");
	}

	for(int i=0;i+1<vec.size();i++){
		int dx = vec[i+1].first - vec[i].first;
		int dy = vec[i+1].second - vec[i].second;
		// 1printf("dx=%d, dy=%d\n", dx,dy);
		for(int j=1;j<=dx;j++) printf("D");
		for(int j=1;j<=dy;j++) printf("R");
	}
	printf("\n");
}