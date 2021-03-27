#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
int main() {
	cin >> n;

	set<int> s;
	for (int i = 1; i <= 10; i ++) {
		s.insert((i+i+n-1)*n/2 % 2);
	}
	if (s.size() == 2) printf("Either\n");
	else if ((*s.begin())==0) printf("Even\n"); else printf("Odd\n");
}