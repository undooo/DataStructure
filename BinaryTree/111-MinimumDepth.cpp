#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

int getMinimumDepth(TreeNode* root){
    if(!root) return 0;
    queue<TreeNode*> q;
    int depth = 0;
    q.push(root);
    while(!q.empty()){
        depth++;
        int size = q.size();
        for(int i=0;i<size();i++){
            TreeNode* node = q.front();q.pop();
            if(!node->left && !node->right){
                return depth;
            }
            if(node->left){q.push(node->left);}
            if(node->right){q.push(node->right);}     
        }
    }
    return depth;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
