/*
 * @yang 2015/7/9
 *
 * Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
 * For example:
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//AC KMP method
class Solution {
    public:
    void computePre(string P, int pre[]) {
        int i,k,n;
        n = P.size();
        pre[0] = -1;
        k = -1;
        for(i=1;i<n;++i) {
            while(k>=0 && P[k+1] != P[i])
                k = pre[k];
            if(P[k+1] == P[i])
                k++;
            pre[i] = k;
        }
        return;
    }

    int myKMP(string T, string P) {
        int i,q,m,n;
        int* pre;
        m = T.size();
        n = P.size();
        pre = new int[n];
        computePre(P,pre);
        q = -1;
        for(i=0; i<m; ++i) {
            while(q>=0 && P[q+1] != T[i])
                q = pre[q];
            if(P[q+1] == T[i])
                q++;
        }
        return m-(q+1);
    }

    string shortestPalindrome(string s) {
        int i,len,temp;
        string copy_rev(s);
        string copy(s);
        string ret1,ret2;
        len = s.size();
        if(len <= 1)
            return s;
        reverse(copy_rev.begin(),copy_rev.end());
        temp = myKMP(copy_rev,copy);
        ret1 = copy_rev.substr(0,temp) + copy;
        return ret1;
        //temp = myKMP(copy,copy_rev);                  //只能在前面加
        //ret2 = copy.substr(0,temp) + copy_rev;
        //if(ret1.size() <= ret2.size())
        //    return ret1;
        //else
        //    return ret2;
    }
};

//TLE
class Solution2 {
    public:
    bool isTrue(string s, int pos) {
        int i,j;
        i = pos-1;
        j = pos+1;
        while(i>=0 && j<s.size()) {
            if(s[i] != s[j])
                break;
            i--;
            j++;
        }
        if(i>=0 && j<s.size())
            return false;
        else
            return true;
    }

    string shortestPalindrome(string s) {
        int i,j,len;
        int *sign;
        string ret;
        if(s.size() <= 1) 
            return s;
        len = s.size();
        sign = new int[len];
        memset(sign,0,len*sizeof(int));
        sign[0] = 1;
        sign[len-1] = 1;
        for(i=1;i<len-1;++i) {
            if(isTrue(s,i))
                sign[i] = 1;
        }
        for(i=len/2; i>=0; --i) {
            if(sign[i] == 1)
                break;
        }
        for(j=len/2; j<len; ++j) {
            if(sign[j] == 1)
                break;
        }
        ret = s;
        if(len-2*i-1 <= 2*j-len+1) {
            for(j=2*i+1; j<len; ++j)
                ret.insert(ret.begin(),s[j]);
        }
        else {
            for(i=2*j-len; i>=0; --i)
                ret.insert(ret.end(),s[i]);
        }
        return ret;
    }
};

int main() {
    Solution solu;
    string s;
    cin>>s;
    cout<<solu.shortestPalindrome(s)<<endl;
    return 0;
}
