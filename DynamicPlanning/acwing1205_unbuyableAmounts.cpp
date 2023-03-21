#include<bits/stdc++.h>
using namespace std;

/*

小明开了一家糖果店。

他别出心裁：把水果糖包成4颗一包和7颗一包的两种。

糖果不能拆包卖。

小朋友来买糖的时候，他就用这两种包装来组合。

当然有些糖果数目是无法组合出来的，比如要买 10 颗糖。

你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。

大于17的任何数字都可以用4和7组合出来。

本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。

输入格式
两个正整数 n,m，表示每种包装中糖的颗数。

输出格式
一个正整数，表示最大不能买到的糖数。

数据范围
2≤n,m≤1000，
保证数据一定有解。

输入样例：
4 7
输出样例：
17
*/


//DP解法
//只需看上一步可不可以到达即可
const int N=1000010;
bool a[N];
int n,m;
void dp(){
    scanf("%d%d",&n,&m);
    int minx=min(n,m);
    int maxx=max(n,m);
    a[0]=true;
    int res=0;
    for(int i=minx;i<=n*m;i++){
        if(a[i-minx]==true){
            a[i]=true;
        }else if(i>=maxx && a[i-maxx]==true){
            a[i]=true;
        }else{
            res=i;
        }
    }
    printf("%d",res);
}

//数学方法
//互质的两个正整数n,m, a*n+b*m凑不成的最大整数为 (n-1)*(m-1)-1
void math(){
    scanf("%d%d",&n,&m);
    printf("%d",(n-1)*(m-1)-1);
}
int main(int argc, char const *argv[])
{
    dp();
    return 0;
}
