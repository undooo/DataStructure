#include <stdc++.h>
using namespace std;

//四数之和等于target，不包含重复
//

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i =0; i< nums.size(); i++){
            if(nums[i]>target && nums[i] >0){
                return ans;
            }

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i+1; j<nums.size();j++){
                if(nums[j]+nums[i]>target &&nums[i] + nums[j]>0){
                    break;
                }
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    
                    if((long) nums[i]+nums[j]+nums[left]+nums[right]==target){
                        ans.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        left++;right--;
                        while(left<right && nums[left] == nums[left-1])left++;
                        while(left<right && nums[right] == nums[right+1])right--;

                    }else if((long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}