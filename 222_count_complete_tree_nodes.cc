#include <iostream>
#include <cstdlib>
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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode *left,*right;
        int countl,countr;
        countl=1;
        left = root->left;
        while(left != NULL) {
            countl++;
            left = left->left;
        }
        countr=1;
        right = root->right;
        while(right != NULL) {
            countr++;
            right = right->right;
        }
        if(countl == countr) {
            return pow(2,countl)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};


//TLE
class Solution2 {
    public:
    bool traversal(TreeNode* root, int level) {
        level++;
        if(root->left == NULL && root->right == NULL) {
            if(first == false) {
                max_level = level;
                ret++;
                first = true;
                return true;
            }
            else {
                if(level >= max_level) {
                    ret++;
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        if(root->left != NULL)
            if(traversal(root->left,level) == false)
                return false;
        if(root->right != NULL)
            if(traversal(root->right,level) == false)
                return false;
        return true;

    } 
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        ret = 0;
        first = false;
        traversal(root,0);
        ret += pow(2,max_level-1) - 1; 
        return ret;
    }
    private:
    int ret;
    int max_level;
    bool first;
};

int main() {
    Solution solu;
    return 0;
}
