#include <stdc++.h>
using namespace std;

class solution{
public :
	vector<int> ans(vector<int> & nums){
		int size = nums.size();
		vector <int> res(size,0);
		int left = 0;
		int right = size-1;
		int index=size-1;
		while(left<=right){
			if(pow(nums[right],2)>= pow(nums[left],2)){
				res[index--] =pow(nums[right--],2);
			}else{
				res[index--] = pow(nums[left++],2);
			}
		}
		return res;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums={-4,-1,0,3,10};
	solution sol;
	std::vector<int> v = sol.ans(nums);
	for(int i=0;i<v.size();i++){
		cout<< v[i] <<" ";
	}
	return 0;
}