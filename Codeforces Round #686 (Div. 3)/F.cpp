#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int n, a[N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		multiset<int> s;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		int mx1=0,mx2=0;
		bool ok = 0;
		for(int i=1,j=n;i<j;i++) {
			s.erase(s.find(a[i]));
			mx1 = max(mx1, a[i]);
			if (mx1 == mx2 && s.size() && mx1 == *s.begin()) {
				ok = true;
				printf("[%d, %d]\n", i + 1, j + 1);
				printf("YES\%d %d %d\n", i, j - i + 1, n - j - 1);
			}
			while (mx2 <= mx1 && j > i + 1) {
				mx2 = max(mx2, a[j]);
				s.erase(s.find(a[j]));
				printf("[%d %d]", i+1, j-1);
				-- j;		
				if (mx1 == mx2 && mx1 == *s.begin()) {
					ok = true;
					printf("YES\n%d %d %d\n", i, j-i, n-j);
					break;
				}
			}
			if (ok) break;
		}
		if (ok == false) {
			printf("No\n");
		}
	}
}


