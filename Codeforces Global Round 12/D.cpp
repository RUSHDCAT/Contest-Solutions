
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t,n,a[N],f[N];
vector<int> v[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		set<int> s;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); s.insert(a[i]);
			v[i].clear(); f[i]=0;
		}
		for(int i=1;i<=n;i++){
			v[a[i]].push_back(i);
		} 


		int l=1,r=n;
		for(int i=1;i<=n;i++){
			if(v[i].size() != 1) {
				if(v[i].size()>0) f[n-i+1]=1;
				else for(int x=n-i;x>=1;x--) f[x]=0;
				break;
			}else{
				if(v[i][0]==l) {
					l++; f[n-i+1]=1;
				}else if(v[i][0]==r){
					--r; f[n-i+1]=1;
				}else{
					if(v[i].size()>0) f[n-i+1]=1;
					else for(int x=n-i;x>=1;x--) f[x]=0;
					break;					
				}
			}
		}
		if(s.size()==n) f[1]=1;
		for(int i=1;i<=n;i++)printf("%d", f[i]);
		printf("\n");
	}
}
