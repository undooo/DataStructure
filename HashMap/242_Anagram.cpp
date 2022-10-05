#include<stdc++.h>
using namespace std;

//异位词

class Solution {
public:
    bool isAnagram(string s, string t) {
            vector<int> hash(26,0);
            for(int i=0;i<s.size();i++){
                    hash[s[i]-'a']++;
            }

            for(int j=0;j<t.size();j++){
                    hash[t[j]-'a']--;
            }

            for(int i=0;i<26;i++){
                    if(hash[i]!=0) return false;
            }
            
            return true;
    }
};