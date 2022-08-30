#include <stdc++.h>
using namespace std;
//Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
//Return the array in the form [x1,y1,x2,y2,...,xn,yn].

vector<int> solution1(vector<int>& nums, int n){
	vector<int> ans;
    for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
    }
    return ans;
}

//shuffle the vector in O(1) space complexity
vector<int> shuffle(vector<int>& nums, int n) {
	for(int i=0;i<2*n;i++){
	    int j=i;
	    if(nums[i]>0){
	        while(nums[i] > 0){
	            //judge the index corresponding to i
	            j = j<n?2*j : 2*(j-n)+1;
	            swap(nums[i],nums[j]);
	        
	            //mark j as negative
	            nums[j] = - nums[j];
	        }
	        
	    }
	}
	for(int & i: nums){i=-i;}
	return nums;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}