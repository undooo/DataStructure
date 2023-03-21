#include<bits/stdc++.h>
using namespace std;

/*
机器人正在玩一个古老的基于 DOS 的游戏。

游戏中有 N+1 座建筑——从 0 到 N 编号，从左到右排列。

编号为 0 的建筑高度为 0 个单位，编号为 i 的建筑高度为 H(i) 个单位。

起初，机器人在编号为 0 的建筑处。

每一步，它跳到下一个（右边）建筑。

假设机器人在第 k 个建筑，且它现在的能量值是 E，下一步它将跳到第 k+1 个建筑。

如果 H(k+1)>E，那么机器人就失去 H(k+1)−E 的能量值，否则它将得到 E−H(k+1) 的能量值。

游戏目标是到达第 N 个建筑，在这个过程中能量值不能为负数个单位。

现在的问题是机器人至少以多少能量值开始游戏，才可以保证成功完成游戏？

输入格式
第一行输入整数 N。

第二行是 N 个空格分隔的整数，H(1),H(2),…,H(N) 代表建筑物的高度。

输出格式
输出一个整数，表示所需的最少单位的初始能量值上取整后的结果。

数据范围
1≤N,H(i)≤105,

输入样例1：
5
3 4 3 2 4
输出样例1：
4
输入样例2：
3
4 4 4
输出样例2：
4
输入样例3：
3
1 6 4
输出样例3：
3
*/


const int N=100010;
int maxI;
int n;
int a[N];

bool check(int x){
    for(int i=1;i<=n;i++){
        x = x*2-a[i];
        if(x>=maxI) return true;
        if(x<0) return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        maxI = max(a[i], maxI);
    }
    int l=0, r=maxI;
    while(l<r){
        int mid = l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d", r);


    return 0;
}
