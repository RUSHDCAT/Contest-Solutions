#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000000 + 10;
int d[N];
int main() {
	int mx=0;
	for(int i=1;i<N;i++){
		mx=max(mx,d[i]);
		for(int j=1;j<N;j+=i)d[j]++;
	}
	printf("%d\n", mx);
}