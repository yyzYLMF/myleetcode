#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int nthUglyNumber(int n) {
        vector<int> store;
        int ret,i,cur;
        if(n == 1)
            return 1;
        store.push_back(1);
        int pos[3],temp[3];
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;
        for(i=2;i<=n;++i) {
            temp[0] = store[pos[0]]*2;
            temp[1] = store[pos[1]]*3;
            temp[2] = store[pos[2]]*5;
            if(temp[0] < temp[1])
                cur = 0;
            else
                cur = 1;
            if(temp[2] < temp[cur])
                cur = 2;
            ret = temp[cur];
            pos[cur]++;
            if(ret == store[store.size()-1])
                i--;
            else
                store.push_back(ret);
        }
        return ret;
    } 
};

int main() {
    Solution solu;
    int n;
    cin>>n;
    cout<<solu.nthUglyNumber(n)<<endl;
    return 0;
}
