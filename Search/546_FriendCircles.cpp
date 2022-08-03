#include <stdc++.h>
using namespace std;


// 给定一个二维的0-1 矩阵，如果第(i, j) 位置是1，则表示第i 个人和第j 个人是朋友。已知
// 朋友关系是可以传递的，即如果a 是b 的朋友，b 是c 的朋友，那么a 和c 也是朋友，换言之这
// 三个人处于同一个朋友圈之内。求一共有多少个朋友圈。

vector<int> direction={-1,0,1,0,-1};

void dfs(vector<vector<int>> & grid,int i,vector<bool> & visited){
	visited[i] =true;
	for(int k=0;k<grid.size();k++){
		if(grid[i][k]==1 && !visited[k]){
			dfs(grid,k,visited);
		}
	}
	return;
}

int CountCircle(vector<vector<int>> & grid){
	int maxCircle = 0;
	if(grid.empty()) return 0;
	vector<bool> visited(grid.size(),false);
	for(int i=0;i<grid.size();i++){
		if(!visited[i]){
			maxCircle++;
			dfs(grid,i,visited);
		}
	}
	return maxCircle;
}



int main(int argc, char const *argv[])
{
	
	return 0;
}