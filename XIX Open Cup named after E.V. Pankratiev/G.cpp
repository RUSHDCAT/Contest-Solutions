#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n, d;

int main() {
	cin >> n >> d;
	vector<int> v;
	for(int i=0;i<10;i++) if(i!=d) v.push_back(i);

	int mn[30] = {0};
	for(int i=0;i<30;i++) mn[i] = 1e9;
	for (int i = 0; i <= 9999; i ++) {
		int x = i, s = 0;
		bool ok = 1;
		while (x) {
			s += x % 10; 
			if (x % 10 == d) ok = 0;
			x /= 10;
		}
		if (ok) {
			//printf("%d %d\n", i, s);
			if (s < 30)
				mn[s] = min(mn[s], i);
		}
	}
	int cnt = 0;
	vector<int> ans;
	while (n) {
		if (n < 30) {
			if (n > 0)
				printf("%d", mn[n]);
			for (int i = 0; i < cnt; i ++) {
				printf("%d", v.back());
			}
			return 0;
		}
		int x = v.back();
		n -= x;
		cnt ++;
	}
}



