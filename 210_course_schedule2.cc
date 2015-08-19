#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        int i,j,num,count;
        num = prerequisites.size();
        vector<int> ret;
        vector<int> empty;
        if(numCourses == 0)
            return ret;
        
        set<int> indegree[numCourses];
        set<int> outdegree[numCourses];
        queue<int> qi;

        for(i=0;i<num;++i) {
            indegree[prerequisites[i].first].insert(prerequisites[i].second);
            outdegree[prerequisites[i].second].insert(prerequisites[i].first);
        }
        count = 0;
        for(i=0;i<numCourses;++i) {
            if(indegree[i].size() == 0) {
                qi.push(i);
                count++;
            }
        }
        while(!qi.empty()) {
            int temp = qi.front();
            qi.pop();
            ret.push_back(temp);
            set<int>::iterator pos = outdegree[temp].begin();
            while(pos != outdegree[temp].end()) {
                indegree[*pos].erase(temp);
                if(indegree[*pos].size() == 0) {
                    qi.push(*pos);
                    count++;
                }
                pos++;
            }
        }
        if(count == numCourses)
            return ret;
        else
            return empty;
    }
};

int main() {
    Solution solu;
    vector<pair<int,int> > input;
    input.push_back(make_pair(1,0));
    solu.findOrder(2,input);
    return 0;
}
