#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int sumOfLeftLeaf(TreeNode* root){
    if(!root) return 0;
    stack<TreeNode*>st;st.push(root);
    int sum=0;
    while(!st.empty()){
        TreeNode* node = st.top();st.pop();
        if(node->left!=nullptr && node->left->left==nullptr && node->left->right==nullptr){
            sum+=node->left->val;
        }
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    return sum;

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
