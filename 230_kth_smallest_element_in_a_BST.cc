/*
 * @yang 2015/7/28
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 */

#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution  {
    public:
    int getNum(TreeNode* root) {
        int left,right,ret;
        if(sign.find(root) != sign.end())
            return sign[root];
        left = 0;
        if(root->left)
            left = getNum(root->left);
        right = 0;
        if(root->right)
            right = getNum(root->right);
        ret = left + right + 1;
        sign[root] = ret;
        return ret;
    }
    int kthSmallest(TreeNode* root, int k) {
        int left;
        left = 0;
        if(root->left)
            left = getNum(root->left);
        if(left+1 == k)
            return root->val;
        else if(left >= k)
            return kthSmallest(root->left,k);
        else 
            return kthSmallest(root->right,k-left-1);
    }
    private:
    map<TreeNode*,int> sign;
};

int main() {
    Solution solu;
    return 0;
}
