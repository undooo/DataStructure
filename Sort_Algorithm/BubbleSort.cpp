#include <stdc++.h>
using namespace std;
//不停的交换，每次保证选出一个最值
void bubble_sort(vector<int> &nums) {
	bool swapped = false;
	int n = nums.size();
	for(int i=1;i<n;i++){
		swapped = false;
		for(int j=1;j<n-i+1;j++){
			if(nums[j-1]>nums[j]){
				swap(nums[j-1],nums[j]);
				swapped = true;
			}
		}
		if(!swapped){
			break;
		}
	}
}


int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,4,3,2,6,5,8,7};
	bubble_sort(v);
	for(int i : v){
		cout<< i <<" ";
	}
	return 0;
}