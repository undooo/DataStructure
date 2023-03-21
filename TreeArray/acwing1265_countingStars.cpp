#include<bits/stdc++.h>
using namespace std;
/*
天空中有一些星星，这些星星都在不同的位置，每个星星有个坐标。

如果一个星星的左下方（包含正左和正下）有 k颗星星，就说这颗星星是 k级的。


给定星星的位置，输出各级星星的数目。

换句话说，给定 N个点，定义每个点的等级是在该点左下方（含正左、正下）的点的数目，试统计每个等级有多少个点。

输入格式
第一行一个整数 N，表示星星的数目；接下来 N行给出每颗星星的坐标，坐标用两个整数 x,y表示；

不会有星星重叠。星星按 y坐标增序给出，y坐标相同的按 x坐标增序给出。

输出格式
N行，每行一个整数，分别是 0级，1级，2级，……，N−1级的星星的数目。

数据范围
1≤N≤15000,
0≤x,y≤32000
输入样例：
5
1 1
5 1
7 1
3 3
5 5
输出样例：
1
2
1
1
0
*/
const int N=32010;
int n;
int tr[N], level[N];


int lowbit(int x){return x&-x;}

void add(int x){
    for(int i=x;i<=N;i+=lowbit(i)) tr[i]+=1;
}

int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x++;
        level[query(x)]++;
        add(x);
    }

    for(int i=0;i<n;i++){
        printf("%d\n", level[i]);
    }

    return 0;
}
