#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
    public:
    int hIndex(vector<int>& citations) {
        int i,num=citations.size();
        if(num == 0)
            return 0;
        int ret = num;
        for(i=0;i<num;++i) {
            if(citations[i] >= ret)
                break;
            else
                ret--;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    return 0;
}
