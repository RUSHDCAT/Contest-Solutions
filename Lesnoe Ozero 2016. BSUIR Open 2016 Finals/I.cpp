#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, t;
int main() {
	scanf("%d%d",&t,&n);
	if(t==1){
		printf("5\n"); fflush(stdout);
		int r, c;  scanf("%d%d",&r,&c);
		//assert(r==2 && c==1);
		for(int i=2;i<=2*n;i++) {
			printf("9\n"); fflush(stdout);
			scanf("%d%d",&r,&c);
		}	
	} else {
		int x; scanf("%d",&x);
 		vector< pair<int,int> > st;
 		for(int i=2;i<=n;i++) {
 			st.push_back(make_pair(1,i)); st.push_back(make_pair(2,i));
 		}
		if(x==4) {
			printf("%d %d\n", 1,1);  fflush(stdout); st.push_back(make_pair(2,1));
 		} else {
 			printf("%d %d\n", 2,1);  fflush(stdout); st.push_back(make_pair(1,1));
 		}

 		for(auto p: st) {
 			int x; scanf("%d",&x);
 			printf("%d %d\n", p.first, p.second); fflush(stdout);
 		}

	}
}