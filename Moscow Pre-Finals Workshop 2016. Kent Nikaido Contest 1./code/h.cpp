#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


const int N = 100000;
int L,n;
int a[N],b[N];
int c(int x, int y){
    LL A=y,B=x-y;
    for(int i=0;i<32;i++){
        if((A>>i&1) && (B>>i&1)) return 2;
    }
    return 1;
} 

int main() {
    scanf("%d%d",&L,&n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        ans += c(L-1, a[i]-1) * c(a[i]-1, b[i]-1);
        ans %= 2;
    }
    if(L%2==0) ans ^= 1;
    printf("%s\n", ans==1?"Iori":"Yayoi");
}