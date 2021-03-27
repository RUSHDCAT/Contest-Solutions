#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, p[N];
int ld[N], lu[N], rd[N], ru[N];
multiset<int> s;
void del(int pos) {
	s.erase(s.find(lu[pos]));
	s.erase(s.find(ru[pos]));
}
void ins(int pos) {
	s.insert(lu[pos]);
	s.insert(ru[pos]);
}
bool can(int c,int l, int r) {
	bool ok=0;
	int lef=c-l+1, rig=c+r-1;
	//l
	if((l>=r||lu[lef]>=r) && ((l>=4 && l%2==0)||lu[lef]>=l||l==2) )  ok=1;
	
	//l+1
	if(l-1>=r && ((l-1>=4 && (l-1)%2==0)||(l-1==2)) ) ok=1;
	
	//r	
	if((r>=l||ru[rig]>=l) && ((r>=4 && r%2==0)||ru[rig]>=r||r==2) ) ok=1;
	
	//r-1
	if(r-1>=l && ((r-1>=4 && (r-1)%2==0)||(r-1==2)) ) ok=1;
	return !ok;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &p[i]);

	for (int i = 1; i <= n; i ++) {
		lu[i] = ld[i] = 1;
		if (i >= 2 && p[i] > p[i-1]) ld[i] = ld[i-1] + 1;
		if (i >= 2 && p[i] < p[i-1]) lu[i] = lu[i-1] + 1;
	}
	for (int i = n; i >= 1; i --) {
		ru[i] = rd[i] = 1;
		if (i < n && p[i+1] > p[i]) ru[i] = ru[i+1] + 1;
		if (i < n && p[i+1] < p[i]) rd[i] = rd[i+1] + 1;
	}

	
	for (int i = 1; i <= n; i ++) {
		ins(i);
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (ld[i] == 1 && rd[i] == 1) continue;

		if (ld[i] > 1 && rd[i] > 1) {
			for (int x = i - ld[i] + 1; x < i + rd[i]; x ++) del(x);
			int mx = s.size()==0?0:(*s.rbegin());
			mx = max(mx, lu[i-ld[i]+1]);
			mx = max(mx, ru[i+rd[i]-1]);
			for (int x = i - ld[i] + 1; x < i + rd[i]; x ++) ins(x);
			
			bool ok=true;
			if(mx>=max(ld[i],rd[i])) ok=false;
			if(ok) {
				ok = can(i, ld[i], rd[i]);
			}
			if (ok) ans ++;
		}
		//printf("i=%d,ans=%d\n", i,ans);
	}
	printf("%d\n", ans);
}