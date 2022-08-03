#include <bits/stdc++.h>
using namespace std;

// 在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。

vector<int> solve(vector<int> & numbers, int target){
	vector<int>:: iterator lpt = numbers.begin(), rpt = numbers.end()-1;
	int sum=0;
	while(lpt < rpt){
		sum = *lpt + *rpt;
		
		if(sum == target){
			int l=lpt-numbers.begin()+1;
			int r=rpt-numbers.begin()+1;
			return {l,r};
		}else if(sum < target){
			lpt++;
		}else{
			rpt--;
		}
	}
	return {0,0};

}


int main(){

	vector<int> numbers = {2,5,7,15};
	int target = 9;
	vector<int> ans=solve(numbers,target);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

