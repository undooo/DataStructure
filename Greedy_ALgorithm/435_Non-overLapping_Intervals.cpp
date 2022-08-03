#include <bits/stdc++.h>
using namespace std;

// ����������䣬��������Щ���以���ص�����Ҫ�Ƴ���������ٸ�������ֹ���������ص���


int solve(vector<vector<int>> & intervals){
	if(intervals.empty()){
		return 0;
	}

	int n = intervals.size();

	//���������β��������
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