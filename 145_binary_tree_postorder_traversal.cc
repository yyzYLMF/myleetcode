/*
 * @yang 2015/4/1
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 * return [3,2,1].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//use sign stack(two stack), this method is not the best.
class Solution {
    public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *tempNode;
        stack<TreeNode*> st;
        stack<int> sign;
        vector<int> result;
        int right;
        if(root==NULL)
            return result;
        tempNode = root;
        while(tempNode) {
            st.push(tempNode);
            sign.push(0);
            tempNode = tempNode->left;
        }
        while(!st.empty()) {
            tempNode = st.top();
            right = sign.top();
            if(tempNode->right && right==0) {
                sign.pop();
                sign.push(1);
                tempNode = tempNode->right;
                while(tempNode) {
                    st.push(tempNode);
                    sign.push(0);
                    tempNode = tempNode->left;
                }
            }
            else {
                st.pop();
                sign.pop();
                result.push_back(tempNode->val);
            }
        }
        return result;
    }
};

//Without the stack
class Solution2 {
    public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *dump = new TreeNode(0);
        dump->left = root;
        vector<int> ret;
        int L, R;
        TreeNode *cur = dump, *tmp = NULL, *helper = NULL;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                tmp = cur->left;
                while (tmp->right != NULL && tmp->right != cur)
                    tmp = tmp->right;
                if (tmp->right != cur) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    //print
                    L = ret.size();
                    helper = cur->left;
                    while (helper != cur) {
                        ret.push_back(helper->val);
                        helper = helper->right;
                    }
                    R = ret.size() - 1;
                    //reverse
                    while (L < R) {
                        swap(ret[L++], ret[R--]);
                    }

                    tmp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        delete dump;
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
