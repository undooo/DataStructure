#include <bits/stdc++.h>
using namespace std;


// һȺ����վ��һ�ţ�ÿһ���������Լ������֡�������Ҫ����Щ���ӷ��ǹ������������һ
// �����ӵ����ֱ��Լ����Ե�һ������Ҫ�ߣ���ô������Ӿͱ���õ������Ժ��Ӹ�����ǹ�����
// �к�������Ҫ��һ���ǹ������������Ҫ���ٸ��ǹ�
vector<int> solve(vector<int>& score){
	//��ʼ��vector��Ϊÿ�����Ӷ�����1���ǹ�
	std::vector<int> result(score.size(),1);

	//�������ұ�������������Ĵ����һ��
	for(int i=0;i<score.size()-1;i++){
		if(score[i]>score[i+1]){
			result[i]++;
		}
	}
	//���������������������Ĵ����ǹ��٣����Ϊ���һ
	for(int i=score.size()-1;i>=1;i--){
		if(score[i]>score[i-1] && result[i]<=result[i-1]){
			result[i]=result[i-1]+1;
		}
	}

	return result;
}



int main(int argc, char const *argv[])
{	vector<int> score={1,0,2};
	std::vector<int> res=solve(score);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}

	return 0;
}