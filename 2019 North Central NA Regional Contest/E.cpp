#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9 + 7;
int n, k, a[N], las[N];
pair<int,int> mn[N<<2];
void build(int l, int r, int rt) {
	if (l == r) {
		mn[rt] = make_pair(a[l], l); return;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
pair<int,int> query(int l, int r, int rt, int L, int R) {
	if (L<=l&&r<=R) return mn[rt];
	int mid = (l+r)>>1;
	pair<int,int> ans = make_pair(inf, inf);
	if (L<=mid) ans=min(ans, query(l,mid,rt<<1,L,R));
	if (R >mid) ans=min(ans, query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
void update(int l,int r,int rt,int pos,int x){
	if(l==r) {
		mn[rt]=make_pair(x,l); return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,rt<<1,pos,x);
	else update(mid+1,r,rt<<1|1,pos,x);
	mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
vector<int> vec[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cin >> n >> k;

	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		las[a[i]] = i;
		vec[a[i]].push_back(i);
	}
	build(1, n, 1);

	set<int> s; 
	for (int i = 1; i <= k; i ++) 
		s.insert(las[i]);

	int l = 1;
	for (int i = 1; i <= k; i ++) {
		int r = (*s.begin());
		pair<int,int> mn = query(1,n,1,l,r);
		//printf("# %d %d\n", mn.first, mn.second);
		for (auto x: vec[mn.first]) {
			//printf("x=%d\n", x);
			update(1,n,1,x,inf);
		}
		l = mn.second + 1;
		s.erase(las[mn.first]);
		//printf("## \n");
		cout << mn.first << " \n"[i==k];
	}
}