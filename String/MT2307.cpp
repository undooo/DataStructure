#include<bits/stdc++.h> 

using namespace std;

string a0 = "IAKIOI";
string a1 = "WHENWILLSCORLLOFTAIWUCOMEOUT!!!";
//保存字符串数组
vector<string> ss={a0,a1};
vector<unsigned long long> len_arr;

//递归搜索
char search(int n, int c){
    while(1){
        if(n==0 || n==1){
        return ss[n][c-1];
        }
        long long len1 = len_arr[n-2];
        long long len2 = len_arr[n-1];
        if(c>len1){
            n=n-1;
            c=c-len1;
        }else{
            n=n-2;
        }
    }
}

int main( )
{
    int n=0;
    int c=0;
    //读取输入信息
    cin>>n>>c;

    //初始化信息
    len_arr.push_back(a0.length());
    len_arr.push_back(a1.length());

    //获取第n项字符串的长度
    for(int i=2;i<=n;i++){
        len_arr.push_back(len_arr[len_arr.size()-1]+len_arr[len_arr.size()-2]) ;
    }

    printf("%c",search(n,c));
    return 0;
}