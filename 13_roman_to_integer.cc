/*
@yang 2015/3/4

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
	int exchange(char c) {
		switch(c){
			case 'I':
			return 1;
			case 'V':
			return 5;
			case 'X':
			return 10;
			case 'L':
			return 50;
			case 'C':
			return 100;
			case 'D':
			return 500;
			case 'M':
			return 1000;
		}
	}

	int romanToInt(string s) {
		vector<int> ivec;
		int result=0;
		int i;
	
		for(i=0; i<s.size(); ++i)
			ivec.push_back(exchange(s[i]));
		ivec.push_back(0);
		for(i=0; i<ivec.size()-1; ++i){
			if(ivec[i] < ivec[i+1])
				result = result - ivec[i];
			else
				result = result + ivec[i];
		}
		return result;
	}
};

int main() {
	string s;
	int result;
	Solution solu;

	while(cin>>s) {
		result = solu.romanToInt(s);
		cout<<result<<endl;
	}
	return 0;
}
