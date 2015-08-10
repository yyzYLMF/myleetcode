#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
    public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int i,count,numP=prerequisites.size();
        set<int> indegree[numCourses];
        set<int> outdegree[numCourses];
        queue<int> qi;
        
        if(numP == 0)
            return true;
        for(i=0;i<numP;++i) {
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
        cout<<count<<endl;
        while(!qi.empty()) {
            int temp = qi.front();
            qi.pop();
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
            return true;
        else
            return false;
    }
};

int main() {
    vector<pair<int,int> > input;
    input.push_back(make_pair(1,0));
    Solution solu;
    cout<<solu.canFinish(2,input)<<endl;
    return 0;
}
