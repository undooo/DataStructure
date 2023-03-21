#include<bits/stdc++.h>
using namespace std;

const int N=11;
int n;
bool used[N], backup[N];
int ans;

bool check(int a, int c){
    long long b = (long long)n*c - (long long)a*c;
    if(!a || !b || !c) return false;
    memcpy(backup, used, sizeof used);
    // 判断b是否存在
    while(b){
        int x = b%10;
        b/=10;
        if(!x || backup[x]) return false;
        backup[x] = true;
    }

    // 判断是否全部使用
    for(int i=1;i<=9;i++){
        if(!backup[i]) return false;
    }
    return true;
}


void dfs_c(int u, int a, int c){
    if(u==n) return;
    if(check(a, c)) ans++;

    for(int i=1;i<=9;i++){
        if(!used[i]){
            used[i] = true;
            dfs_c(u+1, a, c*10+i);
            used[i] = false;
        }
    }
}

void dfs_a(int u, int a){
    if(a >= n) return;
    if(a) dfs_c(u, a, 0); //遍历c的取值

    for(int i=1;i<=9;i++){
        if(!used[i]){
            used[i] = true;
            dfs_a(u+1, a*10 + i);
            used[i] = false;
        }
    }
    return;
}


int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    dfs_a(0, 0);
    printf("%d", ans);
    return 0;
}
