/*
@yang 2015/3/7

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//KMP best
class Solution {
    public:
    void computePre(string needle, int pre[]) {
        int n,i,k;
        n = needle.size();
        pre[0] = -1;
        k = -1;
        for(i=1;i<n;++i) {
            while(k>=0 && needle[k+1] != needle[i])
                k = pre[k];
            if(needle[k+1]==needle[i])
                k++;
            pre[i] = k;
        }
        return;
    }

    int strStr(string haystack, string needle) {
        int m,n,q,i,ret;
        int *pre;
        m = haystack.size();
        n = needle.size();
        if(n == 0)
            return 0;
        if(m < n)
            return -1;
        pre = new int[n];
        computePre(needle,pre);
        q = -1;
        ret = -1;
        for(i=0; i<m; ++i) {
            while(q>=0 && needle[q+1] != haystack[i])
                q = pre[q];
            if(needle[q+1] == haystack[i])
                q++;
            if(q == n-1) {
                ret = i-n+1;
                break;
            }
        }
        return ret;
    }
};

class Solution2 {
	public:
	int strStr(char *haystack, char *needle) {
		string s1(haystack);
		string s2(needle);
		string::size_type index;

		index = s1.find(s2);
		if(index == s1.npos)
			return -1;
		else
			return index;
	}
};

int main() {
	char a[]="xyxyyxxyx";
	char b[]="xyxyyxxyx";
	Solution solu;
	int index;

	index = solu.strStr(a,b);
	cout<<index<<endl;
	return 0;
}
