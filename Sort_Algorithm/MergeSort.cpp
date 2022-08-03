#include <stdc++.h>
using namespace std;

//归并排序：核心思想是分治
//将数组的左右两半都排好序后，再借用一个额外空间，将其合并，再赋给原数组

void Merge(vector<int> &nums,int l, int mid,int r){
	//分配临时空间
	vector<int> temp(r-l,0);
	int i=l,j=mid,k=0;
	while(i<mid && j<r){
		if(nums[i] <=nums[j]){
			temp[k++] = nums[i++];
		}else{
			temp[k++] = nums[j++];
		}
	}

	//将有剩余的部分赋给数组
	while(i<mid){
		temp[k++] = nums[i++];
	}

	while(j<r){
		temp[k++] = nums[j++];
	}
	//将temp赋给num
	for(i=l,k=0;i<r;i++,k++){
		nums[i] = temp[k];
	}

}

void MergeSort(vector<int> & nums,int l, int r){
	if(l<r-1){//-1的原因是左闭右开
		int mid = l +(r-l)/2;
		MergeSort(nums,l,mid);
		MergeSort(nums,mid,r);
		Merge(nums,l,mid,r);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v = {4,1,3,2,6,5,8,7,9};
	MergeSort(v,0,v.size());
	for(int i : v){
		cout<< i <<" ";
	}
	return 0;
}