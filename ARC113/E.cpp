#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T;
char s[N]; int n;

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%s", s + 1); n = strlen(s + 1);

		int cnt_a = 0, cnt_b;
		for (int i = 1; i <= n; i ++) if (s[i] == 'a') cnt_a ++;
		cnt_b = n - cnt_a;

		if (cnt_b == 0) {
			for (int i = 1; i <= cnt_a; i ++) printf("a"); 
			printf("\n"); continue;
		}

		if (s[n] == 'b') {
			if (cnt_a % 2 == 0) {
				for (int i = 1; i <= cnt_b; i ++) printf("b"); 
				printf("\n"); continue;
			} else {
				int las = -1, pre = 0, suf = 0;
				for (int i = 1; i <= n; i ++) if (s[i] == 'a') las = i;
				for (int i = 1; i <= n; i ++) if (s[i] == 'b' && i < las) pre ++;
				for (int i = 1; i <= n; i ++) if (s[i] == 'b' && i > las) suf ++;

				int seg = 0, cnt_1 = 0;
				for (int i = 1, j = 1; i <= n; i = j) {
					if (s[i] == 'b') {
						j ++; continue;
					} else {
						while (j <= n && s[i] == s[j]) ++j;
						if (j - i == 1) cnt_1 ++; else seg ++;
					}
				}

				if (cnt_1 % 2) {
					cnt_1 --; seg ++;
				} 
				if (s[1] == 'a') {
					int pos = 1; while(pos<=n && s[pos]=='a') pos++;
					pos --;
					if (pos >= 2 && seg == 1 && cnt_1 >= 1) cnt_1 --, seg ++;
				}
				if (cnt_1 % 2) {
					cnt_1 --; seg ++;
				} 
				cnt_a -= (cnt_1 + 2 * max(seg - 1, 0));

				if (pre >= 1 && suf >= 3) {
					pre = pre + suf - 2;
					suf = 0;
				}
				if (pre == 0) cnt_a = 1;
				for (int i = 1; i <= pre; i ++) printf("b");
				if (suf == 0)
					for (int i = 1; i <= cnt_a; i ++) printf("a");
				else 
					printf("a");
				for (int i = 1; i <= suf; i ++) printf("b");
				printf("\n"); continue;
			}
		} else {
			int seg = 0, cnt_1 = 0;
			for (int i = 1, j = 1; i <= n; i = j) {
				if (s[i] == 'b') {
					j ++; continue;
				} else {
					while (j <= n && s[i] == s[j]) ++j;
					if (j - i == 1) cnt_1 ++; else seg ++;
				}
			}

			bool fg = false;
			if (cnt_1 % 2) {
				cnt_1 --; seg ++; fg = true;
			} 
			if (s[1] == 'a') {
				int pos = n; while(pos>=1 && s[pos]=='a') pos--;
				
				if (pos == n-1 && (!fg) && seg == 1) cnt_1 --, seg ++;
			}			
			if (cnt_1 % 2) {
				cnt_1 --; seg ++;
			} 
			cnt_a -= (cnt_1 + 2 * max(seg - 1, 0));
	
			for (int i = 1; i <= cnt_b; i ++) printf("b");
			for (int i = 1; i <= cnt_a; i ++) printf("a");
			printf("\n"); continue;
		}
	}	
}