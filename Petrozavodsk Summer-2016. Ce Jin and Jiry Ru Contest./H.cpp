#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int N = 3e5 + 1;
#define re register
inline int  read()
{
    re int x=0,f=1;
    re char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}

long long f[N<<2], g[N<<2], mn[N<<2], mx[N<<2];
int a[N];

void push_up(int x){
	f[x] = f[x<<1] + f[x<<1|1];
	mn[x] = min(mn[x<<1], mn[x<<1|1]);
	mx[x] = max(mx[x<<1], mx[x<<1|1]);
}
void build(int x, int l, int r){
	if (l == r){
		f[x] = a[l]; mn[x] = a[l]; mx[x] = a[l];
		g[x] = 0; 
		return ;
	}
	int mid = (l + r) / 2;
	build(x<<1, l, mid);
	build(x<<1|1, mid + 1, r);
	push_up(x);
}
void push_down(int x, int l, int r){
	int mid = (l + r) / 2;
	if (mn[x] == mx[x]){
		f[x<<1] = mx[x] * (mid - l + 1); mn[x<<1] = mx[x<<1] = mx[x];
		f[x<<1|1] = mx[x] * (r - mid); mn[x<<1|1] = mx[x<<1|1] = mx[x];
		g[x] = g[x<<1] = g[x<<1|1] = 0;
		return ;
	}
	if(g[x]) {
		f[x<<1] += g[x] * (mid - l + 1); mn[x<<1] += g[x]; mx[x<<1] += g[x]; g[x<<1] += g[x];
		f[x<<1|1] += g[x] * (r - mid); mn[x<<1|1] += g[x]; mx[x<<1|1] += g[x]; g[x<<1|1] += g[x];
		g[x] = 0;
	}
}
void update(int x, int l, int r, int left, int right, long long y){
	if (left > r || right < l) return;
	if (left <= l && right >= r){
		f[x] += y * (r - l + 1); 
		mn[x] += y;
		mx[x] += y;
		g[x] += y;
		return;
	}
	push_down(x, l, r);
	int mid = (l + r) / 2;
	update(x<<1, l, mid, left, right, y);
	update(x<<1|1, mid + 1, r, left, right, y);
	push_up(x);
}
int sq[100000 + 10];
void update(int x, int l, int r, int left, int right){
	if (left > r || right < l) return;
	if (left <= l && right >= r){
		if (mx[x] == 1) return;
		if (mn[x] == mx[x]){
			mn[x] = mx[x] = mx[x]<=100000?sq[mx[x]]:sqrt(mx[x]);
			f[x] = mn[x] * (r - l + 1); g[x] = 0;
			return ;
		}
	}
	push_down(x, l, r);
	int mid = (l + r) / 2;
	update(x<<1, l, mid, left, right);
	update(x<<1|1, mid + 1, r, left, right);
	push_up(x);
}
long long query(int x, int l, int r, int left, int right){
	if (left > r || right < l) return 0;
	if (left <= l && right >= r) return f[x];
	push_down(x, l, r);
	int mid = (l + r) / 2;
	return query(x<<1, l, mid, left, right) + query(x<<1|1, mid + 1, r, left, right);
}

int main(){
	for(int i=1;i<=100000;i++) sq[i] = sqrt(i);
	int n, m;
	//scanf("%d%d", &n, &m);
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
		//scanf("%d", &a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++){
		int op, l, r, x; //scanf("%d", &op);
		op = read();
		if (op == 1){
			//scanf("%d%d%d", &l, &r, &x);
			l = read(); r = read(); x = read();
			update(1, 1, n, l, r, x);
		} else if (op == 2){
			//scanf("%d%d", &l, &r);
			l = read(); r = read();
			update(1, 1, n, l, r);
		} else {
			//scanf("%d%d", &l, &r);
			l = read(); r = read();
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}