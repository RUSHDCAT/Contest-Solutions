#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
const LL MOD = 998244353;

int n, x, d[N];
LL inv[N];
LL mpow(LL a, LL x) {
	if(x==0) return 1;
	LL t = mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}

LL c(LL x, LL y) {
	LL ans = 1;
	for (LL i = x; i > x - y; i --) ans = ans * i % MOD;
	ans = ans * inv[y] % MOD;
	return ans;
}

int main() {
	inv[0]=1;
	for(int i=1;i<N;i++) inv[i] = inv[i-1] * mpow(i,MOD-2) % MOD;
	
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	
	vector< pair<LL,LL> > intervals; vector<int> sgn;
	LL x = 0; 
	intervals.push_back(make_pair(0, 0)); sgn.push_back(1);
	for(int i=1;i<=n;i++){
		if (d[i] > 0)
			intervals.push_back(make_pair(x + 1, x + d[i])), sgn.push_back(1);
		else
			intervals.push_back(make_pair(x - 1, x + d[i])), sgn.push_back(-1);
		x += d[i];
	}

	vector<LL> segs;
	for(int i=0;i<intervals.size();i++) {
		int l=min(intervals[i].first,intervals[i].second);
		int r=max(intervals[i].first,intervals[i].second);

		vector<LL> keyPoints;
		for(auto p: intervals) {
			if(p.first>=l && p.first<=r) keyPoints.push_back(p.first);
			if(p.second>=l && p.second<=r) keyPoints.push_back(p.second);
		}	
		sort(keyPoints.begin(),keyPoints.end());
		keyPoints.erase(unique(keyPoints.begin(),keyPoints.end()),keyPoints.end());

		if (sgn[i] == +1) {
			for (int j = 0; j + 1 < keyPoints.size(); j ++) {
				segs.push_back(1);
				if (keyPoints[j+1] - keyPoints[j] > 1)
					segs.push_back(keyPoints[j+1] - keyPoints[j] - 1);
			} 
			segs.push_back(1);
		} else {
			for (int j = keyPoints.size() - 1; j >= 1; j --) {
				segs.push_back(- 1);
				if (keyPoints[j] - keyPoints[j-1] > 1)
					segs.push_back(- (keyPoints[j] - keyPoints[j-1]));
			}
			segs.push_back(-1);
		}
	}
	for(auto p:intervals) printf("[%d,%d]\n", p.first,p.second);
	for(auto p: segs) printf("# %d\n", p);

	vector<int> rk(segs.size(), 0);
	int cur = 0;
	for (int i = 0; i < segs.size(); i ++) {
		if (segs[i] > 0) cur ++; else cur --; 
		rk[i] = cur;
	}

	LL mn = 1e12; for (int i = 0; i < segs.size(); i ++) mn = min(mn, segs[i]);
	for (int i = 0; i < rk.size(); i ++) rk[i] -= (mn - 1);
	int mx = *max_element(rk.begin(), rk.end());
	vector< vector<int> > dp(mx+1, vector<int>(segs.size() + 1, 0) );

	for (int i = 0; i < mx; i ++) {
		for (int j = -1; j < segs.size(); j ++) {
			for (int k = j + 1; k < segs.size(); k ++) {
				
			}
		}
	}

}