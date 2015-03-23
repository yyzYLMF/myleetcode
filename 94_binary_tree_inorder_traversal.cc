/*
 * @yang 2015/3/23
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 * return [1,3,2].
 *
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

//Recursive method
class Solution {
    public:
    void traversal(vector<int> &result, TreeNode *root) {
        if(root==NULL)
            return;
        traversal(result,root->left);
        result.push_back(root->val);
        traversal(result,root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(result,root);
        return result;
    }
};

//Iterative method
class Solution2 {
    public:
    struct Node
    {
        TreeNode *tNode;
        bool findLeft;
        Node(){}
        Node(TreeNode *n,bool s):tNode(n), findLeft(s){}
    };
    vector<int> inorderTraversal(TreeNode *root) {
        stack<Node> s;
        s.push(Node(root, false));
        vector<int> ret;

        while(!s.empty())
        {
            Node node = s.top();
            if (node.tNode == NULL)
                s.pop();
            else
            {
                if (!node.findLeft)
                {
                    s.pop();
                    s.push(Node(node.tNode, true));
                    s.push(Node(node.tNode->left, false));
                }
                else
                {
                    s.pop();
                    ret.push_back(node.tNode->val);
                    s.push(Node(node.tNode->right, false));
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution solu;
    Solution2 solu2;
    vector<int> result;
    TreeNode mynode(1);
    result=solu2.inorderTraversal(&mynode);
    for(int i=0;i<result.size();++i)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
