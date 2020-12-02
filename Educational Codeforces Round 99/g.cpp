#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n,s;
multiset<LL> mn[N];
struct operat {
	int type, y, v;
	void read() {
		char s[5]; scanf("%s", s);
		if(s[0] == 's') {
			type=1; scanf("%d%d",&y,&v);
		}
		if(s[0] == 'i') {
			type=2; scanf("%d",&y);
		}
		if(s[0] == 'e') {
			type=3;
		}
	}
} op[N];

int pat[N],stk[N],top=0,dfn=0;
unordered_map<int,LL> mp[N]; 
LL det[N];


int weight[N],value[N];
void upd(int u,int x,LL val){
	if(mp[u].find(x) == mp[u].end()){
		mp[u][x] = val; mn[u].insert(val);
	}
	else {
		if (val < mp[u][x]) {
			mn[u].erase(mn[u].find(mp[u][x]));
			mn[u].insert(val);
		}
		mp[u][x] = min(mp[u][x], val);
	}
}
void merge(int u,int v){
	int val = weight[v];
	if(mp[u].find(val) == mp[u].end()) return;

	if(mp[u].size() > mp[v].size()) {
	//if(1){
		LL tmp = mp[u][val]; 
		mp[u].erase(mp[u].find(val));
		mn[u].erase(mn[u].find(tmp));
		for(auto p:mp[v]){
			upd(u, p.first, tmp + (mp[v][p.first] + det[v]));
		}
	} else {
		/*
		printf("u det=%lld :",det[u]);
		for(auto p: mp[u]) {
			printf("(%d,%lld)", p.first,p.second + det[u]);
		} printf("\n");

		printf("v det=%lld :",det[v]);
		for(auto p: mp[v]) {
			printf("(%d,%lld)", p.first,p.second + det[v]);
		} printf("\n");
		*/
		LL tmp = mp[u][val] + det[u];
		det[v] += tmp;
		LL tmpval = mp[u][val] + mp[v][val];
		mp[u].erase(mp[u].find(val)); mn[u].erase(mn[u].find(mp[u][val]));
		for(auto p:mp[u]){
			if(p.first != val)
			upd(v,p.first,(p.second+det[u])-det[v]);
		}
		upd(v,val,tmpval);
		swap(mp[u],mp[v]); swap(mn[u],mn[v]); swap(det[u],det[v]);
		/*
		printf("u det=%lld :",det[u]);
		for(auto p: mp[u]) {
			printf("(%d,%lld)", p.first,p.second + det[u]);
		} printf("\n");
		*/
	}
	mp[v].clear();
}
void merge2(int u,int v) {
	LL tmp = *(mn[u].begin());
	det[u] += weight[v];
	if(mp[u].find(value[v]) != mp[u].end()) {
		mn[u].erase(mn[u].find(mp[u][value[v]]));
	}
	mp[u][value[v]] = tmp - weight[v]; mn[u].insert(tmp - weight[v]);
	
} 
void wash(int u) {
	if(mp[u].find(s) != mp[u].end()){
		//printf("u=%d, mp[u][s]=%lld\n", u,mp[u][s]);
		mn[u].erase(mn[u].find(mp[u][s]));
		mp[u].erase(mp[u].find(s));
	}
}
void build(int l,int r,int rt){
	
	if(l>r)return;

	++dfn; weight[rt] = op[l].y;
	assert(dfn == rt);
	mp[rt][ op[l].y ] = 0; mn[rt].insert(0);

	if(l==r){
		weight[rt] = op[l].v;
		value[rt] = op[l].y;
		wash(rt);
		return;
	}
	int now=l+1;

	while(now < r){
		int u=rt, v=dfn+1;
		build(now,pat[now],dfn+1);
		if(pat[now] > now) merge(u,v);	
		if(pat[now] ==now) merge2(u,v);

		now = pat[now] + 1;
		wash(u); 
	}
}
int main() {
	scanf("%d%d",&n,&s);
	op[0]=(operat){2,0,0};
	for(int i=1;i<=n;i++) op[i].read();
	for(int i=1;i<=n;i++) {
		if(op[i].type==2){
			stk[++top]=i; 
		}
		if(op[i].type==3){
			pat[stk[top]]=i; 
			pat[i]=stk[top];
			--top;
		}
		if(op[i].type==1){
			pat[i]=i;
		}
	}
	pat[0]=n+1;
	build(0,n+1,1);
	printf("%lld\n", (*mn[1].begin()) + det[1]);
}