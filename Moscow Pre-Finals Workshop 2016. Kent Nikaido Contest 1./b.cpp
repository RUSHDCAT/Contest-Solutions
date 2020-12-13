#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

set< vector<int> > st;
int fac[20],kk;
const bool printlog = false;

int A[20], B[20];

int n, k, l;
void add(vector<int> v, int a[]) {
	bool vis[20] = {0};
	int p[20];
	for(int i=0;i<v.size();i++) p[i+1]=v[i];
	int len = 0;
	for(auto x: v) {
		if(vis[x]) continue;
		int y=x;
		len ++;
		while(1){
			vis[y]=1; y=p[y]; 
			if(vis[y]) break;
		}
	}
	a[len] ++;
}

void check(int n, int k) {
	st.clear();
	vector<int> v;
	for(int i=1;i<=n;i++) v.push_back(i);
	queue< vector<int> > q;
	q.push(v); st.insert(v);
	while(q.size()) {
		vector<int> vec = q.front();  q.pop();
		for(int i=k-1;i<vec.size();i++) {
			vector<int> tmp;
			for(int j=0;j<i-k+1;j++) tmp.push_back(vec[j]);
			tmp.push_back(vec[i]);
			for(int j=i-k+1;j<i;j++) tmp.push_back(vec[j]);
			for(int j=i+1;j<vec.size();j++) tmp.push_back(vec[j]);
			if(st.count(tmp) == 0) {
				st.insert(tmp); q.push(tmp);
			}
		}
	}

	printf("n=%d,k=%d,total = %d, fac[%d]=%d\n", n,k,st.size(),n,fac[n]);

	for(auto v:st) add(v,A);

	v.clear(); for(int i=1;i<=n;i++) v.push_back(i);
	do{
		add(v,B);
	}while(next_permutation(v.begin(),v.end())); 

	LL sum=0;
	printf("A: ");
	for(int i=1;i<=n;i++){
		printf("%d ", A[i]); 
		//printf("add %lld * %d\n", (LL)pow(kk,i),A[i]);
		sum+=(LL)pow(kk,i)*A[i];
	}
	printf("sum=%lld\n", sum);
	sum/=st.size();

	printf("\nB: ");
	for(int i=1;i<=n;i++){
		printf("%d ",B[i]);
	}
	printf("\n");

	printf("ans = %lld\n", sum);
	if(printlog) {
		for(auto v:st){
			for(auto x:v) {
				printf("%d ", x);
			}
			printf("\n");
		}
	}
}

int main() {
	fac[0] = 1; for(int i=1;i<12;i++)fac[i]=fac[i-1]*i;
	scanf("%d%d%d",&n,&k,&l);kk=k;
	check(n,l);
}