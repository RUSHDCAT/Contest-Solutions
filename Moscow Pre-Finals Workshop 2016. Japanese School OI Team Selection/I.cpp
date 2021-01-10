#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
int n, a[N], b[N], c[N], d[N], s[N];

vector< pair<int,int> > v[N];

vector<int> vec;
int id(int x) {
	return lower_bound(vec.begin(),vec.end(),x) - vec.begin() + 1;
}

int mn[N<<2], lz[N<<2];
void pushdown(int rt) {
	if(lz[rt]) {
		lz[rt<<1] += lz[rt]; mn[rt<<1] += lz[rt]; 
		lz[rt<<1|1] += lz[rt]; mn[rt<<1|1] += lz[rt];
		lz[rt] = 0;
	}
}
void build(int l,int r,int rt){
	if(l==r) {
		mn[rt] = s[l]; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
	mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
void update(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R){
		lz[rt] += -1; mn[rt] += -1; return;
	}
	int mid=(l+r)>>1; pushdown(rt);
	if(L<=mid) update(l,mid,rt<<1,L,R);
	if(R >mid) update(mid+1,r,rt<<1|1,L,R);
	mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
int query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) return mn[rt];
	int mid=(l+r)>>1; pushdown(rt); 
	int ans=1e9;
	if(L<=mid) ans = min(ans, query(l,mid,rt<<1,L,R));
	if(R >mid) ans = min(ans, query(mid+1,r,rt<<1|1,L,R));
	return ans;	
}

bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first == y.first) return x.second > y.second;
	return x.first < y.first;
}
struct Item {
	int x, y;
	bool operator < (const Item & o) const{
		if(y==o.y) return x > o.x;
		return y < o.y;
	}
};

int main() {
	scanf("%d",&n);

	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		v[a[i]].push_back( make_pair(b[i], 1) );
		vec.push_back(b[i]);
	}	
	
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&c[i],&d[i]);
		v[c[i]].push_back( make_pair(d[i], -1) );
		vec.push_back(d[i]);	
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(),vec.end()), vec.end());

	for(int i=1;i<=n;i++) {
		s[id(b[i])]++; s[id(d[i])]--;
	}
	//printf("\n");

	int sz = vec.size();
	for(int i=1;i<=sz;i++) s[i]+=s[i-1];
	build(1,sz,1);
	vector<Item> intervals;

	for(int i=1;i<=n;i++){
		vector<int> stk;
		sort(v[i].begin(), v[i].end(), cmp);
		for(auto p: v[i]) {
			//printf("%d %d\n", p.first, p.second);
			if(p.second == +1) stk.push_back(id(p.first));
			else {
				if (stk.size()) {
					//printf("# %d %d\n", vec[stk.back() - 1], p.first);
					intervals.push_back((Item){stk.back(),id(p.first)});
					stk.pop_back();
				}
			}
		}
		//printf("\n");
	}
	sort(intervals.begin(), intervals.end());

	build(1, sz, 1);
	int ans = 2 * n;
	for (auto p: intervals) {
		int l = p.x, r = p.y - 1;
		//printf("solve %d %d\n", l,r);
		if (l > r) {
			ans -= 2; continue;
		}
		if (query(1,sz,1,l,r) > 0) {
			ans -= 2; update(1,sz,1,l,r);
		}
	}		
	cout<<ans/2<<endl;
}



