#include<bits/stdc++.h>
using namespace std;

/*
6 3
1 2 2 3 3 4
3
4
5
*/
const int N=100010;

int a[N];
int n,q;

int main(int argc, char const *argv[])
{
    scanf("%d %d",&n, &q);

    for(int i=0;i<n;i++){scanf("%d", &a[i]);}
    
    while(q--){
        int num=0;scanf("%d", &num);

        //找第一次出现的位置
        int l=0, r=n-1, mid=0;
        while(l<r){
            mid = l+r >> 1;
            if(a[mid]>=num){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        if(a[l]==num){
            printf("%d ", l);
            //寻找最后一次出现位置
            r = n-1;
            while(l<r){
                mid = l+r+1>>1;
                if(a[mid]<=num){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            printf("%d\n", l);
        }else{
            printf("-1 -1\n");
        }
    }
    return 0;
}
