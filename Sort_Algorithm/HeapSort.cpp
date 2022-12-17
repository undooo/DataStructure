#include<stdc++.h>
using namespace std;

void sink(vector<int>&nums, int i, int k){

	int parent = i;
	int child = parent*2 + 1;
	while(child<=k){
		// find the child with max value
		if(child + 1 <= k && nums[child+1]>nums[child]){
			child++;
		}
		//sink
		if(nums[parent]>=child){
			return;
		}else{
			swap(nums[parent], nums[child]);
			parent = child;
			child = parent*2 +1;
		}
	}
}


void heapSort(vector<int> &nums){
	int size = nums.size()-1;

	// Build the heap
	for(int i=(size-1)/2;i>=0;i--){
		sink(nums, i,size);
	}

	// Heap sort
	for(;size>0;size--){
		swap(nums[0],nums[size]);
		// sink the root to the right position
		sink(nums, 0, size-1);
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
	heapSort(v);
	clock_t end = clock();
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;

	cout<<"Sorted array:"<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"Total time the heap sort take to sort the array: "<<endtime*1000 <<"ms"<<endl;

	
	return 0;
}