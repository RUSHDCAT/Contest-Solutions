#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

const int B = 3;
const int M = 5;

map< vector<int>, int > mp;
vector< vector<int> > res;
void cal(vector<int> v, int now, int tot, vector<int> done) {
	if (tot > B) return;
	if (now == v.size()) {
		if (tot >= 1) {
			//printf("==\n");
			//for (auto x: done) printf("%d ", x); printf("\n");
			res.push_back(done);
		} 
		return;
	}
	for (int i = 0; i < v[now]; i ++) {
		done.push_back(i);
		cal(v, now + 1, tot + 1, done);
		done.pop_back();
	}
	done.push_back(v[now]);
	cal(v, now + 1, tot, done);
}

vector< vector<int> > gen(vector<int> v) {
	res.clear();
	vector<int> done;
	cal(v, 0, 0, done);
	return res;
}
void p(vector<int> v) {
	//if (accumulate(v.begin(),v.end(),0) % (B + 1)) return;
	//if (mp[v]) return;
	for(auto x: v) printf("%d ", x); printf(": sg=%d, sum=%d\n", mp[v], accumulate(v.begin(),v.end(),0));
}
void l(vector<int> v) {
	for(auto x: v) printf("%d ", x); printf("\n");	
}
int solve(vector<int> v) {
	sort(v.begin(), v.end());
	if (mp.find(v) != mp.end()) return mp[v];
	vector< vector<int> > vs = gen(v);
	//l(v);
	bool vis[102] = {0};
	for (auto p: vs) {
		//l(p);
		vis[solve(p)] = 1;
	}
	for (int i = 0;; i ++) if (! vis[i] ) {
		mp[v] = i;
		p(v);
		return i;
	}
	assert(false);
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	vector<int> v = {5,5,5,5,5};
	solve(v);
}