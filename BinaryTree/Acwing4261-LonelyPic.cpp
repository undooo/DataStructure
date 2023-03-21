#include<bits/stdc++.h>
using namespace std;
/*
Farmer John 最近购入了 N 头新的奶牛，每头奶牛的品种是更赛牛（Guernsey）或荷斯坦牛（Holstein）之一。

奶牛目前排成一排，Farmer John 想要为每个连续不少于三头奶牛的序列拍摄一张照片。

然而，他不想拍摄这样的照片，其中只有一头牛的品种是更赛牛，或者只有一头牛的品种是荷斯坦牛——他认为这头奇特的牛会感到孤立和不自然。

在为每个连续不少于三头奶牛的序列拍摄了一张照片后，他把所有「孤独的」照片，即其中只有一头更赛牛或荷斯坦奶牛的照片，都扔掉了。

给定奶牛的排列方式，请帮助 Farmer John 求出他会扔掉多少张孤独的照片。

如果两张照片以不同位置的奶牛开始或结束，则认为它们是不同的。

输入格式
输入的第一行包含 N。

输入的第二行包含一个长为 N 的字符串。如果队伍中的第 i 头奶牛是更赛牛，则字符串的第 i 个字符为 G。否则，第 i 头奶牛是荷斯坦牛，该字符为 H。

输出格式
输出 Farmer John 会扔掉的孤独的照片数量。

数据范围
3≤N≤5×105
输入样例：
5
GHGHG
输出样例：
3
样例解释
这个例子中的每一个长为 3 的子串均恰好包含一头更赛牛或荷斯坦牛——所以这些子串表示孤独的照片，并会被 Farmer John 扔掉。

所有更长的子串（GHGH、HGHG 和 GHGHG）都可以被接受。

*/
typedef long long ll;

const int N = 500010;
char str[N];
int l[N],r[N];

int main(int argc, char const *argv[])
{
    int n;scanf("%d",&n);
    scanf("%s",str);

    //更新左近邻
    for(int i=0,g=0,h=0;i<n;i++){
        if(str[i]=='G') l[i]=h,h=0,g++;
        else l[i]=g,g=0,h++;
    }

    //更新右近邻
    for(int i=n-1,g=0,h=0;i>=0;i--){
        if(str[i]=='G') r[i]=h,h=0,g++;
        else r[i]=g,g=0,h++;
    }
    ll res=0;
    //计算
    for(int i=0;i<n;i++){
        res+= (ll)l[i]*r[i] + max(0, l[i]-1) + max(0, r[i]-1);
    }
    printf("%lld\n", res);
    
    return 0;
}
