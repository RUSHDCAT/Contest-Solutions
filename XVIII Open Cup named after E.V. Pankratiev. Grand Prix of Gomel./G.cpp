#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
LL l[N], r[N];
const int inf = 1e9 + 7;

bool isup(pair<LL,LL> A, pair<LL,LL> B,pair<LL,LL> C) {
	pair<LL,LL> x_1 = make_pair(B.first - A.first, B.second - A.second);
	pair<LL,LL> x_2 = make_pair(C.first - B.first, C.second - B.second);
	return x_1.first * x_2.second - x_1.second * x_2.first >= 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%lld%lld", &l[i], &r[i]);
	}

	vector< pair<LL,LL> > stk_r;
	stk_r.push_back(make_pair(0, inf));
	stk_r.push_back(make_pair(0,r[0]));
	for (int i = 1; i < n; i ++) {
		while (stk_r.size() >= 2) {
			int sz = stk_r.size();
			pair<LL,LL> A = stk_r[sz - 2];
			pair<LL,LL> B = stk_r[sz - 1];
			pair<LL,LL> C = make_pair(i, r[i]);
			if (! isup(A,B,C)) {
				stk_r.pop_back();
			} else {
				break;
			}
		}
		stk_r.push_back(make_pair(i, r[i]));
	}

	vector< pair<LL,LL> > stk_l;
	stk_l.push_back(make_pair(0, -inf));
	stk_l.push_back(make_pair(0,l[0]));
	for (int i = 1; i < n; i ++) {
		while (stk_l.size() >= 2) {
			int sz = stk_l.size();
			pair<LL,LL> A = stk_l[sz - 2];
			pair<LL,LL> B = stk_l[sz - 1];
			pair<LL,LL> C = make_pair(i, l[i]);
			//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   printf("(%lld,%lld)(%lld,%lld)(%lld,%lld)\n", A.first,A.second,B.first,B.second,C.first,C.second);
			if (isup(A,B,C)) {
				stk_l.pop_back();
			} else {
				break;
			}
		}
		stk_l.push_back(make_pair(i, l[i]));
	}

	printf("convex R\n");
	for (int i = 1; i < stk_r.size(); i ++) printf("%lld %lld\n", stk_r[i].first, stk_r[i].second);

	printf("convex L\n");
	for (int i = 1; i < stk_l.size(); i ++) printf("%lld %lld\n", stk_l[i].first, stk_l[i].second);

	vector<int> k;
	for (int i = 1; i + 1 < stk_r.size(); i ++) {
		
	}
}








