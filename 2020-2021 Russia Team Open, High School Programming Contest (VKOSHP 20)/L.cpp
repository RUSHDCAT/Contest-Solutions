#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;

struct Item {
	LL w, cost; int id;
	bool operator < (const Item &o) const{
		return 1LL * cost * o.w > 1LL * o.cost * w;
	}
} it[N];

int n;LL w;
pair<int,int> bit[N];
void add(int pos,pair<int,int> x) {
	while(pos < N) {
		bit[pos] = max(bit[pos], x);
		pos += pos & (-pos);
	}
}
void clear(int pos) {
	while(pos < N) {
		bit[pos] = make_pair(0,0);
		pos += pos & (-pos);
	}
}
pair<int,int> query(LL pos) {
	pos = min(pos, N - 1LL);

	pair<int,int> ans = make_pair(0,0);
	while(pos > 0) {
		ans = max(ans, bit[pos]);
		pos -= pos & (-pos);
	}
	return ans;
}

void clearAll() {
	for(int i=1;i<=n;i++) {
		if(it[i].w <= w && it[i].w * 2 > w) clear(it[i].w);
	}
}
void prt(vector<int> &ans) {
	printf("%d\n", ans.size());
	for(auto x: ans) {
		printf("%d ", x);
	}
	if(ans.size()) printf("\n");
}
int main() {
	for(int i=0;i<N;i++) bit[i] = make_pair(0,0);

	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&w);
		vector<Item> vec;
		int mx = 0;
		for(int i=1;i<=n;i++) {
			it[i].id = i;
			scanf("%lld%lld",&it[i].w,&it[i].cost);
			if (it[i].w * 2 <= w) vec.push_back(it[i]);
			else if (it[i].w <= w) {
				add(it[i].w, make_pair(it[i].cost, i));
			}
		}
		sort(vec.begin(), vec.end());

		LL s=0,c=0,lim=3*w/2;
		LL res = query(lim - s).first;
		vector<int> ans;
		for(auto p: vec){
			if(s+p.w<=lim) {
				res = max(res, c + query(lim - s).first);
				s+=p.w; c+=p.cost;
				res = max(res, c + query(lim - s).first);
			}
		}
		//printf("res = %lld\n",res);
		s=0; c=0;

		if(query(lim - s).first == res) {
			pair<int,int> x = query(lim - s);
			if (x.second > 0) 
				ans.push_back(x.second);
			prt(ans); clearAll(); continue;
		}
		for(auto p: vec) {
			if(s+p.w <= lim) {
				if (c + query(lim - s).first == res) {
					pair<int,int> x = query(lim - s);
					if (x.second != 0) ans.push_back(x.second);
					prt(ans); clearAll(); break;
				} 	 
				s+=p.w; c+=p.cost; ans.push_back(p.id);
				if (c + query(lim - s).first == res) {
					pair<int,int> x = query(lim - s);
					if (x.second != 0) ans.push_back(x.second);
					prt(ans); clearAll(); break;
				} 				
			}
		}

	}
}