/*
 * @yang 2015/3/17
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution {
	public:
	string simplifyPath(string path) {
		stack<string> ss;
		string temp="";
		string result="";
		int i;

		for(i=0; i<path.size(); ++i) {
			if(path[i]=='/') {
				if(temp.empty())
					temp.insert(temp.end(),'/');
				else if(temp.size()==1)
					continue;
				else {
					if(temp == string("/..")) {
						if(!ss.empty())
							ss.pop();
						temp="/";
					}
					else if(temp == string("/.")) {
						temp="/";
						continue;
					}
					else {
						ss.push(temp);
						temp="/";
					}
				}
			}
			else {
				temp.insert(temp.end(),path[i]);
			}
		}
		if(temp.size()>1) {
			if(temp == string("/..")) {
				if(!ss.empty())
					ss.pop();
			}
			else if(temp != string("/."))
				ss.push(temp);
		}
		if(ss.empty())
			return "/";
		else {
			while(!ss.empty()) {
				result = ss.top() + result;
				ss.pop();
			}
			return result;
		}
	}
};

int main() {
	string s;
	Solution solu;

	while(cin>>s) {
		cout<<solu.simplifyPath(s)<<endl;
	}
	return 0;
}
