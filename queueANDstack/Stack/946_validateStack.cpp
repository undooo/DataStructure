#include <stdc++.h>
using namespace std;

// Given two integer arrays pushed and popped each with distinct values, 
// return true if this could have been the result of a sequence of push 
// and pop operations on an initially empty stack, 
// or false otherwise
bool validateStack(vector<int>& pushed, vector<int>& popped){
	stack<int> st;
	int n = pushed.size();
	for(int i=0,j=0;i<n;i++){
		st.emplace(pushed[i]);
		while(!st.empty() && st.top() == popped[j]){
			st.pop();
			j++;
		}
	}
	return st.empty();
}



int main(int argc, char const *argv[])
{
	
	return 0;
}