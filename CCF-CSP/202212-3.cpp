#include<bits/stdc++.h>
using namespace std;

const int N=10;
//https://blog.csdn.net/weixin_53919192/article/details/129511914?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22129511914%22%2C%22source%22%3A%22weixin_53919192%22%7D

int a[N][N]; //量化矩阵
int n,T;
int d[101];  //扫描数据
double M[N][N]; //蛇形矩阵
double M1[N][N];//乘以量化后的矩阵
double M2[N][N];//逆变换后的矩阵


void print2D(){

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<M[i][j]<<" ";        
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    //get quantization matrix
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d%d",&n,&T);

    for(int i=0;i<n;i++) scanf("%d",&d[i]);
    int index = 0;

    //fill the serpentine matrix
    // 8 top-left bias
    for(int i=0;i<8;i++){
        if(i%2==0){
            for(int j=0;j<=i;j++){
                M[i-j][j] = d[index++];
            }
        }else{
            for(int j=0;j<=i;j++){
                M[j][i-j] = d[index++];
            }
        }
    }
    print2D();

    return 0;
}

