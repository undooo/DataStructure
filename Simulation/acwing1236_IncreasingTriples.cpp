#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
int a[N],b[N],c[N];
int n;
int cnt[N], sumA[N],sumC[N];
ll res;

/*
给定三个整数数组

A=[A1,A2,…AN]
,
B=[B1,B2,…BN]
,
C=[C1,C2,…CN]
,

请你统计有多少个三元组 (i,j,k)
 满足：

1≤i,j,k≤N
Ai<Bj<Ck
输入格式
第一行包含一个整数 N
。

第二行包含 N
 个整数 A1,A2,…AN
。

第三行包含 N
 个整数 B1,B2,…BN
。

第四行包含 N
 个整数 C1,C2,…CN
。

输出格式
一个整数表示答案。

数据范围
1≤N≤105
,
0≤Ai,Bi,Ci≤105
输入样例：
3
1 1 1
2 2 2
3 3 3
输出样例：
27
*/

void setVar(){
    scanf("%d", &n);

    for(int i=1;i<=n;i++) scanf("%d", &a[i]),a[i]++,cnt[a[i]]++;
    for(int i=1;i<=N;i++) cnt[i]+=cnt[i-1];
    memcpy(sumA, cnt, sizeof sumA);
    
    for(int i=1;i<=n;i++) scanf("%d", &b[i]), b[i]++;

    memset(cnt, 0, sizeof cnt);
    for(int i=1;i<=n;i++) scanf("%d", &c[i]),c[i]++,cnt[c[i]]++;
    for(int i=1;i<=N;i++) cnt[i]+=cnt[i-1];

    memcpy(sumC, cnt, sizeof sumC);
    return;
}

int main(int argc, char const *argv[])
{
    setVar();

    for(int i=1;i<=n;i++){
        res+=((ll)sumA[b[i]-1] * (n-sumC[b[i]]));
    }
    printf("%lld", res);
    
    return 0;
}
