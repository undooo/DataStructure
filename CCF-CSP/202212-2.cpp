#include<bits/stdc++.h>
using namespace std;

const int N=1010;

int rely[N];
int t[N];
int n,m;
int earliest[N], latest[N];
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>rely[i];
    for(int i=1;i<=m;i++) cin>>t[i];

    int flag=1;

    for(int i=1;i<=m;i++){
        if(rely[i]==0){
            earliest[i]=1;
        }else{
            earliest[i]=earliest[rely[i]] + t[rely[i]];
        }
        if(earliest[i] + t[i] -1 > n) flag=0;
    }
    for(int i=1;i<=m;i++)cout<< earliest[i]<<" ";
    cout<<endl;
    if(flag){
        for(int i=m;i>=1;i--){
            int temp = 400;
            for(int j=i+1;j<=m;j++){
                if(rely[j] == i){
                    temp = min(temp, latest[j]);
                }
            }

            if(temp==400){
                latest[i] = n-t[i]+1;
            }else{
                latest[i] = temp-t[i];
            }
        }
        for(int i=1;i<=m;i++){
            cout<<latest[i]<<" ";
        }
    }
    return 0;
}
