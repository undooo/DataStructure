#include <bits/stdc++.h>
using namespace std;

// 给定两个字符串S 和 T，求S 中包含T 所有字符的最短连续子字符串的长度，同时要求时间
// 复杂度不得超过O(n)
string solve(string S, string T);

int main(int argc, char const *argv[])
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	string res = solve(S,T);

	cout<<res;
	return 0;
}


string solve(string S, string T){
	map<char, int> map;
	vector<bool> flag(128,false);
	//保存数据
	for(int i=0;i<T.size();i++){
		flag[T[i]]=true;
		map[T[i]]++;
	}
	//初始化相关统计数据
	int cnt=0,l=0,min_l=0,min_size=S.size()+1;
	for(int r =0;r < S.size(); r++){
		if(flag[S[r]]){
			if(--map[S[r]] >=0){
				cnt++;
			}
			//尝试左移左指针
			while(cnt == T.size()){
				if(r-l+1 < min_size){
					min_size = r-l+1;
					min_l = l;
				}
				if(flag[S[l]] && ++map[S[l]]>0){
					--cnt;
				}
				++l;
			}
		}
	}
	return min_size > S.size()? "" : S.substr(min_l,min_size);
}

