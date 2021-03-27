#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n, m, k, a[N];
pair<int,int> p[N];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);	p[i]=make_pair(a[i],i);
	}
	if(k%m) return !printf("impossible\n");
	sort(p+1,p+1+n);
	reverse(p+1,p+1+n);
	int p1=k/m, p2=k/m+1;


	LL sum=0, cnt=0;
	vector<int> ans;

	while(true) {
		int pp1 = p1, pp2 = p2;
		while (p1 >= 1) {
			if (sum <= p[p1].first * cnt) {
				ans.push_back(p[p1].second); 
				sum += m, cnt ++;
				//printf("# (%d, %d)\n", p[p1].first, p[p1].second);
				p1 --;
			} else break;
		}
		while (p2 <= n) {
			if (sum >  p[p2].first * cnt) {
				ans.push_back(p[p2].second); 
				sum += 0, cnt ++;
				//printf("$ (%d, %d)\n", p[p2].first, p[p2].second);
				p2 ++;
			} else break;
		}
		if (pp1 == p1 && pp2 == p2) break;
	}

	if (ans.size() == n) {
		for(auto x: ans) printf("%d ", x);
	} else {
		return !printf("impossible\n");
	}
}