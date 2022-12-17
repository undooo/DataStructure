#include<stdc++.h>
using namespace std;


class freq_comp{
    public:

    bool operator()(const pair<int, int>& l,const pair<int, int>& r){
	    return l.second > r.second;
    }
};


vector<int> TopKFrequent (vector<int>& nums, int k){
	//记录每个数字的频率
	unordered_map <int, int> map;
	for(int i=0; i<nums.size(); i++){
		map[nums[i]]++;
	}

	//创立小顶堆
	priority_queue <pair<int, int>, vector<pair<int, int>>, freq_comp> priQueue;

	//扫描所有的数字
	for(unordered_map<int, int>::iterator it = map.begin(); it!=map.end(); it++){
		priQueue.push(*it);
		if(priQueue.size() >k){
			priQueue.pop();
		}
	}

	//提取结果
	vector<int> ans(k);
	for(int i = k-1;i>=0;i--){
		pair<int, int> temp = priQueue.top();
		priQueue.pop();
		ans[i] = temp.first;
	}

	return ans;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}