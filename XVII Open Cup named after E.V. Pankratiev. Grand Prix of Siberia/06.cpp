#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int B, M;

vector< pair<int,int> > loves[N];
int idx[N];
bool cmp(int x, int y) {
	return loves[x] < loves[y];
}
int par[N], ch[N][20];
int find(int x) {
	return par[x]==x?x:par[x]=find(par[x]);
}
vector<int> vec;
int id(int x){
	return lower_bound(vec.begin(),vec.end(),x) - vec.begin();
}
int main() {
	cin >> B >> M;

	int range = 1, pw = 1;
	for(int L=1;;L++) {
		range *= B; pw = pw * B % M;
		// [0, range)	
		for(int i=0;i<M;i++) {
			LL need = (M - 1LL * pw * i % M) % M;
			need = (need % M + M) % M;
			if (need < range) {
				loves[i].push_back(make_pair(L, need));
			}
		}
		if (range >= M) break;
	}	
	loves[0].push_back(make_pair(-1, -1));

	for(int i=0;i<M;i++) idx[i] = i, par[i] = i;
	sort(idx, idx+M, cmp);
	
	for(int i=0;i<M;i++) {
		if(i==0 || (loves[idx[i]] != loves[idx[i-1]])) {
		}else{
			par[find(idx[i])] = find(idx[i-1]);
		}
	}	
	/*
	for(int i=0;i<M;i++){
		for(auto p: loves[i]) {
			printf("(%d, %d)", p.first,p.second);
		}
		printf("/%d\n",find(i));
	}*/
	

	for(int i=0;i<M;i++) if(find(i)==i) vec.push_back(i);
	sort(vec.begin(),vec.end());

	for(int i=0;i<M;i++){
		if(find(i) == i) {
			for(int j=0;j<B;j++){
				int nex=(i*B+j)%M;
				//printf("%d->%d\n", i,nex);
				ch[id(i)][j] = id(find(nex));
			}
		}
	}
	printf("%d %d\n", vec.size(), id(find(0)));
	for(int i=0;i<vec.size();i++) {
		printf("%s ", i==id(find(0))?"G":"B");
	}
	printf("\n");
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<B;j++) printf("%d ", ch[i][j]);
		printf("\n");
	}
}