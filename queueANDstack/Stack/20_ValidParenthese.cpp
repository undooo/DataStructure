#include <stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 !=0) return false;
        stack<char> myStack;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') myStack.push(')');
            else if(s[i]=='[') myStack.push(']');
            else if(s[i]=='{') myStack.push('}');
            else if(myStack.empty() || s[i]!=myStack.top()){
                return false;
            }else{
                myStack.pop();
            }
        }
        return myStack.empty();
    }
};