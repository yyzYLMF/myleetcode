/*
 * @yang 2015/3/27
 * Given a binary tree
 struct TreeLinkNode {
 TreeLinkNode *left;
 TreeLinkNode *right;
 TreeLinkNode *next;
 }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 */
#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//Time Limit Exceeded
class Solution {
    public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        TreeLinkNode *tempNode;
        TreeLinkNode *lastNode;
        if(root==NULL)
            return;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            tempNode = q.front();
            q.pop();
            if(tempNode == NULL) {
                lastNode->next=NULL;
                lastNode=NULL;
                if(q.empty())
                    break;
                else
                    q.push(NULL);
                continue;
            }
            if(lastNode == NULL)
                lastNode = tempNode;
            else {
                lastNode->next = tempNode;
                lastNode = lastNode->next;
            }
            if(tempNode->left)
                q.push(tempNode->left);
            if(tempNode->right)
                q.push(tempNode->right);
        }
        return;
    }
};

//AC
class Solution2 {
    public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right;
        if (root->next == NULL)
            root->right->next = NULL;
        else
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};

int main() {
    Solution solu;
    Solution2 solu2;
    clock_t start,end;
    TreeLinkNode *a=new TreeLinkNode(1);
    TreeLinkNode *b=new TreeLinkNode(2);
    TreeLinkNode *c=new TreeLinkNode(3);
    a->left=b;
    a->right=c;
    
    start=clock();
    solu.connect(a);
    end=clock();
    cout<<end-start<<endl;
    start=clock();
    solu2.connect(a);
    end=clock();
    cout<<end-start<<endl;

    return 0;
}
