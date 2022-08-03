#include <stdc++.h>
using namespace std;
// 给定一个整数n 和一个整数k，求在1 到n 中选取m 个数字的所有组合方法。

void backTracking(vector<vector<int>>& ans, int& count,int n,int m, int pos, vector<int>& comb){
	if(count == m){
		ans.push_back(comb);
		return;
	}

	//尝试将下一个数字放进comb中
	for(int i=pos;i<=n;i++){
		comb[count++] = i;
		backTracking(ans,count,n,m,i+1,comb);
		count--;
	}
}
vector<vector<int>>  Combination(int n, int m){
	vector<vector<int>> ans;
	vector<int> comb(m,0);
	int count = 0;
	backTracking(ans,count,n,m,1,comb);
	return ans;
}



int main(int argc, char const *argv[])
{
	
	vector<vector<int>> ans = Combination(5,3);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<< ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}