#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000000 + 10;
int prime[N], cnt = 0;
bool vis[N]; int mius[N];

void getPrime() {
    mius[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ cnt] = i;
            mius[i] = -1;
        }
        for (int j = 1; j <= cnt && prime[j] * i < N; j ++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) {           
                mius[prime[j] * i] = 0;
                break;
            } else {
                mius[prime[j] * i] = mius[i] * -1;
            }
        }
    }
    for(int i=1;i<N;i++)mius[i]=mius[i-1]+(i%2==1?mius[i]:0);
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
LL brute(LL m, LL n) {
	int ans=0;
	for (int s=1;s<=m;s++){
		for(int t=1;t<=s;t++){
			if(gcd(s+t,s-t)==1 && s+t<=n && 2*s<=m) {
				printf("! %d %d\n", s+t,s-t);
				ans++;
			}
		}
	}
	return ans;
}
LL sum(LL x) {
	return x * (x+1) / 2; 
}
LL f(int m, int n) {
	/*
	int res=0;
	for(int x=1;x<=n;x++){  
		for(int y=0;y<x;y++){
			if(x%2==1 && y%2==1 && x+y<=m) {
				res++;
			}
		}
	}
	int ans = 0;
	// x' <= (n-1)/2
	// x'+y' <= (m-2)/2
	// x' > y'
	for(int x=1;x<=(n-1)/2;x++){
		for(int y=0;x+y<=(m-2)/2 && y<x;y++){
			ans++;
		}
	}
	*/
	LL result = sum((n-1)/2);

	int y_2 = (n-1)/2 - 1;
	int y_1 = (m-2)/2 - (n-1)/2;
	if (y_1 <= y_2) {
		LL r = y_2 - y_1;
		LL l = r % 2;
		result -= (r+l) * ((r-l)/2 + 1) / 2;
	}

	//ssert(ans == res);
	//assert(ans == result);
	return result;
}

int T;
int main() {
	getPrime();
	scanf("%d", &T);
	while (T --) {
		int n,m;
		scanf("%d%d", &n, &m);
		if (n > m) swap(n, m);
		if (n == 1 && m == 1) {
			printf("1\n"); continue;
		}
		if (n == 1) {
			printf("0\n"); continue;
		}
		LL ans=0;
		for(int i=1,nex;i<=n;i=nex+1){
			nex=min(n/(n/i), m/(m/i));
			// printf("[%d, %d]\n", i,nex);
			int miusum = mius[nex] - mius[i-1];
			ans += miusum * f(m/i, n/i);
		}
		printf("%lld\n", ans);
	}
}





