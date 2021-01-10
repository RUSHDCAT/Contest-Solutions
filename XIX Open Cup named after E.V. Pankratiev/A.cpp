#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int seed;
int Random() {
	seed = (1LL * seed * 1234567893 + 151515151) % (1LL<<31);
	return seed % 5;
}
bool chk(int x) {
	seed = x;
	if (Random() == 1 && Random() == 3 && Random() == 2 && Random() == 3 && Random() == 0 && Random() == 0 && Random() == 4 && Random() == 2)
		return 1;
	return 0;
}
int hash(string s) {
	int res = 0;
	for (int i = 0; s[i]; i ++) {
		res = (1LL * res * 31 + s[i]) % (1LL<<31);
	}
	return res;
}
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(b==0) {
        x=1,y=0; return a;
    }
    LL ans=exgcd(b,a%b,y,x);
    y-=(a/b)*x; return ans;
}

LL inv(LL a,LL b) {
    LL x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
const int iv = 1619076733;
const LL mod = 1LL<<31;

int pre(int x) {
	return (1LL * (x - 151515151) * iv % mod + mod) % mod;
}

int A[8] = {484,467,469,363,621,504,291,503};
int check(int x) {
	for(int i=7;i>=0;i--){
		int sum=500;
		for(int j=0;j<10000;j++){
			x=pre(x);
			sum+=x%3-1;
		}
		if(sum!=A[i]) return false;
	}
	return true;
}

int main() {
	
	freopen("out.txt", "r", stdin);
	int x;
	while (~ scanf("%d", &x)) {
		if(check(x)) {
			printf("%d\n", x);
		}
	}

	//iv = inv(1234567893, 1LL<<31);
	//printf("# %lld\n", iv);
	/*
	
	freopen("out.txt","w",stdout);
	for (LL i = 0; i < (1LL<<31); i ++) {
		if (chk(i)) {
			printf("%d\n", i);
		}
	} 
	*/
	
}