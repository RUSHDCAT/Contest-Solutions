#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
int cnt[N];
 
int x[N],xx[N],xy[N];
 
int paigugou, need;
int solve(int l,int r){
	if(a[l]==paigugou || a[r]==paigugou) return 0;
	int sum=r-l;
	int cnt=0;
	vector<int> pos;
	for(int i=l;i<r;i++){
		if((a[i]==paigugou) != (a[i+1]==paigugou)) cnt++;
	}
	return sum - cnt;
}
 
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		//n=rand()%10+1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			//a[i]=rand()%4+1;
			//printf("%d ", a[i]);
		}
		//printf("\n");

		/*
		int R=1e9,p[20];
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			bool ok=1; int ans=0;
			for(int i=2;i<=n;i++){
				if(a[p[i]] == a[p[i-1]]) {
					ok=0; break;
				}
				if(abs(p[i] - p[i-1]) > 1) ans++;
			}
			if(ok) R=min(R,ans);
		}while(next_permutation(p+1,p+1+n));

 		if(R==1e9) R=-1;
 		printf("ac %d\n", R);
		*/
		for(int i=1;i<=n;i++){
			cnt[a[i]]=0; x[a[i]]=xx[a[i]]=xy[a[i]]=0;
		}
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,cnt[a[i]]);
		if(mx*2>n+1){
			//assert(R==-1);
			printf("-1\n");continue;
		}
 
		vector< pair<int,int> > vec;
 
		int tot=0;
		for(int l=1,r=1;l<=n;l=r+1){
			++tot;
			r=l;
			while(r+1<=n && a[r+1]!=a[r]) ++r;
			//printf("[%d,%d]\n", l,r);
			vec.push_back(make_pair(l,r));
			if(l==r){
				x[a[l]]++;
			}
			if(l<r){
				if(a[l]==a[r]){
					xx[a[l]]++;
				}else{
					xy[a[l]]++; xy[a[r]]++;
				}
			}
		}
 
		set<int> st;for(int i=1;i<=n;i++)st.insert(a[i]);
		paigugou = -1; need = -1;
		for(auto v:st){
			int a=x[v]+xx[v];
			int b=tot-a-xy[v];
			if(a-b>1){
				paigugou = v; need = a-(b+1); break;
			}
		}

		if(paigugou == -1) {
			//assert(R==tot-1);
			printf("%d\n", tot - 1);
		} else {
			printf("%d\n", tot - 1 + need);
		}
	}
}