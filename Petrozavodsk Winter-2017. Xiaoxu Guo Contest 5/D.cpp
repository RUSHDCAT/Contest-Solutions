#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, a[N];

typedef bitset<200002> B;

B S;
void add(LL x) {
	if (x > 200002) return;
	// printf("add %lld\n", x);
	S |= (S<<x);
}

char s[N]; int nex[N];
void build() {
    nex[0]=nex[1]=0;
    int j=0;
    for(int i=1;s[i];i++) {
        while(j>0 && s[i]!=s[j]) j=nex[j];
        if(s[i]==s[j]) j++;
        nex[i+1] = j;
    }
}

bitset<10000000> SS;
void add2(LL x) {
	if (x >= 10000000) return;
	// printf("add %lld\n", x);
	SS |= (SS<<x);
}
LL brt() {
	SS.reset(); SS[0]=1;
	for(int i=1;i<=n;i++){
		LL cur = a[i], del = 1;
		while (cur >= del) {
			add2(del * i); cur -= del; del *= 2;
		}
		if(cur>0) add2(cur * i);
	}

	int s1=0,s2=0,s3=0;
	for(int i=0;i<=99999;i++)if(SS[i])s1++;
	for(int i=550011;i<=650010;i++)if(SS[i])s3++;
	for(int i=100000;i<=550010;i++)if(SS[i])s2++;
	printf("## %d %d %d\n", s1,s2,s3);

	return SS.count();
}

int main() {
	while(~scanf("%d",&n)) {
		S.reset(); S[0] = 1;
		LL tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); tot+=1LL*i*a[i];
			LL cur = a[i], del = 1;
			while (cur >= del) {
				add(del * i); cur -= del; del *= 2;
			}
			if(cur>0) add(cur * i);
		}



		LL ans = 0;
		for(int i=0;i<=200000;i++)if(S[i])ans++;
		if(tot <= 200000) {
			printf("%lld\n", ans); 
			//assert(brt() == ans);
			continue;
		}

		int pos = 99999; // [0,pos] [pos+1,tot-pos-1]  [tot-pos,tot]

		//printf("[%d,%d][%d,%d][%d,%d]\n", 0,pos,pos+1,tot-pos-1,tot-pos,tot);
		ans=0;
		for(int i=0;i<=pos;i++) if(S[i]) ans++; 

		//printf("!! %lld\n", ans);

		ans *= 2;
		for(int i=100000;i<150000;i++)s[i-100000]=S[i]?'1':'0';
		/*
		for(int i=pos+1;i<=pos+100;i++){
			printf("%d", S[i]?1:0);
		}
		printf("\n");
		*/
		build();
		int rig = 49999;
		int len = rig - nex[rig];
		
		//printf("rig=%d,nex=%d\n", rig,nex[rig]);
		//printf("len = %d\n", len);
		for(int i=pos+1;i<=pos+len;i++) {
			if(i<=tot-pos-1) {
				LL cnt = (tot-pos-1 - i) / len + 1;
				if(S[i]==1) ans += cnt;
			}
		}
		//printf("# %lld %lld\n", brt(), ans);
		//assert(brt() == ans);
		printf("%lld\n", ans);
	}	
}

