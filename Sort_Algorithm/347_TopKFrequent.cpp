#include <stdc++.h>
using namespace std;

vector<int> topK(vector<int> & nums, int k){
	unordered_map<int,int> counts;
	int maxNum=0;
	//存数字
	for(const auto & num :nums){
		maxNum = max(maxNum,++counts[num]);
	}
	vector<vector<int>> buckets(maxNum+1);
	//将不同出现次数的数字存入vector
	for(const auto & count:counts){
		buckets[count.second].push_back(count.first);
	}
	vector<int> ans;
	for(int i = buckets.size()-1;i>=0 && ans.size()<k;i--){
		for(const int & num:buckets[i]){
			ans.push_back(num);
			if(ans.size() == k){
				break;
			}
		}
	}
	return ans;

}
int main(int argc, char const *argv[])
{
	vector<int> nums = {1,1,1,1,2,2,3,4};
	vector<int> ans = topK(nums,3);
	for(const int & num: ans){
		cout<<num<<" ";
	}
	return 0;
}
