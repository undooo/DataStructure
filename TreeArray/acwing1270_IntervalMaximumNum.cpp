#include<bits/stdc++.h>
using namespace std;


const int N=100010;
int w[N];

struct{
    int l,r;
    int max;
}tr[4*N];

void pushUp(int u){
    tr[u].max = max(tr[u<<1].max, tr[u<<1|1].max);
}


void build(int u, int l, int r){
    if(l==r) tr[u] = {l, r, w[l]};
    else{
        tr[u] = {l, r};
        int mid = l+r>>1;
        build(u<<1, l, mid);
        build(u<<1|1, mid+1, r);

        pushUp(u);
    }
}

int query(int u, int l, int r){
    if(l<=tr[u].l && r>=tr[u].r) return tr[u].max;
    int mid = tr[u].l + tr[u].r >>1;
    int maxV=INT_MIN;
    if(l<=mid) maxV = query(u<<1, l, r);
    if(r>=mid+1) maxV = max(maxV,query(u<<1|1, l, r));
    return maxV;
}
int main(int argc, char const *argv[])
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d", &w[i]);
    build(1,1,n);
    while(m--){
        int l,r;scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }
    return 0;
}
