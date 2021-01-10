#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
char s[N], t[N];
LL x, y; 
int n,pre[N][2];

int bit[2][N];
void add(int id,int pos,int x) {
	while(pos<N){
		bit[id][pos] += x;
		pos += pos&(-pos);
	}
}
int query(int id,int pos){
	int ans=0;
	while(pos>0){
		ans+=bit[id][pos];
		pos-=pos&(-pos);
	}
	return ans;
}

LL cal1() {
	for(int i=1;i<=n;i++){
		t[i]=s[i];
		if(t[i]=='?') t[i]='1';
	}
	memset(bit,0,sizeof(bit));
	LL ans=0;
	for(int i=1;i<=n;i++){
		add(t[i]-'0',i,1);
		if(t[i]=='0'){
			ans += query(1,i) * y;
		}else{
			ans += query(0,i) * x;
		}
	}
	LL res=ans;

	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			ans -= (query(0,i-1) * x + ( query(0,n) - query(0,i)) * y );
			ans += (query(1,i-1) * y + ( query(1,n) - query(1,i)) * x );
			add(1,i,-1);
			add(0,i,+1);
		}
		res=min(res,ans);
	}
	return res;
}

LL cal2() {
	for(int i=1;i<=n;i++){
		t[i]=s[i];
		if(t[i]=='?') t[i]='0';
	}
	memset(bit,0,sizeof(bit));
	LL ans=0;
	for(int i=1;i<=n;i++){
		add(t[i]-'0',i,1);
		if(t[i]=='0'){
			ans += query(1,i) * y;
		}else{
			ans += query(0,i) * x;
		}
	}
	LL res=ans;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			ans -= (query(1,i-1) * y + ( query(1,n) - query(1,i)) * x );
			ans += (query(0,i-1) * x + ( query(0,n) - query(0,i)) * y );
			add(0,i,-1);
			add(1,i,+1);
		}
		res=min(res,ans);
	}
	return res;
}

int main() {
	scanf("%s", s+1);
	scanf("%lld%lld",&x,&y);
	n = strlen(s+1);
	for(int i=1;i<=n;i++){
		pre[i][0]=pre[i-1][0];
		pre[i][1]=pre[i-1][1];
		if(s[i]!='?')
			pre[i][s[i]-'0']++;
	}
	printf("%lld\n", min(cal1(),cal2()));
}

