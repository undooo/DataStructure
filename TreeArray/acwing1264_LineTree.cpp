#include<bits/stdc++.h>
using namespace std;


const int N=10010;

int w[N];
struct{
    int l,r;
    int sum;
}tr[4*N];


void pushUp(int x){
    tr[x].sum = tr[x<<1].sum + tr[x<<1|1].sum; 
}

void build(int x, int l, int r){
    if(l==r) tr[x] = {l,r,w[r]};
    else{
        tr[x]={l,r};

        int mid = l+r>>1;
        build(x<<1, l, mid);
        build(x<<1+1, mid+1, r);
        pushUp(x);
    }
}

int query(int x, int l, int r){
    if(l<=tr[x].l && r>= tr[x].r) return tr[x].sum;

    int mid = l+r>>1;
    int sum = 0;
    if(l<=mid)  sum+=query(x<<1, l, r);
    if(r>=mid+1)sum+=query(x<<1|1,l,r);
    return sum;
}

void modify(int u, int x, int v){
    if(tr[u].l == tr[u].r) tr[u].sum+=v;
    else{
        int mid = tr[u].l + tr[u].r >>1;
        if(x<=mid) modify(x<<1, x, v);
        else modify(x<<1|1, x, v);

        pushUp(u);
    }
}

int main(int argc, char const *argv[])
{
    int n,m;scanf("%d%d",&n,&m); 

    for(int i=1;i<=n;i++) scanf("%d",&w[i]);   
    build(1, 1, n);
    while(m--){
        int k, a, b;scanf("%d%d%d", &k, &a, &b);
        if(k==0) printf("%d\n", query(1, a, b));
        else modify(1, a, b);
    }
    return 0;
}
