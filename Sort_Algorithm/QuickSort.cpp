#include <stdc++.h>
using namespace std;


void quick_sort(vector<int> &nums,int l,int r){
	//采用的是左闭右开，因此当只剩一个的时候，应该是l+1>=r
	if(l+1 >= r){
		return;
	}

	int first=l,last=r-1,key = nums[first];
	while(first<last){
		//右哨兵出发，向左遍历
		while(first<last && nums[last]>=key){
			last--;
		}
		nums[first] = nums[last];
		while(first<last && nums[first]<=key){
			first++;
		}
		nums[last]=nums[first];
	}
	nums[first] = key;
	quick_sort(nums,l,first);
	quick_sort(nums,first+1,r); //左闭右开
}	
int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,4,3,2,6,5,8,7};
	quick_sort(v,0,v.size());
	for(int i : v){
		cout<< i <<" ";
	}
	return 0;
}