#include <stdc++.h>
using namespace std;

//思想为：每次挑选出一个最值，只交换一次

void SelectionSort(vector<int> & nums){
	int n = nums.size(),mid;
	for(int i=0;i<n;i++){
		mid=i;
		for(int j=i+1;j<n;j++){
			if(nums[j]<nums[mid]){
				mid = j;
			}
		}
		swap(nums[i],nums[mid]);
	}
}

int main(int argc, char const *argv[])
{
	
	std::vector<int> v = {1,4,3,2,6,5,8,7};
	SelectionSort(v);
	for(int i : v){
		cout<< i <<" ";
	}
	return 0;
}