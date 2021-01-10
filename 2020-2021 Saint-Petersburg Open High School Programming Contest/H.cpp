#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;

int main() {
	int n;
	scanf("%d",&n);
	vector< pair<int, pair<int,int> > > vec(n);
	vector<int> cnt(n*2 + 10, 0);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d",&vec[i].second.first, &vec[i].second.second); vec[i].first = i;
		cnt[ vec[i].second.first ] ++;
		cnt[ vec[i].second.second ] ++; 
	}
	
}