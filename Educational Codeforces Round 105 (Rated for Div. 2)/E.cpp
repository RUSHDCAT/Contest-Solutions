#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, m;
map< pair<int,int>,int > mp;
set< pair<int,int> > done;

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char op[2]; scanf("%s",op);
		if(op[0]=='+'){
			int u,v,c; 
			scanf("%d%d%d",&u,&v,&c);
			mp[make_pair(u,v)]=c;
			if(mp[make_pair(u,v)] && mp[make_pair(v,u)]) done.insert(make_pair(u,v));
		}else
		if(op[0]=='-'){
			int u,v;
			scanf("%d%d",&u,&v);
			mp[make_pair(u,v)]=0;
		}else{
			int k;scanf("%d",&k);
		}

	}	
}