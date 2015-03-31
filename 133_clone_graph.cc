/*
 * @yang 2015/3/31
 *
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public:
    void traverse(UndirectedGraphNode *node, UndirectedGraphNode *&head, map<int,int> &sign, map<int,UndirectedGraphNode*> &store) {
        int i;
        sign[node->label] = 1;
        head = new UndirectedGraphNode(node->label);
        store[node->label] = head;

        for(i=0;i<node->neighbors.size();++i) {
            UndirectedGraphNode *temp=NULL;
            if(sign[node->neighbors[i]->label]) {
                temp = store[node->neighbors[i]->label];
                head->neighbors.push_back(temp);
            }
            else {
                traverse(node->neighbors[i],temp,sign,store);
                head->neighbors.push_back(temp);
            }
        }
        return;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, int> sign;
        map<int, UndirectedGraphNode* > store;
        if(node == NULL)
            return node;
        UndirectedGraphNode *head;
        traverse(node,head,sign,store);
        return head;
    }
};

int main() {
    Solution solu;
    UndirectedGraphNode *a = new UndirectedGraphNode(-1);
    UndirectedGraphNode *b = new UndirectedGraphNode(1);
    UndirectedGraphNode *result;
    a->neighbors.push_back(b);
    result = solu.cloneGraph(a);
    cout<<result->label<<" "<<result->neighbors[0]->label<<endl;
    return 0;
}
