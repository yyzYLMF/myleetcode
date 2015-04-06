/*
 * @yang 2015/4/6
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
    public:
    int toNum(string s, int m, int n) {
        int sum=0;
        for(int i=m;i<n;++i) {
            sum=sum*10+s[i]-'0';
        }
        return sum;
    }

    int compareVersion(string version1, string version2) {
        int start1,start2,end1,end2,val1,val2;
        if(version1.size()==0 || version2.size()==0)
            return 0;
        start1=0;
        start2=0;
        end1=0;
        end2=0;
        while(end1<version1.size() && end2<version2.size()) {
            while(version1[end1] != '.' && end1<version1.size())
                end1++;
            while(version2[end2] != '.' && end2<version2.size())
                end2++;
            val1 = toNum(version1,start1,end1);
            val2 = toNum(version2,start2,end2);
            if(val1>val2)
                return 1;
            else if (val1<val2)
                return -1;
            start1 = end1+1;
            end1 = start1;
            start2 = end2+1;
            end2 = start2;
        }
        if(end1 >= version1.size() && end2<version2.size()) {
            while(end2<version2.size()) {
                while(version2[end2] != '.' && end2<version2.size())
                    end2++;
                val2 = toNum(version2,start2,end2);
                if(val2 != 0)
                    return -1;
                start2 = end2+1;
                end2 = start2;
            }
            return 0;
        }
        else if(end1<version1.size() && end2 >= version2.size()) {
            while(end1 < version1.size()) {
                while(version1[end1] != '.' && end1<version1.size())
                    end1++;
                val1 = toNum(version1,start1,end1);
                if(val1 != 0)
                    return 1;
                start1 = end1+1;
                end1 = start1;
            }
            return 0;
        }
        else if(end1 >= version1.size() && end2 >= version2.size())
            return 0;
    }
};

int main() {
    Solution solu;
    return 0;
}
