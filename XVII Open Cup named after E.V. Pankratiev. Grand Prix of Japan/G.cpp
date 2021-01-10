#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 150 + 10;
int a[14][14];
char s[150 + 2][150 + 2];

int main() {
	for(int i=1;i<=11;i++){
		for(int j=1;j<=13;j++){
			a[i][j] = (i-1)*13 + j;
		}
	}
	
	for(int i=1;i<=150;i++){
		for(int j=1;j<=150;j++) s[i][j] = '.';
	}
	
	int ans = 0;
	int curx = 0;
	for(int bias=0;bias<13;bias++) {
		for(int beg=0;beg<13;beg++){
			++curx;
			for(int i=0;i<12;i++) {
				int cury = (beg + bias * i) % 13 + 13 * i + 1;
				if(curx <= 150 && cury <= 150) {
					// printf("# %d %d\n", curx, cury);
					//assert(s[curx][curx] != 'O');
					s[curx][cury] = 'O'; ans++;
				}
			}
		}
	}

	int cnt=0;
	for(int i=1;i<=150;i++)for(int j=1;j<=150;j++)if(s[i][j]=='O')cnt++;
	//printf("%d\n", cnt);
	// printf("%d\n", ans);
	printf("150\n");
	for(int i=1;i<=150;i++){
		printf("%s\n", s[i]+1);
	}
	
	for (int i = 1; i <= 150; i++){
			for (int j = i + 1; j <= 150; j++){
				for (int k = 1; k <= 150; k++){
					for (int l = k + 1; l <= 150; l++){
						if (s[i][k] == 'O' && s[i][l] == 'O' && s[j][k] == 'O' && s[j][l] == 'O'){
							while(1) printf("huo yu shi sha bi !");
						}
					}
				}
			}
		}
		
}