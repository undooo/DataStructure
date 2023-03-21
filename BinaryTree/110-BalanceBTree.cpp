#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//返回-1意味该树不为平衡树
int judgeRecursively(TreeNode* root, int depth){
    if(!root) return 0;
    int leftDepth = judgeRecursively(root->left,depth+1);
    int rightDepth = judgeRecursively(root->right,depth+1);

    return abs(leftDepth-rightDepth)>1? -1:max(leftDepth,rightDepth);
}

int backOrderTraverse(TreeNode* root){
    if(!root) return 0;
    stack<TreeNode*> st;
    st.push(root);
    int depth =0;
    int result=0;
    while(!st.empty()){
        TreeNode* node = st.top();
        if(node!=NULL){ 
            st.push(NULL);
            depth++;
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }else{ // father node
            st.pop();
            depth--;
            st.pop();
        }
        result = max(result, depth);
    }
    return result;
}


bool isBalance(TreeNode* root){
    if(!root) return true;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();st.pop();
        if(abs(backOrderTraverse(node->left) - backOrderTraverse(node->right))>1){
            return false;
        }
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    return true;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
