#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;


int tot = 0;
int main() {
	printf("19999 100000");
	for (int i = 1; i <= 9999; i++){
		if (i == 1){
			for (int j = 1; j <= 3; j++) {
				//printf("1 1\n"); 
				++ tot;
			}
		} else if (i % 2){
			for (int j = 1; j <= 2; j++) {
				//printf("1 %d\n", i); 
				++ tot;
			}
		} else {
			//printf("2 %d %d\n", i, i - 1);
			//printf("2 %d %d\n", i, i + 1);
			tot += 2;
		}
	}
	printf("%d\n", tot);
}