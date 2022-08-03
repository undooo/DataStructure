#include <stdc++.h>
using namespace std;

vector<int> dir = {-1,0,1,0,-1};
void dfs(vector<vector<int>> & matrix, vector<vector<bool>> & reach, int i, int j){
	if(reach[i][j]){
		return;
	}
	reach[i][j] = true;
	int x,y;
	for(int k =0;k<4;k++){
		x+=dir[k];
		y+=dir[k+1];
		if(x>=0 && x<matrix.size() &&
			y>=0 && y<matrix[0].size() &&
			matrix[x][y]>=matrix[i][j]){
			dfs(matrix,reach,x,y);
		}
	}

}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix){
	if (matrix.empty() || matrix[0].empty()){
		return {};
	}
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> ans;
	vector<vector<bool>> reachP(m,vector<bool> (n,false));
	vector<vector<bool>> reachA(m,vector<bool> (n,false));

	//先从左右边界开始遍历
	for(int i =0;i < m;i++){
		dfs(matrix,reachP,i,0);
		dfs(matrix,reachA,i,n-1);
	}
	//从上下边界遍历
	for(int i = 0;i< n;i++){
		dfs(matrix,reachP,0,i);
		dfs(matrix,reachA,m-1,i);
	}
	//遍历所有的点，如果这个点同时可以到达A和P，则可行
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(reachA[i][j] && reachP[i][j]){
				ans.push_back(vector<int>{i,j});
			}
		}
	}
	return ans;
}



int main(int argc, char const *argv[])
{

	return 0;
}
