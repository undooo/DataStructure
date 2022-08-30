#include <stdc++.h>
using namespace std;

// 最大树 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。

// 给你最大树的根节点 root 和一个整数 val 。

// 就像 之前的问题 那样，给定的树是利用 Construct(a) 例程从列表 a（root = Construct(a)）递归地构建的：

// - 如果 a 为空，返回 null 。
// - 否则，令 a[i] 作为 a 的最大元素。创建一个值为 a[i] 的根节点 root 。
// - root 的左子树将被构建为 Construct([a[0], a[1], ..., a[i - 1]]) 。
// - root 的右子树将被构建为 Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]) 。
// - 返回 root 。
// 请注意，题目没有直接给出 a ，只是给出一个根节点 root = Construct(a) 。

// 假设 b 是 a 的副本，并在末尾附加值 val。题目数据保证 b 中的值互不相同。

// 返回 Construct(b) 。

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode * left, TreeNode * right):val(x),left(left),right(right){}
};

class Solution {
public:
	//方法一，递归方法
	//若传入节点大于跟，则将根作为新节点的左子树
	//若传入节点小，则更新根节点的右子树
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root || root->val <val) return new TreeNode(val,root,nullptr);
        root->right = insertIntoMaxTree(root->right,val);
        return root;
    }

    //方法二，模拟
    TreeNode* insertII(TreeNode* root, int val){
    	TreeNode* node(val);
    	TreeNode* prev=nullptr,cur=root;
    	while(cur && cur->val > val){
    		prev = cur;
    		cur = cur->right;
    	}
    	if(prev == nullptr){
    		return new TreeNode(val,root,nullptr);
    	}else{
    		prev->right = node;
    		node->left = cur;
    		return root;
    	}
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}