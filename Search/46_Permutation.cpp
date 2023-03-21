#include <bits/stdc++.h>
using namespace std;


void backtracking(vector<int> &nums,int level,vector<vector<int>> &ans){
	if(level == nums.size()){
		ans.push_back(nums);
		return;
	}

	//将当前level位与之后的每一位交换
	for(int i= level;i<nums.size();i++){
		swap(nums[level],nums[i]);
		backtracking(nums,level+1,ans);
		swap(nums[level],nums[i]);
	}
}
vector<vector<int>> permute(vector<int> &nums){
	vector<vector<int>> ans;
	backtracking(nums,0,ans);
	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> nums{1,2,3,4};
	vector<vector<int>> ans = permute(nums);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<< ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}