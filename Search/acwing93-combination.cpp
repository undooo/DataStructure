#include<bits/stdc++.h>
using namespace std;

/*
从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。

输入格式
两个整数 n,m ,在同一行用空格隔开。

输出格式
按照从小到大的顺序输出所有方案，每行 1 个。

首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。

数据范围
n>0 ,
0≤m≤n ,
n+(n−m)≤25
输入样例：
5 3
输出样例：
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 

*/
const int N = 13;
int n,m;
int state[N];

void dfs(int start, int level){

    if(level-1 + n-start +1 < m) return; //剪枝
    if(level>m){
        for(int i=1;i<=m;i++){
            printf("%d ",state[i]);
        }
        puts("");
        return;
    }

    for(int i=start;i<=n;i++){
        state[level] = i;
        dfs(i+1,level+1);
    }
}


int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);

    dfs(1,1);
    return 0;
}
