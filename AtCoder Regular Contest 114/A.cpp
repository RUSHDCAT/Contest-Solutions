#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 50 + 10;
int n, x[N];
bool vis[N], flag[N];

void init() {
	for(int i=2;i<N;i++){
		for(int j=i+i;j<N;j+=i) {
			vis[j]=1;
		}
	}
}

int main() {
	scanf("%d", &n);
	LL res = 1e18;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x[i]);
	}	
	int a[4] = {2,3,5,7};
	for (int i = 0; i < 1<<4; i ++) {
		LL ans = 1;
		for (int bit = 0; bit < 4; bit ++) if (i >> bit & 1)
			ans = ans * a[bit];	

		for (int j = 1; j <= n; j ++) {
			int tmp = x[j];
			bool find = false;
			for (int bit = 0; bit < 4; bit ++){
				int mod = a[bit];
				if (tmp % mod == 0) { 
					if ((i >> bit & 1) && (tmp % mod == 0)) find = true;
					while (tmp % mod == 0) tmp /= mod;
				}
			}
			if (!find && tmp == 1) {
				ans = 1e18; break;
			}
			if (!find && tmp > 1)
				ans *= tmp;
		}
		res = min(res, ans);
	}

	cout << res << endl;
}