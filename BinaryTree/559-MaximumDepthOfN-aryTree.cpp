#include<bits/stdc++.h>
using namespace std;
// 求一个n叉树的最大深度
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root){
    if(!root) return 0;
    int ans=0;
    queue<Node*> que;
    que.push(root);
    
    while(!que.empty()){
        ans++;
        int size = que.size();
        for(int i=0; i<size;i++){
            Node* node = que.front();que.pop();
            for(int j=0;j<node->children.size();j++){
                if(node->children[j]) que.push(node->children[j]);
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
