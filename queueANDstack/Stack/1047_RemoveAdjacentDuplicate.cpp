class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> myStack;

        for(char str: s){
            if(myStack.empty() || str != myStack.top()){
                myStack.push(str);
                continue;
            }
            myStack.pop();
        }

        while(!myStack.empty()){
            ans+=myStack.top();
            myStack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};