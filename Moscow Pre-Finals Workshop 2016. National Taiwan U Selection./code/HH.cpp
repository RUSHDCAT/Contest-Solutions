#include<cstdio>
#define LL long long
using namespace std;
const int maxn = 1e6 + 5;
int mod, phi;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
    scanf("%d", &mod), phi = mod - 1;
    for(register int i = 2, p = 1; i <= mod; ++i, p = 1) {
    	if(gcd(i, mod) != 1) continue;
    	for(register int a = i; a != 1; (a *= i) %= mod, ++p) ;
    	if(p == phi) {printf("%d\n", i);return 0;}
    }
    return 0;
}