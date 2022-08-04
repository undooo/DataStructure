#include <stdc++.h>
using namespace std;

// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
class solutino{
public:
	//快慢指针
 	// 在不影响原顺序的情况下，移除元素
 	int remove_1(vector<int> & nums, int val){
 		int slow=0;
 		for(int fast=0;fast<nums.size();fast++){
 			if(nums[fast]!=val){
 				nums[slow++] = nums[fast];
 			}
 		}
 		return slow;
	}
	// 双向指针
	// 在可以改变相对顺序的前提下，移除元素
	int remove_2(vector<int> & nums, int val){
		//从左往右找，找到左面第一个目标元素，右面第一个非目标元素，覆盖
		int left = 0, right = nums.size()-1;
		while(left<=right){
			//第一个目标元素
			while(left <= right && nums[left]!=val){
				left++;
			}
			//右方非目标元素
			while(left <=right && nums[right]==val){
				right--;
			}
			if (left < right){
				nums[left++] = nums[right--];
			}
		}
		return left;
	}

};



int main(int argc, char const *argv[])
{
	
	return 0;
}