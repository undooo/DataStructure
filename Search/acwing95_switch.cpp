#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000;
const int N=10;

char g[N][N];
int dx[]={0,0,0,-1,1}, dy[]={0,-1,1,0,0};

void turn(int x, int y){
    for(int i=0;i<5;i++){
        int a = dx[i] + x, b=dy[i] + y;
        if(a>=0 && a<5 && b>=0 && b<5){
            g[a][b] = '0' + ('1'-g[a][b]);
        }
    }
    return;
}


int solve(){
    //通过位来表示所有可能的五种情况
    int res=MAX;

    for(int k=0;k< 2<<5;k++){
        int step=0;
        char backup[N][N];
        memcpy(backup, g, sizeof g);

        //模拟该情况下第一行的开关结果
        for(int j=0;j<5;j++){
            if(k>>j & 1){
                step++;
                turn(0,j);
            }
        }

        //更改后续四行
        for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                if(g[i][j]=='0'){
                 step++;
                 turn(i+1,j);
                }
            }
        }

        //若最后一行全亮，则说明可行
        bool success = true;
        for(int j=0;j<5;j++){
            if(g[4][j]=='0'){
                success=false;
            }
        }

        memcpy(g, backup, sizeof backup);
        if(success) res = min(res, step);
    }
    if(res<=6) return res;
    return -1;
}


int main(int argc, char const *argv[])
{
    int T;scanf("%d", &T);
    
    while(T--){
        for(int i=0;i<5;i++) scanf("%s", g[i]);
        int ans = solve();
        printf("%d\n", ans);
    }    
    return 0;
}
