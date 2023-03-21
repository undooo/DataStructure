#include<bits/stdc++.h>
using namespace std;
/*
观察这个数列：

1 3 0 2 -1 1 -2 …

这个数列中后一项总是比前一项增加2或者减少3，且每一项都为整数。

栋栋对这种数列很好奇，他想知道长度为 n 和为 s 而且后一项总是比前一项增加 a 或者减少 b 的整数数列可能有多少种呢？

输入格式
共一行，包含四个整数 n,s,a,b，含义如前面所述。

输出格式
共一行，包含一个整数，表示满足条件的方案数。

由于这个数很大，请输出方案数除以 100000007 的余数。

数据范围
1≤n≤1000,
−109≤s≤109,
1≤a,b≤106
输入样例：
4 10 2 3
输出样例：
2
样例解释
两个满足条件的数列分别是2 4 1 3和7 4 1 -2。
*/

/*
最终序列为
x + (x + d_1) + (x + d_1 + d_2) + ... + (x + d_1 + ... + d _n-1) = s
==>
nx + (n-1) * (d_1) + (n-2) * (d_2) + ... + (n - (n-1)) * (d_n-1) = s
==>
x = s - ((n-1) * (d_1) + (n-2) * (d_2) + ... + (n - (n-1)) * (d_n-1)) / n

因此，s和（...）模n同余，便可对应一个方案

状态表示：
dp[i][j] 表示取前i个数字，序列和模n的余数为j的方案数

状态计算：
分为以下两大种情况：1. +a  2. -b
1. +a情况
c + (n-i) * a 和  j 模n同余
c 与 j-(n-i)*a 模n同余
即
dp[i-1][(j-(n-i)*a)%n]

2.同理
dp[i-1][(j+(n-i)*b)%n]

*/
const int N=1010;
const int MOD = 100000007;
int dp[N][N];
int n,s,a,b;

int get_mod(int a, int b){
    return (a%b + b)% b;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d",&n,&s,&a,&b);
    dp[0][0] = 1;

    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++){
            dp[i][j] = (dp[i-1][get_mod(j-a*(n-i),n)] + dp[i-1][get_mod(j+b*(n-i),n)])%MOD;
        }
    printf("%d", dp[n-1][get_mod(s, n)]);
    return 0;
}
