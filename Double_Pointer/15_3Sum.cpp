#include <stdc++.h>
using namespace std;

//找到所有三数之和为0的三元组，不能包含重复的情况
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //将数组进行排序
        sort(nums.begin(),nums.end());

        //双（三）指针法
        vector<vector<int>> ans;
        for(int i=0; i< nums.size(); i++){
            if(nums[i] >0){
                return ans;
            }

            //去重
            if(i >0 && nums[i] == nums[i-1]){
                continue;
            }

            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    //进一步去重
                    while(l<r && nums[l]==nums[l+1]){l+=1;}
                    while(l<r && nums[r-1] == nums[r]){r-=1;}
                    l++;r--;
                }else if (nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }else{
                    r--;
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