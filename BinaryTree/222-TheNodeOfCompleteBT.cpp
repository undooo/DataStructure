#include<bits/stdc++.h>
using namespcae std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//递归求结点数
int nodeNumRecursicely(TreeNode* root){
    if(!root) return 0;
    return 1 + nodeNumRecursicely(root->left) + nodeNumRecursicely(root->right);
}

// 层序遍历求结点数
int nodeNumHierarchicaly(TreeNode* root){
    if(!root) return 0;
    int result = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();q.pop();
            ++result;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return result;
}

//通过数学特性求结点数
//判断以当前节点为根的树是否为满二叉树，通过2^n -1 计算
int nodeNumByMath(TreeNode* root){
    if(!root) return 0;
    int leftDepth = 0,rightDepth = 0;
    TreeNode* left = root->left, *right = root->right;
    while(left){
        left = left->left;
        leftDepth++;
    }
    while(right){
        right = right->right;
        rightDepth++;
    }
    if(leftDepth == rightDepth){
        return (2 << leftDepth) -1;
    }
    return nodeNumByMath(root->right) + nodeNumByMath(root->left) + 1;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
