#include<bits/stdc++.h>
using namespace std;

/*
给定一个长度为 N 的数列，A1,A2,…AN，如果其中一段连续的子序列 Ai,Ai+1,…Aj 之和是 K 的倍数，我们就称这个区间 [i,j] 是 K 倍区间。

你能求出数列中总共有多少个 K 倍区间吗？

输入格式
第一行包含两个整数 N 和 K。

以下 N 行每行包含一个整数 Ai。

输出格式
输出一个整数，代表 K 倍区间的数目。

数据范围
1≤N,K≤100000,
1≤Ai≤100000
输入样例：
5 2
1
2
3
4
5
输出样例：
6
*/
const int N=100010;
typedef long long LL;
int n,k;
LL a[N];
LL cnt[N];

int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i] += a[i-1];
    }    
    LL res=0;
    //设0为1的原因：例如当某个数字本身便是k的倍数时，即余数为0，也成立，提前设为1可避免特判
    cnt[0]=1;
    for(int i=1;i<=n;i++){
        res+=cnt[a[i]%k];
        cnt[a[i]%k]++;

    }
    printf("%lld", res);

    return 0;
}
