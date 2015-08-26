/*
@yang 2015/3/4

Write a function to find the longest common prefix string amongst an array of strings.

*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
    string merge(string left,string right) {
        string ret = "";
        int i,j;
        for(i=0,j=0;i<left.size() && j<right.size(); ++i, ++j) {
            if(left[i] == right[j])
                ret.insert(ret.end(),left[i]);
            else
                break;
        }
        return ret;
    }

    string commonPrefix(vector<string>& strs, int m, int n) {
        int mid;
        string left,right;
        if(m==n)
            return strs[m];
        if(m+1 == n)
            return merge(strs[m],strs[n]);
        mid = (m+n)/2;
        left = commonPrefix(strs,m,mid);
        right = commonPrefix(strs,mid+1,n);
        return merge(left,right);
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ret="";
        int len;
        len = strs.size();
        if(len == 0)
            return ret;
        else if(len == 1)
            return strs[0];
        ret = commonPrefix(strs,0,len-1);
        return ret;
    }
};

//TLE
class Solution2 {
	public:
	string mycompare(string s1, string s2) {
		string::iterator i,j;
		for(i=s1.begin(),j=s2.begin(); i<s1.end() && j<s2.end(); ++i,++j) {
			if(*i != *j)
				break;
		}
		return string(s1.begin(),i);
	}

	string longestCommonPrefix(vector<string> &strs) {
		string result;
		int i;

		if(strs.empty())
			return string("");

		result = strs[0];
		for(i=1; i<strs.size(); ++i)
			result = mycompare(result, strs[i]);
		return result;
	}
};

int main() {
	vector<string> strs;
	string result;
	Solution solu;

	strs.push_back("asdfasdfabc");
	strs.push_back("asdfasfd");
	strs.push_back("asdasdasdfasdf");

	result = solu.longestCommonPrefix(strs);
	cout<<"result: "<<result<<endl;
	return 0;
}
