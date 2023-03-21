#include <bits/stdc++.h>
using namespace std;

const int N=10010;
int n;
int a[N];


int main(int argc, char const *argv[])
{

    int cnt;scanf("%d\n", &cnt);
    string line;
    while(cnt--){
        getline(cin, line);
        stringstream ssin(line);

        while(ssin>>a[n]) n++;
    }

    sort(a, a+n);
    int n1,m1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) n1=a[i];
        else if(a[i]>=a[i-1]+2) m1=a[i]-1;
    }
    printf("%d %d",m1,n1);
    return 0;
}
