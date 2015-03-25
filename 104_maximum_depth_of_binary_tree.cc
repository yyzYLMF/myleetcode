/*
 * @yang 2015/3/25
 *
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//iterative
class Solution {
    public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> q;
        TreeNode *tempNode;
        int level;

        if(root==NULL)
            return 0;
        q.push(root);
        q.push(NULL);
        level=0;
        while(!q.empty()) {
            tempNode = q.front();
            q.pop();
            if(tempNode==NULL) {
                level++;
                if(q.empty())
                    break;
                else
                    q.push(NULL);
                continue;
            }
            if(tempNode->left)
                q.push(tempNode->left);
            if(tempNode->right)
                q.push(tempNode->right);
        }
        return level;
    }
};

//recursion
class Solution2 {
    public:
    void traverse(TreeNode *root, int level) {
        if(root==NULL)
            return;
        level++;
        if(level>max)
            max=level;
        if(root->left)
            traverse(root->left,level);
        if(root->right)
            traverse(root->right,level);
        return;
    }
    int maxDepth(TreeNode *root) {
        max=0;
        traverse(root,0);
        return max;
    }
    private:
    int max;
};

int main() {
    Solution solu;
    return 0;
}
