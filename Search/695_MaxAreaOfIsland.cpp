#include <stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& grid,int x,int y);


// 给定一个二维的0-1 矩阵，其中0 表示海洋，1 表示陆地。单独的或相邻的陆地可以形成岛
// 屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。


//递归写法
vector<int> direction{-1,0,1,0,-1};

//主函数
int maxAreaOfIsland(vector<vector<int>> & grid){
	if(grid.empty() || grid[0].empty()){
		return 0;
	}
	int max_area = 0;
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			if(grid[i][j] == 1){
				max_area = max(max_area,dfs(grid,i,j));
			}
		}
	}
	return max_area;
}

//辅函数
int dfs(vector<vector<int>> & grid,int i,int j){
	if(grid[i][j] == 0) return 0;
	grid[i][j] = 0;
	int x,y,area=1;
	for(int k = 0;k<4;k++){
		x = i+direction[k];
		y = j+direction[k+1];
		if(x >=0 && x<grid.size() && y>=0 && y<grid[0].size()){
			area+=dfs(grid,x,y);
		}
	}
	return area;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}