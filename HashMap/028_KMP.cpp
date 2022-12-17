#include<stdc++.h>
using namespace std;


//整体减一的方法对应的next数组
void get_next_array(int * next, const string & s){
	int j=-1;
	next[0] = j;
	for(int i=1; i<s.size();i++){
		while(j>=0 && s[i]!=s[j+1]){//前后缀不同，则回退
			j = next[j];
		}
		if(s[j+1]==s[i]){
			j++;
		}
		next[i] = j;
	}

}

int kmp(string & haystack, string & needle){
	if(needle.size() == 0){
		return -1;
	}
	int next[needle.size()];
	get_next_array(next, needle);

	int j=-1;
	for(int i=0;i<haystack.size();i++){
		while(j>=0 && haystack[i]!=needle[j+1]){
			j = next[j];
		}
		if(haystack[i] == needle[j+1]){
			j++;
		}

		if(j == needle.size()-1){
			return haystack.size()-i+1;
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}