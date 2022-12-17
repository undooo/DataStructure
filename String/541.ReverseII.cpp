class Solution {
public:
    // Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
    // If there are fewer than k characters left, reverse all of them. 
    // If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
    
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i+=2*k){
            
            if(i+k< s.size()){
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};