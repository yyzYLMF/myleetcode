/*
 * @yang 2015/4/1
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 * return [1,2,3].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *tempNode;
        if(root == NULL)
            return result;
        st.push(root);
        while(!st.empty()) {
            tempNode = st.top();
            st.pop();
            result.push_back(tempNode->val);
            if(tempNode->right)
                st.push(tempNode->right);
            if(tempNode->left)
                st.push(tempNode->left);
        }
        return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
