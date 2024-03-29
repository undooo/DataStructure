#include<bits/stdc++.h>
using namespace std;
/*
问题描述
评估一个长期项目的投资收益，资金的时间价值是一个必须要考虑到的因素。简单来说，假设银行的年利率为 
，那么当前的 
 元一年后就会变成 
 元，两年后变成 
 元。因此，现在收到 
 元比两年后收到 
 元收益更多，两年后再支出 
 元会比立刻支出 
 元更加划算。

基于上述分析，我们使用如下的模型来衡量时间价值：假设银行的年利率为 
，当前（第 
 年）的 
 元就等价于第 
 年的 
 元；相应的，第 
 年的 
 元的当前价值实际为 
 元。

现给出某项目未来 
 年的预计收入支出情况，在将所有款项转换为当前价值后，试计算该项目的总收益。

输入格式
从标准输入读入数据。

输入的第一行包含空格分隔的一个正整数 
 和一个实数 
，分别表示年数和银行年利率。

输入的第二行包含空格分隔的 
 个整数，依次表示该项目第 
 年的预计收入（正数）或支出（负数）。

输出格式
输出到标准输出中。

输出一个实数，表示该项目在当前价值标准下的总盈利或亏损。

样例输入
2 0.05
-200 100 100
Data
样例输出
-14.059
Data
样例说明
该项目当前支出 
 元，在接下来两年每年收入 
 元。虽然表面看起来收支相抵，但计算当前价值可知总共亏损了约 
 元。

子任务
全部的测试数据满足 
，
 且 
 的有效数字不多于 
 位，每年预计收入（正数）或支出（负数）的绝对值不大于 
。

评分方式
如果你输出的浮点数与参考结果相比，满足绝对误差不大于 
，则该测试点满分，否则不得分。

提示
C/C++：建议使用 double 类型存储浮点数，并使用 scanf("%lf", &x); 进行输入，printf("%f", x); 进行输出。

Python：直接使用 print(x) 进行输出即可。

Java：建议使用 double 类型存储浮点数，可以使用 System.out.print(x); 进行输出。
*/
int main(int argc, char const *argv[])
{
    int n;cin>>n;
    double i,all=0;cin>>i;
    for(int j=0;j<=n;j++){
        int temp;cin>>temp;
        all+= temp*pow(1+i, -j);   
    }
    printf("%.3f", all);
    return 0;
}
