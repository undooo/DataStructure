#include<bits/stdc++.h>
using namespace std;

/*
求出一个序列中最长的单调递增子序列

7
3 1 2 1 8 5 6
*/

const int N=1010;
int num[N];
int dp[N];
int n;


int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        for(int j=0;j<i;j++){
            if(num[i]>num[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    printf("%d", dp[n]);
    return 0;
}
