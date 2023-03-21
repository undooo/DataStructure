#include <bits/stdc++.h>
using namespace std;
// ����һ������n ��һ������k������1 ��n ��ѡȡm �����ֵ�������Ϸ�����

void backTracking(vector<vector<int>>& ans, int& count,int n,int m, int pos, vector<int>& comb){
	if(count == m){
		ans.push_back(comb);
		return;
	}

	//���Խ���һ�����ַŽ�comb��
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