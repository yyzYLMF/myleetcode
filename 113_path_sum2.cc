/*
 * @yang 2015/3/26
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \    / \
  7    2  5   1
 * 
 * returni
 *
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
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
    void traverse(vector<vector<int> > &result, TreeNode *root, int sum, vector<int> tempvec, int tempsum) {
        tempsum += root->val;
        tempvec.push_back(root->val);
        if(root->left==NULL && root->right==NULL) {
            if(tempsum==sum)
                result.push_back(tempvec);
            return;
        }
        if(root->left)
            traverse(result,root->left,sum,tempvec,tempsum);
        if(root->right)
            traverse(result,root->right,sum,tempvec,tempsum);
        return;
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> tempvec;
        if(root==NULL)
            return result;
        traverse(result,root,sum,tempvec,0);
        return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
