#include <stdc++.h>
using namespace std;

// 输入是一个数组和一个值，输出为该值第一次出现的位置和最后一次出现的位置（从0 开
// 始）；如果不存在该值，则两个返回值都设为-1。

int lower_bound (std::vector<int>& v, int target){

	int l=0,r=v.size(),mid;
	while(l<r){
		mid = (l+r)/2;
		if(v[mid] < target){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return l;
}

int upper_bound (std::vector<int>& v, int target){

	int l=0,r=v.size(),mid;
	while(l<r){
		mid = (l+r)/2;
		if(v[mid] <= target){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return l;
}
int main(int argc, char const *argv[])
{
	std::vector<int> v = {5,7,7,8,8,8};
	int target = 2;
	int left = lower_bound(v,target);
	int right = upper_bound(v,target);
	//找不到有两种情况：左边界移动到了size，说明不存在
	//				  左边界仍在0，且不为target
	if(left == v.size() || v[left]!=target){
		cout<<"This number does not exists";
	}else{
		cout<< left <<" " <<right-1;
	}			  

	return 0;
}