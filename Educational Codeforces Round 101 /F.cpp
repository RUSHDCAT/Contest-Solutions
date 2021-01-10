#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k;
int l[N];

bool cmp(pair<int,int> A, pair<int,int> B) {
	if (A.first == B.first) return l[A.second] < l[B.second];
	return A.first > B.first;
}
bool check(int lim) {
	vector< pair<int,int> > vec;
	for(int i=1;i<=n;i++){
		// k + (l+1)/2 <= lim;
		int mxdep = lim - l[i]/2 - 1;
		vec.push_back(make_pair(mxdep, i));
		//printf("mxdep = %d, i = %d\n", mxdep, i);
	}
	sort(vec.begin(),vec.end(),cmp);

	priority_queue<int> q;
	q.push(- 1);

	LL sum = 1;
	while (q.size()) {
		if(sum >= k) return true;
		int dep = - q.top(); q.pop();
		bool fail = false;
		while (vec.size()) {
			pair<int,int> now = vec.back(); vec.pop_back();
			//printf("now = %d %d\n", now.first, now.second);
			if (dep > now.first) {
				fail = true;
				break;
			} else {
				for(int i=1;i<=(l[now.second]-1)/2;i++) {
					if(dep + 1 + i > lim) break;
					q.push(-(dep + 1 + i)); //printf("in %d\n", dep+1+i);
				}
				for(int i=1;i<=l[now.second]/2;i++) {
					if(dep + 1 + i > lim) break;
					q.push(-(dep + 1 + i)); //printf("in %d\n", dep+1+i);
				}
				break;
			}
		}
		if(fail) break; 
	} 
	if(sum >= k) return true;
	return false;
}

int main() {
	scanf("%d%d",&n,&k);
	LL sum=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]); sum+=l[i]-2;
	}
	if(sum < k) return !printf("-1\n");
	//check(5); return 0;
	int l=1,r=1e9+7;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid; else l=mid;
	}
	printf("%d\n", r - 1);
}
