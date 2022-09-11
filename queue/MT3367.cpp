/*
	现有一条队伍，小码哥观察人员进出情况时，有以下两种记录
	1. 队伍进入一个人
		1. 知道该人名字
		2. 但不知道该人是否站在队尾还是插队
	2. 队伍中离开一个人
		1. 知道这个人的名字
		2. 知道这个人一定是队伍最前端的人
	现给出n条队伍进出信息，求有多少同学没有插队

	样例输入：
	10
	in z5mrnk4wjp
	in 30o01ci902
	in hu2jc04d9
	in 07t
	in uzplc2
	out z5mrnk4wjp
	out 07t
	out 30o01ci902
	out hu2jc04d9
	out uzplc2
	样例输出：
	4
 */

#include<bits/stdc++.h> 

using namespace std;

long long n_stu;
int ans;

queue<string> nameIn;
set<string> Jumpers;

int main( )
{
    cin>>n_stu;
    ans = n_stu/2;
    string type,temp;
    
    for(long long i=0;i<n_stu;i++){
        type.clear();
        temp.clear();
        type.resize(3);
        temp.resize(100);

        scanf("%s %s\n",&type[0],&temp[0]);
        
        if( type.at(0) == 'i'){
            
            nameIn.push(temp);
        }else{//出队列
            string first = nameIn.front();
            //先查看当前队首的是否是插队的同学，若是，则取下一个
            while(!Jumpers.empty() && Jumpers.count(first)==1){
                nameIn.pop();
                first = nameIn.front();
            }
            if(temp == first){//若相等则说明是正常同学
                nameIn.pop();
                continue;
            }else{//若不同，说明该同学插队了
                
                Jumpers.insert(temp);
                ans--;
            }
        }
        
    }
    cout<<ans;
    return 0;
}