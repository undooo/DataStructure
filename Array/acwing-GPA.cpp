#include<bits/stdc++.h>
using namespace std;


const int N = 20;
int score[10] = {0,60,64,68,72,75, 78,82,85,90};
double value[10] = {0,1.0,1.5,2.0,2.3,2.7,3.0,3.3,3.7,4.0};

int a[N];
int b[N];

double sum=0;
double cnt=0;

double get(int x){
    for(int n=9;n>=0;n--){
        if(b[x]>=score[n]) return value[n];
    }
    return 0.0;
}


int main(int argc, char const *argv[])
{
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n;i++){
        double d = get(i)*a[i];
        sum+=d;
        cnt+=a[i];        
    }
    printf("%.2lf", sum/cnt);
    return 0;
}
