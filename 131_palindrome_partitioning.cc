/*
 * @yang 2015/3/31
 *
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
    vector<vector<string> > ans;
    vector<string> vt;
    vector<vector<int> > g;
    int len;

    bool judge(string &s, int i, int j) {
        if (i > j)
            return false;
        if (g[i][j] != -1)
            return g[i][j];
        if (i == j)
            return g[i][j] = 1;
        if (s[i] != s[j])
            return g[i][j] = 0;
        else {
            if (i + 1 == j)
                return g[i][j] = 1;
            return g[i][j] = judge(s, i + 1, j - 1);
        }
    }

    void dfs(string &s, int cnt) {
        if (cnt == len) {
            ans.push_back(vt);
            return;
        }
        for (int i = len - 1; i >= cnt; i--) {
            if (judge(s, cnt, i)) {
                vt.push_back(s.substr(cnt, i - cnt + 1));
                dfs(s, i + 1);
                vt.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        ans.clear(), vt.clear(), g.clear();
        len = s.length();
        vector<int> tmp;
        for (int i = 0; i < len; i++)
            tmp.push_back(-1);
        for (int i = 0; i < len; i++)
            g.push_back(tmp);

        dfs(s, 0);
        return ans;
    }
};

int main() {
    Solution solu;
    return 0;
}
