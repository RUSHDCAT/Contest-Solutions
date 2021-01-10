#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int n;
char s[N][9];

vector<int> g[N];

int f[N][1<<8];
int build(int l,int r,int mask) {
	bool win[10] = {0};
	for(int i=r;i>=l;i--) {
		for(auto j:g[i]){
			if(j>r) {
				int pos = j-(r+1);
				if((mask>>pos&1) == 0){
					win[i-l]=true; break;
				}
			}else{
				if(win[j-l]==0){
					win[i-l]=true; break;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<8;i++)if(win[i])ans|=1<<i;
	/*
	for(int i=0;i<2;i++){
		printf("%d", win[i]);
	}printf("\n");
	*/
	return ans;
}
int dfs(int i, int mask) {
	if(f[i][mask] != -1) return f[i][mask];
	f[i][mask] = 0;
	int r=i,l=max(i-7,1);
	//printf("# %d %d %d\n", l,r,mask);
	int mask_ = build(l,r,mask);
	if(i-8<=0)return f[i][mask] = mask_&1; 
	return f[i][mask] = dfs(i-8,mask_);
}


int build(int l,int r){
	bool win[10]={0};
	for(int i=r;i>=l;i--) {
		for(auto j:g[i]){
			if(j<=r) {
				if(win[j-l]==0){
					win[i-l]=true;  break;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<8;i++)if(win[i])ans|=1<<i;

	return ans;	
}

int brt(int l,int r){
	bool win[100]={0};
	for(int i=r;i>=l;i--) {
		for(auto j:g[i]){
			if(j<=r) {
				if(win[j-l]==0){
					win[i-l]=true; 
				}
			}
		}
	}	
	/*
	for(int i=1;i<=10;i++){
		printf("%d", win[i-1]);
	}printf("\n");
*/
	return win[0]==1?1:2;
}

int main() {
	memset(f,-1,sizeof(f));
	scanf("%d",&n); 
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=min(i+8,n);j++){
			int energy=0;
			for(int k=1;k<=8;k++)if(s[i][k]==s[j][k])energy++;
			if(energy>=j-i){
				g[i].push_back(j);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(i<=8) {
			int ans=build(1,i)&1;
			printf("%d", ans==0?2:1);
		}else{
			int mask=build(i-7,i);
			printf("%d",dfs(i-8,mask)==0?2:1);
		}
	}


}