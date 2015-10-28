#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    void mydfs(vector<int> &store, vector<vector<int> >& ret, vector<int> temp, int pos) {
        if(pos == store.size()) {
            ret.push_back(temp);
            return;
        }
        mydfs(store,ret,temp,pos+1);
        temp.push_back(store[pos]);
        mydfs(store,ret,temp,pos+1);
        return;
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int> > ret;
        vector<int> store(nums);
        sort(store.begin(),store.end());
        mydfs(store,ret,temp,0);
        return ret;
    }
};

class Solution2 {
    public:
    void mydfs(vector<int> &store, int pos, int rest, vector<int> temp) {
        int i,len=store.size();
        if(rest == 0) {
            ret.push_back(temp);
            return;
        }
        if(rest > len-pos)
            return;
        for(i=pos;i<len;++i) {
            if(i!=pos && store[i] == store[i-1])
                continue;
            temp.push_back(store[i]);
            mydfs(store,i+1,rest-1,temp);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> empty;
        vector<int> store(nums);
        vector<int> temp;
        int i,len=nums.size();
        ret.push_back(empty);
        if(len == 0)
            return ret;
        sort(store.begin(),store.end());
        for(i=len;i>=1;--i) {
            mydfs(store,0,i,temp);
        }
        return ret;
    }
    private:
    vector<vector<int> > ret;
};

int main() {
    Solution solu;
    vector<int> input(1,0);
    cout<<solu.subsets(input).size()<<endl;
    return 0;
}
