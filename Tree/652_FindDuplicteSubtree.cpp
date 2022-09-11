#include<stdc++.h>
using namespace std;

// Given the root of a binary tree, return all duplicate subtrees.

// For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with the same node values.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map <string, int> map;
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }

    string dfs(TreeNode* root){
        if(root == nullptr) return "";

        string ss = to_string(root->val) + " " + dfs(root->left) + " " + dfs(root->right);
        map[ss]++;
        if(map[ss]==2) ans.push_back(root);
        return ss;
    }
};

int main(int argc, char const *argv[])
{
	int i =0;
    i = i++;
    cout<< i;
	return 0;
}