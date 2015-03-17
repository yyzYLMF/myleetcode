/*
 * @yang 2015/3/17
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
	public:
	string addBinary(string a, string b) {
		int c=0,i,j,temp;
		string result(a);

		if(a.size() < b.size())
			return addBinary(b,a);
		i=a.size()-1;
		j=b.size()-1;
		for(;i>=0 && j>=0; --i,--j) {
			temp=a[i]-'0'+b[j]-'0'+c;
			result[i]=temp%2+'0';
			c=temp/2;
		}
		if(c!=0) {
			while(i>=0) {
				temp = a[i]-'0'+c;
				result[i]=temp%2+'0';
				c=temp/2;
				if(c==0)
					break;
				i--;
			}
		}
		if(c!=0)
			result.insert(result.begin(),1+'0');
		return result;
	}
};

int main() {
	string s1,s2;
	Solution solu;
	while(cin>>s1>>s2) {
		cout<<solu.addBinary(s1,s2)<<endl;
	}
	return 0;
}
