#include <bits/stdc++.h>
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
	if(l+1>=r){return;}
	
	int mid = l +(r-l)/2;
	MergeSort(nums,l,mid);
	MergeSort(nums,mid,r);
	if(nums[mid-1]>nums[mid]){
		Merge(nums,l,mid,r);
	}
}

int main(int argc, char const *argv[])
{
	
	cout<<"Please enter the size of the array:"<<endl;
	int size=0;cin>>size;
	vector<int> v(size);
	cout<<"Please enter the array seperated by space:"<<endl;
	for(int i=0; i<size;i++){
		cin>>v[i];
	}

	cout<<endl;
	// vector<int> v;
	// for(int i = 0; i<20000;i++){
	// 	v.push_back(i);
	// }
	
	clock_t start = clock();
	MergeSort(v,0,v.size());

	clock_t end = clock();
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;

	cout<<"Sorted array:"<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"Total time the merge sort take to sort the array: "<<endtime*1000 <<"ms"<<endl;

	
	return 0;
}