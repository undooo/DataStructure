#include<stdc++.h>
using namespace std;

int quickSelection(vector<int> &nums,int l, int r){
	int key = nums[l];
	r--;
	while(l<r){
		while(l<r && nums[r]>=key){
			r--;
		}
		nums[l]=nums[r];
		while(l<r && nums[l]<=key){
			l++;
		}
		nums[r]=nums[l];
	}
	nums[l] = key;
	return l;
}

int findKthLargest(vector<int> & nums, int k){
	int r = nums.size(),l=0,target = nums.size() - k;
	while(l<r){
		int mid = quickSelection(nums,l,r);
		if(mid == target){
			return nums[mid];
		}else if(mid<target){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return nums[l];

}




int main(int argc, char const *argv[])
{
	std::vector<int> v = {3,2,1,5,6,4};
	cout<<findKthLargest(v,5);
	return 0;
}