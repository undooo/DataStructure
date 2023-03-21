#include<bits/stdc++.h>
using namespace std;

/*
从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。

输入格式
输入一个整数 n。

输出格式
每行输出一种方案。

同一行内的数必须升序排列，相邻两个数用恰好 1 个空格隔开。

对于没有选任何数的方案，输出空行。

本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。

数据范围
1≤n≤15
输入样例：
3
输出样例：

3
2
2 3
1
1 3
1 2
1 2 3

*/
const int N=16;
int flag[N];
int n;

void dfs(int u){
    if(u > n){
        for(int i=1;i<=n;i++){
            if(flag[i]==1) printf("%d ",i);
        }
        printf("\n");
        return;
    }

    flag[u]=2;
    dfs(u+1);
    flag[u]=0;

    flag[u]=1;
    dfs(u+1);
    flag[u]=0;
    return;
}


int main(int argc, char const *argv[])
{
    cin>>n;
    dfs(1);
    return 0;
}
