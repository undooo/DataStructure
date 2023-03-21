#include<bits/stdc++.h>
using namespace std;

/*
计算区间和
5 3
2 1 3 6 4
1 2
1 3 
2 4
*/

const int N=100010;
int n,m;
int a[N];
int s[N];

int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);    
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=a[i]+s[i-1];
    }

    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}
