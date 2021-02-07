#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;

char s[N],t[N];int n,q;
int height[N],rk[N],sa[N],cc[N],t1[N],t2[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k>=n?-1:y[a+k];
    int b1=y[b],b2=b+k>=n?-1:y[b+k];
    return a1==b1&&a2==b2;
}
void buildSA(int m) {
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++) cc[i]=0;
    for(int i=0;i<n;i++) cc[x[i]=s[i]]++;
    for(int i=1;i<m;i++) cc[i]+=cc[i-1];
    for(int i=n-1;i>=0;i--) sa[--cc[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++)
            if(sa[i]>=k) y[p++]=sa[i]-k;

        for(int i=0;i<m;i++) cc[i]=0;
        for(int i=0;i<n;i++) cc[x[y[i]]] ++;
        for(int i=1;i<m;i++) cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--) sa[--cc[x[y[i]]]]=y[i];
        swap(x,y);
        m=1,x[sa[0]]=0;
        for(int i=1;i<n;i++) {
            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?m-1:m++;
        }
        if(m>=n) break;
    }
}
void buildH(){
    for(int i=0;i<n;i++)
        rk[sa[i]]=i;
    int k=0; height[0]=0;
    for(int i=0;i<n;i++) {
        if(!rk[i]) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}
int LG[N],st[N][20];
void RmqInit() {
    for(int i=0;i<n;i++)
        st[i][0]=height[i];

    for(int i=1;i<20;i++)
    for(int j=0;j<n;j++)
        if(j+(1<<i)<=n)
            st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
}
int LCP(int x, int y) { // suffix(x) & suffix(y)
    if (x==y) return n-x;
    int l = min(rk[x], rk[y]) + 1;
    int r = max(rk[x], rk[y]); 
    int k = LG[r-l+1];
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

pair<int,int> getInterval(int l,int r){
    // suffix whose prefix include [l,r];
    if (l > r) return make_pair(0, n - 1);
    pair<int, int> ans;

    {
        int rig = rk[l], lef = -1;
        while (rig - lef > 1) {
            int mid = (lef + rig) >> 1;
            if (LCP(l, sa[mid]) >= r - l + 1) rig = mid; else lef = mid;
        }
        ans.first = rig;
    }

    {
        int lef = rk[l], rig = n;
        while (rig - lef > 1) {
            int mid = (lef + rig) >> 1;
            if (LCP(l, sa[mid]) >= r - l + 1) lef = mid; else rig = mid;
        }
        ans.second = lef;
    }
    return ans;
}

int cnt_points = 0;
int cnt_intervals = 0;
pair<int,int> points[N]; 
pair<int,int> X[N]; 
pair<int,int> Y[N];
int from[N];

int bit[N];
void add(int pos) {
    pos += 2;
    // printf("add %d\n", pos);
    while(pos < N) {
        bit[pos] ++; pos += pos & (-pos);
    }
}
void clear(int pos) {
    pos += 2;
    while(pos < N) {
        bit[pos] = 0; pos += pos & (-pos);
    }
}
int query(int pos) {
    pos += 2;
    int ans = 0;
    while (pos > 0) {
        ans += bit[pos]; pos -= pos & (-pos);
    }
    return ans;
}
struct Nod {
    int x, y, tp;
    bool operator<(const Nod&o)const{
        if(x==o.x){
            if(y==o.y) return abs(tp)<abs(o.tp);
            return y<o.y;
        }
        return x<o.x;
    }
} nod[N]; int tot = 0;
void count() {
    tot = 0;
    for (int i = 1; i <= cnt_intervals; i ++) {
        nod[++tot] = (Nod){X[i].second, Y[i].second, +from[i]};
        nod[++tot] = (Nod){X[i].first-1, Y[i].first-1, +from[i]};
        nod[++tot] = (Nod){X[i].second, Y[i].first-1, -from[i]};
        nod[++tot] = (Nod){X[i].first-1, Y[i].second, -from[i]};
    }
    for (int i = 1; i <= cnt_points; i ++) {
        nod[++tot] = (Nod){points[i].first, points[i].second, 0};
    }

    sort(nod+1,nod+1+tot);
    vector<int> ans(q+1,0);
    for(int i=1;i<=tot;i++){
        if(nod[i].tp==0) {
            add(nod[i].y);
        }else{
            int sgn = nod[i].tp > 0 ? 1 : -1;
            int id =  abs(nod[i].tp);
            ans[id] += sgn * query(nod[i].y);
        }
    }
    for(int i=1;i<=tot;i++){
        if(nod[i].tp==0) {
            clear(nod[i].y);
        }
    }    

    for(int i=1;i<=q;i++)
        printf("%d\n", ans[i]);
}

int beg[N],len[N];
void gen(char s[],int lim) {
    int len=rand()%lim+1;
    for(int i=0;i<len;i++) s[i]=rand()%26+'a';
    s[len]='\0';
}
void init() {
    //scanf("%s", s); 
    gen(s,100);
    //printf("%s\n", s);
    len[0]=n=strlen(s); 
    //scanf("%d",&q);
    q=rand()%100+1;
    for(int i=1;i<=q;i++){
        //scanf("%s",t);
        gen(t,100);
        s[n++]='#';
        beg[i]=n; len[i]=strlen(t);
        for(int i=0;t[i];i++)
            s[n++]=t[i];
    }   
    //printf("# %d\n", n);

    buildSA(1000); buildH(); RmqInit();
    cnt_points = len[0], cnt_intervals = 0;
    for(int i=0;i<len[0];i++){
        points[i+1].first = rk[i];
    }
    for(int i=1;i<=q;i++){
        for(int j=beg[i];j<beg[i]+len[i];j++){
            int lef = j + 1;
            int rig = beg[i] + len[i] - 1;
            ++cnt_intervals;
            X[cnt_intervals] = getInterval(lef, rig);
            from[cnt_intervals] = i;
        }
    }

    for(int i=0;i<=q;i++) {
        reverse(s+i, s+i+len[i]);
    }
    buildSA(1000); buildH(); RmqInit();
    cnt_points = len[0], cnt_intervals = 0;
    for(int i=0;i<len[0];i++){
        points[len[0]-i].second = rk[i];
    }
    for(int i=1;i<=q;i++){
        for(int j=beg[i]+len[i]-1;j>=beg[i];j--){
            int lef = j + 1;
            int rig = beg[i] + len[i] - 1;
            ++cnt_intervals;
            Y[cnt_intervals] = getInterval(lef, rig);
            from[cnt_intervals] = i;
        }
    }    
    count();
}

int main() {
    for(int i=1;i<N;i++) {
        int t = i, c = 0;
        while(t>1) { t/=2; c ++; }
        LG[i] = c;
    }
	int t; scanf("%d",&t);
    while(t--){
        init();
    }
}

