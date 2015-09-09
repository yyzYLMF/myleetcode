#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    public:
    int hIndex(vector<int>& citations) {
        int *temp;
        int i,num=citations.size();
        if(num == 0)
            return 0;
        temp = new int[num+1];
        memset(temp,0,(num+1)*sizeof(int));
        for(i=0;i<num;++i) {
            if(citations[i] > num)
                temp[num]++;
            else
                temp[citations[i]]++;
        }
        int ret = num;
        int sum = 0;
        for(i=num;i>=0;--i) {
            sum += temp[i];
            if(sum>=ret)
                break;
            else
                ret--;
        }
        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> input;
    input.push_back(0);
    input.push_back(0);
    cout<<solu.hIndex(input)<<endl;
    return 0;
}
