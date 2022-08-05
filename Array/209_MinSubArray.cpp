#include <stdc++.h>
using namespace std;

// 给定一个含有 n 个正整数的数组和一个正整数 s ，
// 找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
class solution{
public:
	int minSubLength(vector<int> & nums, int val){
		int left = 0,right = nums.size()-1;
		int minLen = nums.size(),curLen=0;
		int sum = 0;
		int i = 0;

		for(int j=0;j<nums.size();j++){
			sum += nums[j];
			while(sum >=val){
				curLen = j-i+1;
				minLen = curLen<minLen? curLen : minLen;
				sum -= nums[i++];
			}
		}
		return minLen == nums.size()? 0 : minLen;
	}

};

int main(int argc, char const *argv[])
{
	vector<int> nums={2,3,1,2,2,3,1,3,3};
	solution sol;
	int ans = sol.minSubLength(nums,7);
	cout<< ans;
	return 0;
}