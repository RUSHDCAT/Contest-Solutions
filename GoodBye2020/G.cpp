#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
const LL MOD = 1e9 + 7;

namespace kmp {
	char s[N],t[N]; int nex[N],flag[N];
	void build() {
	    nex[0]=nex[1]=0;
	    int j=0;
	    for(int i=1;s[i];i++) {
	        while(j>0 && s[i]!=s[j]) j=nex[j];
	        if(s[i]==s[j]) j++;
	        nex[i+1] = j;
	    }
	}
	int match(char * t) {
	    int ans=0;
	    int j=0; int len=strlen(s);
	    for(int i=0;t[i];i++){
	        while(j>0 && t[i]!=s[j]) j=nex[j];
	        if(t[i]==s[j]) j++;
	        if(j==len) {
	        	ans++;
	        }
	        if(t[i+1]=='\0') {
	        	int now=j;
	        	while(now) {
	        		//printf("now=%d\n", now);
	        		flag[now-1]=1; now=nex[now];
	        	}
	        }
	    }
	    return ans;
	}
	int solve_(char *ss, char* tt) {
		int n=strlen(ss); int m=strlen(tt);
		for(int i=0;i<n;i++) s[i]=ss[i]; s[n]='\0';
		for(int i=0;i<m;i++) t[i]=tt[i]; t[m]='\0';
		for(int i=0;i<=max(n,m);i++) nex[i]=flag[i]=0;
		build();
		return match(t);
	}
	int solve(char *ss, string tt) {
		int n=strlen(ss); int m=tt.length();
		for(int i=0;i<n;i++) s[i]=ss[i]; s[n]='\0';
		for(int i=0;i<m;i++) t[i]=tt[i]; t[m]='\0';
		for(int i=0;i<=max(n,m);i++) nex[i]=flag[i]=0;
		build();
		return match(t);
	}
}

int n, q, slen;
char s[N], t[N], str[N];



string pref[22];int prefLen[22],last;
void initstr() {
	int lim = 1000000;
	pref[0] = "";
	for(int i=0;s[i];i++) pref[0]+=s[i]; prefLen[0]=pref[0].length();
	for(int i=0;i<20 && i<n; i++) {
		prefLen[i+1] = prefLen[i] + 1 + prefLen[i];
		pref[i+1] = pref[i] + t[i] + pref[i];
		if (prefLen[i+1] > lim) {
			last = i+1; break;
		} 
	}
	//for(int i=0;i<5;i++) cout<<pref[i]<<endl;
}
LL sum[100000 + 10][27],pw[100000 + 10],ipw[N];
void initcnt() {
	pw[0]=1; 
	for(int i=1;i<=100000;i++) pw[i]=pw[i-1]*2%MOD;
	ipw[0]=1; ipw[1]=(MOD+1)/2;
	for(int i=2;i<=100000;i++) ipw[i]=ipw[i-1]*ipw[1]%MOD;

	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++) sum[i][j] = (i>=1?sum[i-1][j]:0);
		int ch=t[i]-'a';
		(sum[i][ch] += pw[n-i-1]) %= MOD;
	}
}
int query(int l,int r,int c) {
	LL cnt = sum[r][c] - (l>=1?sum[l-1][c]:0); cnt=(cnt%MOD+MOD)%MOD;
	return cnt * ipw[n-r-1] % MOD;

}

int cnt[30]={0};
void tag(char* s, string t) {
	//printf("tag %s ", s); cout<<t<<endl;
	memset(cnt,0,sizeof(cnt));
	int slen=strlen(s), tlen=t.length();
	vector<bool> f1(slen+1),f2(slen+1); // t 的后缀 match s 的前缀, s 的后缀匹配 t 的前缀
	kmp::solve(s,t);
	for(int i=0;i<slen;i++) f1[i]=kmp::flag[i];
	/*
	for(int i=0;i<slen;i++){
		printf("%d", f1[i]?1:0);
	}
	printf("\n");
	*/
	reverse(s,s+slen);
	reverse(t.begin(),t.end());
	kmp::solve(s,t);
	for(int i=0;i<slen;i++) f2[i]=kmp::flag[slen-1-i];
	/*
	for(int i=0;i<slen;i++){
		printf("%d", f2[i]?1:0);
	}
	printf("\n");
	*/
	reverse(s,s+slen);
	for(int i=0;i<slen;i++) 
		if((i==0||f1[i-1])&&(i==slen-1||f2[i+1])) {
			//printf("i=%d, c=%c\n", i,s[i]);
			cnt[s[i]-'a']++;
		}

}

void test() {
	scanf("%s%s",s,t);
	tag(s,t);
}

int main() {
	scanf("%d%d",&n,&q);
	scanf("%s%s",s,t); slen = strlen(s);
	initstr();
	initcnt();
	for(int i=1;i<=q;i++){
		int x; scanf("%d%s",&x,str);
		int len=strlen(str);
		LL ans = 0;
		
		int cur = 0;
		while(prefLen[cur] <= len) cur ++;
		//ans += kmp::solve(str, pref[x]); ans%=MOD;
		//printf("x=%d,cur=%d\n", x,cur);

		if (cur >= x) {
			ans = kmp::solve(str, pref[x]); ans %= MOD; 
			printf("%lld\n", ans);
		} else {
			ans = kmp::solve(str, pref[cur]) * pw[x - cur] % MOD; 
			
			tag(str, pref[cur]);
			for(int ch=0;ch<26;ch++){
				if(cnt[ch]) {
					//printf("ch = %c, cnt = %d, query = %d\n", ch+'a', cnt[ch], query(cur,x-1,ch));
					//printf("Q %d %d %d\n", cur,x-1,ch);
				}
				ans = ans + 1LL * cnt[ch] * query(cur, x-1, ch) % MOD;
				ans = ans % MOD;
			}
			printf("%lld\n", ans);
		}
	}	
}





