#include <bits/stdc++.h>

// 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
// 一个饼干，且只有饼干的大小不小于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩子
// 可以吃饱。
int solve(std::vector<int> child, std::vector<int> cookie){
	sort(child.begin(),child.end());
	sort(cookie.begin(),cookie.end());
	int chNum=0,cooNum=0;
	while(chNum < child.size() && cooNum < cookie.size()){
		if(child[chNum] <= cookie[cooNum]){
			chNum++;
		}
		cooNum++;
	}	
	return chNum;
}

int main(int argc, char const *argv[])
{
	std::vector<int> child={1,2};
	std::vector<int> cookie={1,2,3};
	int result = solve(child,cookie);
	std::cout<<result;
	return 0;
}