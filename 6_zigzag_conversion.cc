/*
@yang 2015/3/3

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;

class Solution {
	public:
	string convert(string s, int nRows) {
		string sa[nRows];
		int i, temp;
		
		if(nRows == 1)
			return s;

		for(i=0; i<s.size(); ++i) {
			if(i%(2*nRows-2) >= nRows) {
				temp = 2*nRows-2-(i%(2*nRows-2));
				sa[temp].insert(sa[temp].end(), s[i]);
			}
			else {
				temp = i%(2*nRows-2);
				sa[temp].insert(sa[temp].end(), s[i]);
			}
		}
		
		for(i=1; i<nRows; ++i) {
			sa[0].append(sa[i]);
		}
		return sa[0];
	}
};

int main() {
	string s("PAYPALISHIRING");
	string result;
	Solution solu;

	result = solu.convert(s,3);
	cout<<"result: "<<result<<endl;
	return 0;
}
