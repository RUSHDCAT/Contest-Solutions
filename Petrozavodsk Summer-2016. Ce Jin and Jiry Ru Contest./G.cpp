#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;

bool ok(int x) {
	int c=0;
	for(int i=0;i<n;i++){
		if(x>>i&1) c++;	
		else c--;
		if(c<0)return 0;
	}
	return c==0;
}

vector<int> nex(int x){
	vector<int> v,ans;
	for(int i=0;i<n;i++){
		if(x>>i&1)v.push_back(1);else v.push_back(0);
	}

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			vector<int> tmp=v;
			for(int x=i;x<=j;x++){
				int l=x,r=i+j-x;
				if(l<=r)swap(tmp[l],tmp[r]);
			}
			for(int x=i;x<=j;x++) tmp[x]^=1;
			int y=0;
			for(int x=0;x<tmp.size();x++){
				if(tmp[x]) y|=1<<x;
			}
			ans.push_back(y);
		}
	}
	return ans;
}
int dis[N];

void chk(int nn) {
	n = nn;
	memset(dis, -1, sizeof(dis));
	queue<int> q;
	for(int i=0;i<1<<n;i++){
		if(ok(i)){
			q.push(i); dis[i]=0;
		}
	}

	while(q.size()){
		int u=q.front(); q.pop();
		vector<int> f=nex(u);
		for(auto v:f){
			if(dis[v]==-1){
				dis[v]=dis[u]+1; q.push(v);
			}
		}
	}
	int ans=0,f[20] = {0};
	for(int i=0;i<1<<n;i++){
		int s=0;
		printf("x=%d ", i);
		for(int j=0;j<n;j++){
			printf("%c", i>>j&1?'(':')');
			if(i>>j&1) s++;
		}
		printf(" %d / %d\n", dis[i],s);
		ans += dis[i] + 1;
		f[dis[i]] ++;
	}
	printf("%d %d %d %d\n", f[0], f[1], f[2], f[3]);
}

int main() {
	chk(10);
}