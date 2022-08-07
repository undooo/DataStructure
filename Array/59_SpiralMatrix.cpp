#include <stdc++.h>
using namespace std;
//给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
vector<vector<int>> SpiralMatrix(int n){
	vector<vector<int>> res(n,vector<int>(n,0));
	// 确定初始圈数左上角起点为 0 0
	int startx = 0;
	int starty = 0;
	int count = 1;	//从1开始计数
	int loop = n/2; //确定循环圈数
	int length = n-1; //当前圈数每条边要加的个数
	while(loop--){
		// 确定初始位置
		int x = startx;
		int y = starty;

		// 上边
		for(y;y<starty+length;y++){
			res[x][y] = count++;
		}

		//右边
		for(x;x<startx+length;x++){
			res[x][y] = count++;
		}

		//下边
		for(y;y>starty;y--){
			res[x][y] = count++;
		}

		//左边
		for(x;x>startx;x--){
			res[x][y] = count++;
		}

		//更新起始点
		startx = startx+1;
		starty = starty+1;
		length-=2;
	}
	//若为奇数，则还差中心点需要填补
	if( n%2 == 1){
		res[startx][starty] = count;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	vector<vector<int>> res = SpiralMatrix(6);

	for(auto & row : res){
		for(auto & col : row){
			cout<<col<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}