#include <stdc++.h>
using namespace std;


class Solution {
public:
    //暴力遍历
    bool repeatedSubstringPattern(string s) {

        bool match = false;

        for(int i=1;i<s.size();i++){
            if(s.size()%i==0){
                match = true;
                for(int j=i;j<s.size();j++){
                    if(s[j]!=s[j-i]){
                        match = false;
                        break;
                    }
                }
                if(match){
                    return true;
                }
            }
        }
        return false;

    }

	//数学方法
    bool repeatedSubstringPattern2(string s) {

        return (s+s).find(s,1) != s.size();

    }
};


int main(int argc, char const *argv[])
{
	
	return 0;
}