#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
    public:
    int str2int(string& input, int p, int q) {
        int ret = 0;
        for(int i=p;i<=q;++i) {
            ret = ret*10 + input[i]-'0';
        }
        return ret;
    }
    vector<int> mydfs(string& input, int p, int q) {
        vector<int> ret;
        vector<int> left;
        vector<int> right;
        int i,j,k,val;
        if(p > q)
            return ret;
        for(i=p;i<=q;++i) {
            if(input[i]=='+' || input[i]=='-' || input[i]=='*') {
                left = mydfs(input,p,i-1);
                right = mydfs(input,i+1,q);
                for(j=0;j<left.size();++j) {
                    for(k=0;k<right.size();++k) {
                        switch(input[i]) {
                            case '+':
                                val = left[j]+right[k];
                                break;
                            case '-':
                                val = left[j]-right[k];
                                break;
                            case '*':
                                val = left[j]*right[k];
                                break;
                        }
                        ret.push_back(val);
                    }
                }
            }
        }
        if(ret.empty()) {
            val = str2int(input,p,q);
            ret.push_back(val);
        }
        //cout<<ret.size()<<endl;
        return ret;
    }

    vector<int> diffWaysToCompute(string input) {
        int i,len;
        vector<int> empty;
        len = input.size();
        if(len == 0)
            return empty;
        //cout<<len-1<<endl;
        return mydfs(input,0,len-1);
    }
};

int main() {
    Solution solu;
    string s;
    cin>>s;
    vector<int> out = solu.diffWaysToCompute(s);
    for(int i=0; i<out.size(); ++i)
        cout<<out[i]<<" ";
    cout<<endl;
    return 0;
}
