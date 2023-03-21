#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
typedef long long int LL;
//有一排孩子，要把他们冒泡排序，对于每一个孩子，第n次调换会使得耐心度加n，求最小耐心度和


int tr[N], h[N], sum[N];
int n;

int lowBit(int x){return x&-x;}

void add(int x, int v){
    for(int i=x;i<N;i+=lowBit(i)){
        tr[i]+=v;
    }
}

int query(int x){
    int res=0;
    for(int i=x;i;i-=lowBit(i)){
        res+=tr[i];
    }
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &h[i]);
    }

    //计算位置i的孩子前，有几个人比他大
    for(int i=0;i<n;i++){
        sum[i] += query(N-1) - query(h[i]);
        add(h[i], 1);
    }

    //计算后面有几个比他小
    memset(tr, 0, sizeof tr);
    for(int i=n-1;i>=0;i--){
        sum[i] += query(h[i]-1);
        add(h[i], 1);
    }

    LL ans=0;
    for(int i=0;i<n;i++) ans+= (LL)sum[i] * (sum[i]+1) / 2;
    printf("%d", ans);
    return 0;
}
