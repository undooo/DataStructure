#include<stdc++.h>
using namespace std;

//-1 0 3 5 9 12

int binarySearch(vector<int>&nums, int target){
	int l = 0, r = nums.size();
	while(l<r){
		int mid = (l+r)/2;
		if(nums[mid] == target){
			return mid;
		}else if(nums[mid] > target){
			r = mid;
		}else{
			l = mid+1;
		}
	}
	return -1;
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
	cout<<"Please enter the target number: "<<endl;
	int target;cin>>target;

	clock_t start = clock();
	int posi = binarySearch(v, target);
	clock_t end = clock();
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;

	cout<< "The index of target number "<<target<<" is "<<posi<<endl;
	cout<<"Total time the binarySearch take to sort the array: "<<endtime*1000 <<"ms"<<endl;

	
	return 0;
}