#include <bits/stdc++.h>
using namespace std;

/*
    判断一颗二叉树是不是镜像对称的
*/
struct BTree{
    int val;
    BTree* left;
    BTree* right;
    BTree(int x):val(x),left(NULL),right(NULL){}
    BTree(int x, BTree* left, BTree* right):val(x), left(left), right(right){}
};

bool compare(BTree* left, BTree* right){
    if(left==nullptr && right!= nullptr)        return false;
    else if(left!=nullptr && right== nullptr)   return false;
    else if(left==nullptr && right==nullptr)    return true;
    else if(left->val != right->val)            return false;
    else return compare(left->left,right->right) && compare(left->right, right->left);
}

bool isSymmetric(BTree* root){
    if(!root) return true;
    return compare(root->left, root->right);
}


// 非递归方法
bool isSymmetric2(BTree* root){
    if(root == nullptr) return true;
    queue<BTree*> q;
    q.push(root->left);
    q.push(root->right);

    while(!q.empty()){
        BTree* left = q.front();q.pop();
        BTree* right = q.front();q.pop();
        
        if(left == nullptr && right == nullptr) continue;
        if(left == nullptr || right==nullptr || left->val != right->val) return false;

        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }
    return true;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
