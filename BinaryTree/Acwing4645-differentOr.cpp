#include<bits/stdc++.h>
using namespace std;
/*
给定一个长度为 n 的数列 A1,A2,⋅⋅⋅,An 和一个非负整数 x，给定 m 次查询，每次询问能否从某个区间 [l,r] 中选择两个数使得他们的异或等于 x。

输入格式
输入的第一行包含三个整数 n,m,x。

第二行包含 n 个整数 A1,A2,⋅⋅⋅,An。

接下来 m 行，每行包含两个整数 li,ri 表示询问区间 [li,ri]。

输出格式
对于每个询问，如果该区间内存在两个数的异或为 x 则输出 yes，否则输出 no。

数据范围
对于 20% 的评测用例，1≤n,m≤100；
对于 40% 的评测用例，1≤n,m≤1000；
对于所有评测用例，1≤n,m≤100000，0≤x<2^20，1≤li≤ri≤n，0≤Ai<2^20。

输入样例：
4 4 1
1 2 3 4
1 4
1 2
2 3
3 3
输出样例：
yes
no
yes
no

*/

const int N=100010, M=(1<<20)+10;

int last[M], g[N];

int main(int argc, char const *argv[])
{
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++){
        int a;scanf("%d",&a);
        g[i] = max(g[i-1], last[a^x]);
        last[a] = i;
    }

    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        if(g[r]>=l) puts("yes");
        else puts("no");
    }
    return 0;
}
