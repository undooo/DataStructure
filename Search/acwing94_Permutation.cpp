#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n;
int state[N];
bool used[N];


void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++) printf("%d ",state[i]);
        puts("");
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            state[u]=i;
            used[i]=true;
            
            dfs(u+1);
            state[u]=0;
            used[i]=false;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin>>n;
    dfs(1);
    return 0;
}
