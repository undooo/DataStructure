#include<bits/stdc++.h>
using namespace std;
/*
#include<bits/stdc++.h>
using namespace std;

const int N=5010;
int n,m,r;
int s[N][N];


int main(int argc, char const *argv[])
{
    int cnt=0;
    scanf("%d%d",&cnt,&r);
    r=min(5001,r);

    n=m=r;
    
    while(cnt--){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++,y++;
        n=max(n,x),m=max(m,y);
        s[x][y]+=w;
    }

    //求前缀和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    int res=0;
    //求大小为r的子矩阵的最大和，从右下角开始
    for(int i=r;i<=n;i++)
        for(int j=r;j<=m;j++){
            int sum = s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r];
            res = max(res, sum);
        }
    
    printf("%d\n",res);
    return 0;
}

*/
const int N=5010;
int n,m,r;
int s[N][N];


int main(int argc, char const *argv[])
{
    int cnt=0;
    scanf("%d%d",&cnt,&r);
    r=min(5001,r);

    n=m=r;

    while(cnt--){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++,y++;
        n=max(n,x),m=max(m,y);
        s[x][y]+=w;
    }

    //求前缀和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    int res=0;
    //求大小为r的子矩阵的最大和，从右下角开始
    for(int i=r;i<=n;i++)
        for(int j=r;j<=m;j++){
            int sum = s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r];
            res = max(res, sum);
        }
    
    printf("%d\n",res);
    return 0;
}
