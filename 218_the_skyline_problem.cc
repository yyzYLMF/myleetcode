/*
 * @yang 2015/7/13
 *
 * A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo, write a program to output the skyline formed by these buildings collectively
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (int i=0;i<buildings.size(); ++i) {
            h.push_back(pair<int,int>(buildings[i][0],-buildings[i][2]));
            h.push_back(pair<int,int>(buildings[i][1],buildings[i][2]));
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (int i=0;i<h.size();++i) {
            if (h[i].second < 0) m.insert(-h[i].second);
            else m.erase(m.find(h[i].second));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back(pair<int,int>(h[i].first, cur));
                pre = cur;
            }
        }
        return res;
    }
};

int main() {
    Solution solu;
    vector<vector<int> > input;
    vector<int> i1;
    i1.push_back(2);
    i1.push_back(9);
    i1.push_back(10);
    vector<int> i2;
    i2.push_back(3);
    i2.push_back(7);
    i2.push_back(15);
    vector<int> i3;
    i3.push_back(5);
    i3.push_back(12);
    i3.push_back(12);
    vector<int> i4;
    i4.push_back(13);
    i4.push_back(14);
    i4.push_back(12);
    input.push_back(i1);
    input.push_back(i2);
    input.push_back(i3);
    input.push_back(i4);
    vector<pair<int,int> > ret = solu.getSkyline(input);
    for(int i=0; i<ret.size(); ++i)
        cout<<ret[i].first<<" "<<ret[i].second<<endl;

    return 0;
}
