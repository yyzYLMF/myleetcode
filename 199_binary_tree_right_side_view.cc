/*
 * @yang 2015/4/7
 *
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
      1            <---
    /   \
   2     3         <---
    \     \
     5     4       <---
 * You should return [1, 3, 4].
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<int> traverse(TreeNode *root) {
        vector<int> ret;
        vector<int> left,right;
        int i;
        if(root->left==NULL && root->right==NULL) {
            ret.push_back(root->val);
            return ret;
        }
        if(root->left)
            left = traverse(root->left);
        if(root->right)
            right = traverse(root->right);
        ret=left;
        for(i=0;i<right.size();++i) {
            if(i<ret.size())
                ret[i]=right[i];
            else
                ret.push_back(right[i]);
        }
        ret.insert(ret.begin(),root->val);
        return ret;
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> empty;
        if(root == NULL)
            return empty;
        return traverse(root);
    }
};

int main() {
    Solution solu;
    return 0;
}
