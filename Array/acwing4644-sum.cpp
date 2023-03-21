#include<bits/stdc++.h>
using namespace std;

/*
给定 n 个整数 a1,a2,⋅⋅⋅,an，求它们两两相乘再相加的和，即

S=a1⋅a2+a1⋅a3+⋅⋅⋅+a1⋅an+a2⋅a3+⋅⋅⋅+an−2⋅an−1+an−2⋅an+an−1⋅an
输入格式
输入的第一行包含一个整数 n。

第二行包含 n 个整数 a1,a2,⋅⋅⋅,an。

输出格式
输出一个整数 S，表示所求的和。

请使用合适的数据类型进行运算。

数据范围
对于 30% 的数据，1≤n≤1000，1≤ai≤100。
对于所有评测用例，1≤n≤200000，1≤ai≤1000。

输入样例：
4
1 3 6 9
输出样例：
117

*/


const int N=200010;

int a[N];

int main(int argc, char const *argv[])
{
    int n;scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    long long res=0;
    long long subSum=0;
    for(int i=n-1;i>0;i--){
        subSum+=a[i];
        long long temp = subSum*a[i-1];
        res+=temp;
    }
    cout<<res;
    return 0;
}
