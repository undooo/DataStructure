#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int val):left(NULL),right(NULL),val(val){}
};

//前序遍历
vector<int> preOrderTraversal(TreeNode* root){
	stack<TreeNode *> st;
	vector<int> result;
	if(root == nullptr) return result;

	st.push(root);
	while(!st.empty()){
		TreeNode * node = st.top();
		st.pop();
		result.push_back(node->val);
		if(node->right) st.push(node->right);
		if(node->left)  st.push(node->left);
	}
	return result;
}

//后序遍历 （其实只需要前序遍历改变左右位置，翻转以后便是后序遍历）
vector<int> postOrderTraversal(TreeNode* root){
	vector<int> result;
	stack<TreeNode*> st;
	if(root==nullptr) return result;
	st.push(root);
	while(!st.empty()){
		TreeNode *node = st.top();
		st.pop();
		result.push_back(node->val);
		if(node->left) st.push(node->left);
		if(node->right) st.push(node->right);
	}
	reverse(result.begin(), result.end());
	return result;
}

//中序遍历
vector<int> inOrderTraversal(TreeNode * root){
	vector<int> result;
	stack<TreeNode*> st;
	if(root == nullptr) return result;
	TreeNode * cur = root;
	while(cur !=nullptr || !st.empty()){
		if(cur!=nullptr){
			st.push(cur);
			cur = cur->left;
		}else{
			cur = st.top();
			st.pop();
			result.push_back(cur->val);
			cur = cur->right;
		}
	}
}
int main(int argc, char const *argv[])
{
	
	return 0;
}