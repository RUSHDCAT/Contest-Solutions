#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;

const LL mod = 1LL<<31;

LL ran() {
	return (1LL*rand()*rand()%mod*rand()%mod ^ rand()) % (mod-1) + 1;
}
vector<int> vec[32],vec2[32];
int n;
LL a[N], b[N];
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


bool chk(LL x) {
	set<int> s;
	for(int i=1;i<=n;i++){
		s.insert(a[i] * x % mod);
	}
	for(int i=1;i<=n/2;i++){
		if(s.find(b[i]) == s.end())return false;
	}
	printf("%lld\n", x); fflush(stdout);
	exit(0);
	return true;
}
int main() {
	//LL X = 13;
	//srand(clock());
	scanf("%d", &n);
	vector<int> las(33,1);

	int T = 0;
	for (int i=1;i<=n;i++) {
		while(1){
			int x = rand() % 31;
			T ++;
			if (T <= 100) x = 0; 
			if (x == 0 && las[x] >= 100) continue;
			if (1LL * las[x] * (1LL << x) <= mod - 1) {
				a[i] = 1LL * las[x] * (1LL << x);
				las[x] += 2;
				int cnt=0;
				LL y=a[i]; while(y%2==0) {y/=2; cnt++;};	
				vec[cnt].push_back(y);
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++) {
		printf("%lld%c", a[i]," \n"[i==n]);
	}
	fflush(stdout);
	
	for(int i=1;i<=n/2;i++){
		int x; 
		scanf("%d",&x); 
		//x = a[i] * X % mod;
		b[i]=x;
		int cnt=0;
		LL y=x; while(y%2==0) {y/=2; cnt++;};		
		vec2[cnt].push_back(y);
		//printf("# cnt = %d, y = %lld\n", cnt, y);
	}

	for(int i=0;i<=30;i++){
		if(vec[i].size()>0) {
			//printf("#\n");
			//printf("i=%d\n", i);
			//printf("%d %d\n", vec[i].size(),  vec2[i].size());
			//printf("# "); for(auto x: vec[i]) printf("%d ", x); printf("\n");
			//printf("$ "); for(auto x: vec2[i]) printf("%d ", x); printf("\n");
			map<int,int> mp;
			for(auto x: vec[i]) {
				LL iv = inv(x, mod);
				for(auto y: vec2[i]) {
					LL c = 1LL * iv * y % mod;
					//printf("! %lld\n", c);
					mp[c] ++;
				}
			}
			vector< pair<int,int> > vec;
			for(auto p: mp) {
				vec.push_back(make_pair(p.second, p.first));
			}
			sort(vec.begin(), vec.end());
			reverse(vec.begin(),vec.end());
			for(auto p: vec) {
				chk(p.second);
			}
			return 0;
		}
	}

	assert(0);
}