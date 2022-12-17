#include <stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//翻转一颗二叉树

//递归法
TreeNode* InvertBinaryTree_recursive(TreeNode* root){
        if(root == nullptr) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;	
}

//深度优先（前序遍历）
TreeNode* InvertBinaryTree_PreOrder(TreeNode* root){
	stack<TreeNode*> st;
	if(root==nullptr) return root;
	st.push(root);
	while(!st.empty()){
		TreeNode* node = st.top();
		st.pop();
		swap(node->left, node->right);
		if(node->right) st.push(node->right);
		if(node->left) st.push(node->left);
	}
	return root;
}




int main(int argc, char const *argv[])
{
	
	return 0;
}