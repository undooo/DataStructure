#include<bits/stdc++.h>
using namespace std;

/*
三个瓶盖可以换一瓶饮料
若初始时就有n瓶饮料，则最后共可得多少瓶饮料
*/
int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int res=n;
    while(n>=3){
        res+= n/3;
        n=n/3+n%3;
    }
    printf("%d",res);
    return 0;
}
