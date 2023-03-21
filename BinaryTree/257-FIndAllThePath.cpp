#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


void findPath(TreeNode* root, string path, vector<string> result){
    path += to_string(root->val);
    if(root->left == nullptr && root->right == nullptr){
        result.push_back(path);
    }

    if(root->left) findPath(root->left, path+"->", result);
    if(root->right) findPath(root->right, path+"->", result);
    return;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    string path="";
    findPath(root, path, result);
    return result;
}

vector<string> findAllPath(TreeNode* root){
    vector<string> result;
    stack<string> pathSt;
    stack<TreeNode*> nodeSt;
    nodeSt.push(root);
    pathSt.push(to_string(root->val));
    while(!nodeSt.empty()){
        TreeNode* node = nodeSt.top();nodeSt.pop();
        string path = pathSt.top();pathSt.pop();

        if(node->left==nullptr && node->right == nullptr){
            result.push_back(path);
        }
        if(node->left){
            nodeSt.push(node->left);
            pathSt.push(path + "->" + to_string(node->left->val));
        }
        if(node->right){
            nodeSt.push(node->right);
            pathSt.push(path + "->" + to_string(node->right->val));
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
