/*
 * @yang 2015/3/26
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void traverse(TreeNode *root, int high) {
        high++;
        if(root->left==NULL && root->right==NULL) {
            if(high<min)
                min=high;
            return;
        }
        if(root->left)
            traverse(root->left,high);
        if(root->right)
            traverse(root->right,high);
        return;
    }
    int minDepth(TreeNode *root) {
        min=INT_MAX;
        if(root==NULL)
            return 0;
        traverse(root,0);
        return min;
    }
    private:
    int min;
};

int main() {
    Solution solu;
    return 0;
}
