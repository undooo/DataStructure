#include<stdc++.h>
using namespace std;


int n,m; //the size of matrix

int shortestPath(vector<vector<int>> & nums){
	vector<vector<int>> dp(n,vector<int>(m,0));
	dp[0][0] = nums[0][0];

	// set the first column
	for(int i=1;i<nums.size();i++){
		dp[i][0] = nums[i][0]+dp[i-1][0];
	}

	// set the first row
	for(int i=1;i<nums[0].size();i++){
		dp[0][i] = nums[0][i]+dp[0][i-1];
	}

	// set all the other nodes
	for(int i=1;i<nums.size();i++){
		for(int j=1;j<nums[0].size();j++){
			dp[i][j] = nums[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[nums.size()-1][nums[0].size()-1];
}


int main(int argc, char const *argv[])
{
	cout<<"Please enter the width n and height m of the matrix (seperated by space):"<<endl;
	cin>>n>>m;
	vector<vector<int>> nums(n,vector<int>(m,0));
	cout<<"Please enter the matrix:"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>nums[i][j];
		}
	}
	
	int ans = shortestPath(nums);
	cout<< "The shortest length from the top left to the bottom right is :"<<ans<<endl;
	return 0;
}