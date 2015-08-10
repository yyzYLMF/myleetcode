#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
    public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long overlap,area;
        area = (C-A)*(D-B)+(G-E)*(H-F);
        int l1 = max(A,E);
        int l2 = min(C,G);
        int h1 = max(B,F);
        int h2 = min(D,H);
        if(l2<=l1 || h2<=h1)
            overlap = 0;
        else
            overlap = (l2-l1)*(h2-h1);
        return area-overlap;
    }
};

int main() {
    Solution solu;
    cout<<solu.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1)<<endl;
    return 0;
}
