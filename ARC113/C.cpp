#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

char s[N];
int sum[30][N];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 26; j ++) sum[j][i] = sum[j][i-1];
		sum[s[i] - 'a'][i] ++;
	}

	LL ans = 0;

	pair<int,int> nex = make_pair(n + 1, n + 1);
	for (int i = n, j = n; i >= 1; i = j) {
		while (j >= 1 && s[i] == s[j]) -- j;
		if (i - j >= 2) {
			int l = i + 1, r = nex.first - 1;
			ans += r - l + 1 - (sum[s[i]-'a'][r] - sum[s[i]-'a'][l-1]);
			if (s[nex.first] != s[i])
				ans += n - nex.first + 1;
			nex = make_pair(j + 1, i);
		}
	}	
	cout << ans << endl;
}