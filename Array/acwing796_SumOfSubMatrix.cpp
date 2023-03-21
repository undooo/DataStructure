#include<bits/stdc++.h>
using namespace std;

/*
求一个二维矩阵的子矩阵的和

3 4 3
1 7 2 4 
3 6 2 8 
2 1 2 3 
1 1 2 2 
2 1 3 4
1 3 3 4

*/
const int N=1010;
int n,m,q;
int a[N][N], s[N][N];



int main(int argc, char const *argv[])
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }    

    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1]);
    }
    return 0;
}
