#include<bits/stdc++.h>
using namespace std;

/*
四平方和定理，又称为拉格朗日定理：

每个正整数都可以表示为至多 4 个正整数的平方和。

如果把 0 包括进去，就正好可以表示为 4 个数的平方和。

比如：

5=02+02+12+22
7=12+12+12+22
对于一个给定的正整数，可能存在多种平方和的表示法。

要求你对 4 个数排序：

0≤a≤b≤c≤d
并对所有的可能表示法按 a,b,c,d 为联合主键升序排列，最后输出第一个表示法。

输入格式
输入一个正整数 N。

输出格式
输出4个非负整数，按从小到大排序，中间用空格分开。

数据范围
0<N<5∗106
输入样例：
5
输出样例：
0 0 1 2
难度：简单
时/空限制：1s / 64MB
总通过数：11305
总尝试数：39319
来源：第七届蓝桥杯省赛C++A/B组,第七届蓝桥杯省赛JAVAB/C组
算法标签
*/

const int N=5000010;

int n;

void violentSearch(){
    scanf("%d", &n);
        for(int a=0;a*a<=n;a++)
            for(int b=a;a*a+b*b<=n;b++)
                for(int c=b;a*a+b*b+c*c<=n;c++){
                    int left=n-a*a-b*b-c*c;
                    int d = sqrt(left);
                    if(d*d==left){
                        printf("%d %d %d %d",a,b,c,d);
                        return;
                    }
                }  
    return;
}

struct Sum{
    int s,c,d;
    bool operator <(const Sum&t)const{
        if(s!=t.s) return s<t.s;
        if(c!=t.c) return c<t.c;
        return d<t.d;
    }
}sum[N];

int m;

void dichotomousSearch(){
    scanf("%d", &n);
    for(int c=0;c*c<=n;c++)
        for(int d=c;d*d+c*c<=n;d++){
            sum[m++] = {d*d+c*c,c,d};
        }

    sort(sum,sum+m);
    for(int a=0;a*a<=n;a++)
        for(int b=a; a*a+b*b<=n;b++){
            int left = n-a*a-b*b;

            int l=0,r=m-1;
            while(l<r){
                int mid = l+r>>1;
                if(sum[mid].s>=left) r=mid;
                else l=mid+1;
            }
            if(sum[l].s == left){
                printf("%d %d %d %d", a,b,sum[l].c,sum[l].d);
                return;
            }
        }
}

#define x first
#define y second
typedef pair<int, int> PII;
unordered_map<int, PII> umap;

void hash(){
    scanf("%d", &n);
    for(int a=0;a*a<=n;a++)
        for(int b=a;a*a+b*b<=n;b++){
            int t=a*a+b*b;
            if(umap.count(t)==0) umap[t] = {a,b};
        }
    
    for(int c=0;c*c<=n;c++) 
        for(int d=0;d*d+c*c<=n;d++){
            int t=n-c*c-d*d;
            if(umap.count(t)!=0){
                printf("%d %d %d %d", c,d,umap[t].x, umap[t].y);
                return;
            }
        }
}

int main(int argc, char const *argv[])
{
    dichotomousSearch();
    return 0;
}
