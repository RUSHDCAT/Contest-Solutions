#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL c[8];
bool fail(LL d[]){
	for(int i=0;i<7;i++)if(d[i]<0)return true;
	return false;
}
bool vis[8]={0};
void dfs(int x,LL var[]) {
	if(vis[x]==true || var[x]==0)return;
	vis[x]=1;
	dfs((x+1)%7,var);
	dfs((x-1+7)%7,var);
}
int curk = 0;
bool check(LL x[]) {
	if(fail(x))return false;
	//printf("x:");for(int i=0;i<7;i++)printf("%lld ", x[i]);
	int ans=0;
	memset(vis,0,sizeof(vis));
	bool haszero=false;
	for(int i=0;i<7;i++){
		if(x[i]>0 && vis[i]==0){
			dfs(i,x); ans++;
		}
	} 
	if(x[0]>0||x[6]>0)haszero=true;
	if(curk==0&&ans==1&&haszero==false)return false;
	if(ans<=1)return true;
	return false;
}
bool findsol(LL d[], LL x[]) {
	// x[i]+x[i+1]=d[i+1]
	pair<int,LL> f[8];
	f[0]=make_pair(1,0);
	for(int i=0;i<7;i++){
		//f[i]+f[i+1]=d[i+1]
		f[i+1]=make_pair(-f[i].first, d[(i+1)%7]-f[i].second);
	}
	if(f[7].second % 2) return false;
	LL var[7];
	var[0] = f[7].second / 2;
	for(int i=1;i<7;i++){
		var[i] = f[i].first * var[0] + f[i].second;
	}
	for(int i=0;i<7;i++)x[i]=var[i];
	return check(var);
}
bool solve(int k){
	curk = k;
	LL d[8];
	for(int i=0;i<7;i++)d[i]=c[i];
	for(int i=0;i<7;i++)d[i]-=k; d[0]--;

	if(fail(d))return true;
	//for(int i=0;i<7;i++)printf("%lld,", d[i]);printf("\n");
	LL x[8]={0};
	if(findsol(d,x)){
		//for(int i=0;i<7;i++)printf("%lld ",x[i]);printf("\n");
		printf("YES\n"); return true;
	}
	return false;
}

int main() {
	while(1){
		memset(c,0,sizeof(c));

		int now=0;c[0]++;
		for(int i=0;;i++){
			if(rand()%2==0)now++;else now--;
			now=(now%7+7)%7;
			c[now]++;
			if(now==0 && rand()%20==0){
				break;
			}
		}

		for(int i=0;i<7;i++){
			printf("%lld ", c[i]);
		}
		printf("\n");
		//solve(0); return 0;
		bool ac=0;
		for(int k=0;k<=2;k++){
			//printf("solve %d\n", k);
			if(solve(k)) {
				ac=1;
				break;
			}
		}
		if(!ac){
			printf("NO\n");
			return 0;
		}
	}
}