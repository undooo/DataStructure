#include <bits/stdc++.h>
using namespace std;

/*
X星球居民小区的楼房全是一样的，并且按矩阵样式排列。

其楼房的编号为 1,2,3…
当排满一行时，从下一行相邻的楼往反方向排号。

比如：当小区排号宽度为 6
 时，开始情形如下：

1  2  3  4  5  6
12 11 10 9  8  7
13 14 15 .....
我们的问题是：已知了两个楼号 m
 和 n
，需要求出它们之间的最短移动距离（不能斜线方向移动）。

输入格式
输入共一行，包含三个整数 w,m,n
，w
 为排号宽度，m,n
 为待计算的楼号。

输出格式
输出一个整数，表示 m,n
 两楼间最短移动距离。

数据范围
1≤w,m,n≤10000
,

输入样例：
6 8 2
输出样例：
4
*/
int w,m,n;


int main(int argc, char const *argv[])
{

    scanf("%d%d%d",&w, &m, &n);

    int x1=(m-1)/w+1;
    int y1 =x1%2==1? m-(x1-1)*w: w-(m-(x1-1)*w)+1;
    int x2=(n-1)/w+1;
    int y2 =x2%2==1? n-(x2-1)*w: w-(n-(x2-1)*w)+1;  
    printf("x1:%d y1:%d x2:%d y2:%d\n",x1, y1, x2, y2);

    int res = abs(x2-x1) + abs(y2-y1); 
    printf("%d", res);
    return 0;
}
