#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	LL n; cin >> n; n *= 2;	
	int ans = 0;
	set< pair<LL,LL> > st;
	for (LL i = 1; i * i <= n; i ++) {
		if (n % i == 0) {
			LL a = i, b = n / i;
			// y + x = a
			// y - x = b - 1


			if ( (a + b - 1) % 2 == 0 ) {
				LL y = (a + b - 1) / 2;
				LL x = (a - (b - 1) ) / 2;
				
				if (x <= y){
					st.insert(make_pair(x, y));
				}
			}
			swap(a, b);
			if ( (a + b - 1) % 2 == 0 ) {
				LL y = (a + b - 1) / 2;
				LL x = (a - (b - 1) ) / 2;
				
				if (x <= y){
					st.insert(make_pair(x, y));
				}
			}
		} 
	}
	cout << st.size() << endl;
}