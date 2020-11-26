#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int f[20];

int main() {
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if((i&j)==0) {
				printf("1");
			}else{
				printf("0");
			}
		}
		printf("\n");
	}
}