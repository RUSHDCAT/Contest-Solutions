#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k; cin >> k;

	vector<int> t(k), a(k), b(k);
	for (int i = 0; i < k; i ++)
		cin >> t[i] >> a[i] >> b[i];

	int r; cin >> r;
	while (r --) {
		int ave, wsum; 
		cin >> ave >> wsum;	 

		LL cur = 0;
		for (int i = 0; i < k; i ++)  {
			cur += 1LL * a[i] * (t[i] - ave);
			wsum -= a[i];
		}
		if (wsum < 0) {
			cout << "no" << endl; continue;
		}
		vector< pair<LL,LL> > vec(k);
		for (int i = 0; i < k; i ++) 
			vec[i] = make_pair(t[i] - ave, b[i] - a[i]);

		//printf("cur = %lld\n", cur);

		bool ok = true;;

		{
			LL low = 0;
			sort(vec.begin(), vec.end());
			LL rem = wsum;
			for (int i = 0; i < k; i ++) {
				//printf("(%lld,%lld)", vec[i].first, vec[i].second);
				LL dt = min(rem, vec[i].second);
				rem -= dt;
				low += dt * vec[i].first;
			}
			if (rem > 0) ok = false;
			//printf(" low = %lld\n", cur + low);
			if (cur + low > 0) ok = false;
		}

		{
			LL high = 0;
			sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
			LL rem = wsum;
			for (int i = 0; i < k; i ++) {
				//printf("(%lld,%lld)", vec[i].first, vec[i].second);
				LL dt = min(rem, vec[i].second);
				rem -= dt;
				high += dt * vec[i].first;
			}
			if (rem > 0) ok = false;
			//printf(" high = %lld\n", cur + high);
			if (cur + high < 0) ok = false;
		}

		cout << (ok?"yes":"no") << endl;
	}
}