#include<bits/stdc++.h>
using namespace std;


const int N=110;

char start[N], aim[N];

void turn(int x){
    start[x] = start[x]=='o'?'*':'o';
}
int main(int argc, char const *argv[])
{
    scanf("%s", start);
    scanf("%s", aim);

    int n=strlen(start);
    int res=0;
    for(int i=0;i<n-1;i++){
        if(start[i]!=aim[i]){
            turn(i),turn(i+1);
            res++;
        }
    }
    printf("%d", res);
    return 0;
}
