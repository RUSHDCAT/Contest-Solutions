#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
vector<int> d[N];
int f[N];

int main() {
	ios::sync_with_stdio(false);

	int n;	
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + i; j <= n; j += i)
			d[j].push_back(i);
	}

	f[1] = 1;
	for (int i = 2; i <= n; i ++) {
		for (auto x: d[i]) {
			f[i] = max(f[i], f[x] + 1); 
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << f[i] << " ";
	cout << endl;
}