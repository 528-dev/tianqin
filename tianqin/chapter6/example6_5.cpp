#include<iostream>
#include<queue>

using namespace std;

typedef struct BTNode* BinTree;
struct BTNode{
    int data = 0;
    BinTree left = NULL, right = NULL;
    BTNode() = default;
    BTNode(int nd, BinTree nl, BinTree nr): data(nd), left(nl), right(nr){}
};

struct NodeInfo{
    BTNode* pNode = NULL;
    int depth = 0, position = 0;
    NodeInfo() = default;
    NodeInfo(BTNode* nb, int nd, int np): pNode(nb), depth(nd), position(np){}
};

// example6_5
// Find the width of the binary tree
int widthOfBinaryTree(BinTree bt){
    int ret = 0, curDepth = -1; // curDepth is the depth of tmp
    queue<NodeInfo*> q;
    NodeInfo *tmp, *left;
    q.push(new NodeInfo(bt, curDepth + 1, 1));
    while (q.size()){
        tmp = q.front();
        q.pop();
        if (tmp->pNode->left){
            q.push(new NodeInfo(tmp->pNode->left, curDepth + 1, 2 * tmp->position));
        }
        if (tmp->pNode->right){
            q.push(new NodeInfo(tmp->pNode->right, curDepth + 1, 2 * tmp->depth + 1));
        }
        if (tmp->depth != curDepth){
            curDepth = tmp->depth;
            left = tmp;
        }
        ret = max(ret, tmp->position - left->position + 1);
    }return ret;
}