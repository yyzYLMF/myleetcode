/*
 * @yang 2015/3/25
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]
 */
#include <iostream>
#include <cstdlib>
#include <queue>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
       queue<stack<TreeNode*> > qs;
       int sign;
       vector<vector<int> > result;
       vector<int> tempval;
       stack<TreeNode*> stackNode;
       TreeNode *tempNode;
       stack<TreeNode*> temps;

       if(root==NULL)
           return result;
       temps.push(root);
       qs.push(temps);
       sign=1;
       while(!qs.empty()) {
           stackNode=qs.front();
           qs.pop();
           stack<TreeNode*> temps;
           while(!stackNode.empty()) {
               tempNode = stackNode.top();
               stackNode.pop();
               tempval.push_back(tempNode->val);
               if(sign==1) {
                    if(tempNode->left)
                        temps.push(tempNode->left);
                    if(tempNode->right)
                        temps.push(tempNode->right);
               }
               else {
                   if(tempNode->right)
                       temps.push(tempNode->right);
                   if(tempNode->left)
                       temps.push(tempNode->left);
               }
           }
           result.push_back(tempval);
           tempval.clear();
           if(!temps.empty())
               qs.push(temps);
           sign=(sign+1)%2;
       }
       return result;
    }
};

int main() {
    Solution solu;
    return 0;
}
