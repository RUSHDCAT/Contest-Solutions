#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int a,b,lson[N],rson[N];
set<int> s;

int sz[N],v[N];
int main() {
	cin>>a>>b;
	for(int i=1;i<=a+b;i++) {
		s.insert(i);
		v[i]=1;
	}

	queue<int> q;
	q.push(1); sz[1]=a+b;
	int now=1;

	while(q.size()){
		int u=q.front(); q.pop();
		int szl=(sz[u]-1)/2;
		int szr=(sz[u]-1+1)/2;
		if(now+1<=a+b && szl){
			++now; sz[now]=szl;
			lson[u]=now; q.push(now);
		}
		if(now+1<=a+b && szr){
			++now; sz[now]=szr;
			rson[u]=now; q.push(now);
		}
	}
	if(b){
		q.push(1); sz[1]=b; now=1;
		while(q.size()){
			int u=q.front(); q.pop();
			v[u]++;
			int szl=(sz[u]-1+1)/2;
			int szr=(sz[u]-1)/2;

			if(szl){
				if(lson[u]==0) return !printf("-1\n");
				q.push(lson[u]);
				sz[lson[u]] = szl;
			}
			if(szr){
				if(rson[u]==0) return !printf("-1\n");
				q.push(rson[u]);
				sz[rson[u]] = szr;
			}
		}
	}
	for(int i=1;i<=a+b;i++){
		printf("%d %d %d\n", v[i],lson[i],rson[i]);
	}
}