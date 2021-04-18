#include <bits/stdc++.h>
using namespace std;
const int six = 3;
set<vector<int> > s;
int main(){
	map<vector<int>,bool> m;
	m[{}] = false;
	function<bool(vector<int>)> f = [&](vector<int> v){
		sort(v.begin(),v.end());
		if(m.count(v)) return m[v];
		vector<int> tmp;
		function<bool(int,int)> dfs = [&](int dep,int rem){
			if(dep==(int)v.size()) return rem<six&&!f(tmp);
			int x = v[dep];
			for(int i=0;i<=x;i++){
				if(rem-(!!i)<0) continue;
				if(x-i>0) tmp.push_back(x-i);
				if(dfs(dep+1,rem-(!!i))) return true;
				if(x-i>0) tmp.pop_back();
			}
			return false;
		};
		m[v] = dfs(0,six);
		if(!m[v]){
			cout<<v.size()<<' ';
			cout<<"{";
			for(int i: v) cout<<i<<',';
			cout<<"}";
			cout<<endl;
			map<int,int> cnt;
			for(int i=1;i<6;i++) cnt[i] = 0;
			for(int i: v) cnt[i]++;
			vector<int> t;
			for(auto [k,v]: cnt){
				cout<<v%(six+1)<<' ';
				t.push_back(v%(six+1));
			}
			s.insert(t);
			cout<<endl;
		}
		return m[v];
	};
	vector<int> v;
	function<void()> dfs = [&](){
		if(!f(v)){
			vector<int> t = v;
			sort(t.begin(),t.end());
			// if(!s.count(t)){
			// 	cout<<t.size()<<' ';
			// 	cout<<"{";
			// 	for(int i: t) cout<<i<<',';
			// 	cout<<"}";
			// 	cout<<endl;
			// 	s.insert(t);
			// }
		}
		if(v.size()<14){
			for(int i=1;i<=5;i++){
				v.push_back(i);
				dfs();
				v.pop_back();
			}
		}
	};
	dfs();
	for(auto i: s){
		for(int j: i){
			cout<<j<<' ';
		}
		cout<<endl;
	}
}