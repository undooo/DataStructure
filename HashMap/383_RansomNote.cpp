#include<stdc++.h>
using namespace std;

//第一个字符串能否由第二个字符串中的内容表示
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
            vector<int> map(26,0);
            for(int i = 0 ; i < ransomNote.size() ; i++){
                    map[ransomNote[i]-'a']++;
            }

            for(int j = 0; j < magazine.size(); j++){
                    map[magazine[j]- 'a']--;
            }

            for(int i = 0; i < 26; i++){
                    if(map[i]>0){
                            return false;
                    }
            }

            return true;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}