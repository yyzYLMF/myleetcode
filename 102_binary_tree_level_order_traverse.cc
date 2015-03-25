/*
 * @yang 2015/3/25
 *
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 */
#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int> > result;
        vector<int> temp;
        TreeNode *tempNode;
        
        if(root==NULL)
            return result;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            tempNode = q.front();
            q.pop();
            if(tempNode==NULL) {
                result.push_back(temp);
                temp.clear();
                if(q.empty())
                    break;
                else {
                    q.push(NULL);
                    continue;
                }
            }
            temp.push_back(tempNode->val);
            if(tempNode->left)
                q.push(tempNode->left);
            if(tempNode->right)
                q.push(tempNode->right);
        }
        return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
