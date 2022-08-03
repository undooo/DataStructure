#include <stdc++.h>
using namespace std;


//插入排序的思想为：每有一个新的元素，就把它放到之前元素应该在的位置

void Insertion_Sort(vector<int> & nums){
	int size = nums.size();
	for(int i=1;i<size;i++){
		for(int j=i;j>0 && nums[j]<nums[j-1];j--){
			swap(nums[j],nums[j-1]);
		}
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,4,3,2,6,5,8,7};
	Insertion_Sort(v);
	for(int i : v){
		cout<< i <<" ";
	}
	return 0;
}