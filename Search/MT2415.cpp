/*
	现有两个货船，载重分别为a和b，
	工人需要将k个集装箱装上船，问是否一定可以讲所有货物运上船

	样例输入：
	54 100 5 26 50 30 23 25
	样例输出：
	no
 */

#include<bits/stdc++.h> 

using namespace std;

int c1,c2,n;
int boxw[10];
int sum=0;
int bestC1;
int weight_cur;

void backtrack(int a){
    if(a==n){
        if(weight_cur>bestC1)
            bestC1 = weight_cur;
        return;
    }

    if(weight_cur+boxw[a] <= c1){
        weight_cur+= boxw[a];
        backtrack(a+1);
        weight_cur-= boxw[a];
    }
    backtrack(a+1);
}
int main( )
{   
    cin>>c1>>c2>>n;

    for(int i=0;i<n;i++){
        cin>>boxw[i];
        sum+=boxw[i];
    }

    bestC1 = weight_cur = 0;
    backtrack(0);
    if(sum-bestC1 <= c2){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}