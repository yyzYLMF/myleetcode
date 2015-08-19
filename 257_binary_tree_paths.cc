#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    void myadd(string &str, int val) {
        string temp="";
        long temp_val;
        bool flag=false;
        if(val < 0) {
            temp_val = 0-(long)val;
            flag = true;
        }
        else
            temp_val = val;
        if(temp_val == 0)
            temp = "0";
        while(temp_val != 0) {
            temp.insert(temp.begin(),temp_val%10+'0');
            temp_val = temp_val/10;
        }
        if(flag)
            str = str+"-";
        str = str+temp;
        return;
    }

    void traversal(TreeNode* root, vector<int> temp) {
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            string str="";
            for(int i=0; i<temp.size(); ++i) {
                if(i==0)
                    myadd(str,temp[i]);
                else {
                    str = str+"->";
                    myadd(str,temp[i]);
                }
            }
            ret.push_back(str);
            return;
        }
        if(root->left != NULL)
            traversal(root->left,temp);
        if(root->right != NULL)
            traversal(root->right,temp);
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> empty;
        vector<int> temp;
        if(root==NULL)
            return empty;
        traversal(root,temp);
        return ret;
    }
    private:
    vector<string> ret;
};

int main() {
    Solution solu;
    return 0;
}
