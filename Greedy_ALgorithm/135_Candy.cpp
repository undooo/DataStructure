#include <bits/stdc++.h>
using namespace std;


// 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
// 个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
// 有孩子至少要有一个糖果。求解最少需要多少个糖果
vector<int> solve(vector<int>& score){
	//初始化vector，为每个孩子都分配1个糖果
	std::vector<int> result(score.size(),1);

	//从左向右遍历，若比右面的大，则加一个
	for(int i=0;i<score.size()-1;i++){
		if(score[i]>score[i+1]){
			result[i]++;
		}
	}
	//从右向左遍历，若比左面的大且糖果少，则改为左加一
	for(int i=score.size()-1;i>=1;i--){
		if(score[i]>score[i-1] && result[i]<=result[i-1]){
			result[i]=result[i-1]+1;
		}
	}

	return result;
}



int main(int argc, char const *argv[])
{	vector<int> score={1,0,2};
	std::vector<int> res=solve(score);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}

	return 0;
}