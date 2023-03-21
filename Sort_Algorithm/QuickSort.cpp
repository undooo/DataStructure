#include <stdc++.h>
using namespace std;

void quickSort(vector<int> &nums,int l,int r){
	//The idea i used is left-closed & right-open,
	//So when there is only one left, it should be l+1>=r 
	if(l+1 >= r){
		return;
	}
	int first=l,last=r-1,key = nums[first];
	while(first<last){
		//The right sentry moves to the left
		while(first<last && nums[last]>=key){
			last--;
		}
		nums[first] = nums[last];
		//The left sentry moves to the right
		while(first<last && nums[first]<=key){
			first++;
		}
		nums[last]=nums[first];
	}
	nums[first] = key;
	quickSort(nums,l,first);
	quickSort(nums,first+1,r); 
}	



// Improved version
// Optimized pivot selecting method  + Aggregating equal elements

// pivot selecting
int selectPivotBymideum(vector<int> & nums, int l, int r){
	int mid = (l+r)/2;//计算数组中间的元素的下标
 
	//使用三数取中法选择枢轴
	if (nums[mid] > nums[r])//ensure nums[mid] <= nums[r]
	{
		swap(nums[mid],nums[r]);
	}
	if (nums[l] > nums[r])//ensure nums[l] <= nums[r]
	{
		swap(nums[l],nums[r]);
	}
	if (nums[mid] > nums[l]) //ensure nums[l] >= nums[mid]
	{
		swap(nums[mid],nums[l]);
	}
	return nums[l];
	
}



void quickSortImproved (vector<int>& nums, int l, int r){
	// quit case
	if(l+1>=r) return;

	int first = l, last = r-1; 				//sentinel
	int lEqualLength = 0, rEqualLength = 0; //The number of the elements equal to pivot
	int key = selectPivotBymideum(nums, l, r-1);

  
	while(first < last){
		while(first < last && nums[last] >= key){
			if(nums[last] == key){
				//move the equal element to the end of the array
				swap(nums[last], nums[r-1-rEqualLength]);	
				rEqualLength++;
			}
			last--;
		}
		nums[first] = nums[last];
		while(first < last && nums[first] <=key){
			if(nums[first] == key){
				//move the equal element to the head of the array
				swap(nums[first], nums[l+lEqualLength]);
				lEqualLength++;
			}
			first++;
		}
		nums[last] = nums[first];
	}
	nums[first] = key;

	//After move the pivot to the right place, we will aggregate the same value together
	int i = l, j = first-1;	//Pointer to swap the elements that are same with pivot
	while(i < j && nums[j] !=key){
		swap(nums[i], nums[j]);
		i++;
		j--;
	} 

	i = first+1; j = r-1;
	while(i < j && nums[i] !=key){
		swap(nums[i], nums[j]);
		i++;
		j--;
	}

	quickSortImproved(nums, l, first-lEqualLength);
	quickSortImproved(nums, first+rEqualLength+1,r);
	
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
	
	clock_t startA = clock();
	//quickSort(v, 0, v.size());
	clock_t endA = clock();
	double endtimeA=(double)(endA-startA)/CLOCKS_PER_SEC;

	clock_t startB = clock();
	quickSortImproved(v,0,v.size());
	clock_t endB = clock();
	double endtimeB=(double)(endB-startB)/CLOCKS_PER_SEC;

	cout<<"Sorted array:"<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"Total time the quick sort take to sort an ordered array: "<<endtimeA*1000 <<"ms"<<endl;
	cout<<"Total time the improved quick sort take to sort an ordered array: "<<endtimeB*1000 <<"ms"<<endl;

	

	return 0;
}