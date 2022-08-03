#include <bits/stdc++.h>
using namespace std;

// 给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。


int solve(vector<vector<int>> & intervals){
	if(intervals.empty()){
		return 0;
	}

	int n = intervals.size();

	//按照区间结尾升序排列
	sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
		return a[1]<b[1];
	});

	int total = 0,prev = intervals[0][1];
	for(int i=1;i<n;i++){
		if(intervals[i][0]<prev){
			total++;
		}else{
			prev=intervals[i][1];
		}
	}
	return total;
}

int main(int argc, char const *argv[])
{
	std::vector< vector<int> > v(3,vector<int>(2,0));
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[0].size();j++){
			cin>>v[i][j];
		}
	}

	int res=solve(v);
	cout<<res;
	return 0;
}