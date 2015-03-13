/*
@yang 2015/3/13

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
	public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
	static bool cmp(const Interval &a, const Interval &b) {
		return a.start < b.start;
	}

	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> copy(intervals);
		vector<Interval> result;
		Interval temp;
		
		if(intervals.size() <= 1)
			return intervals;
		sort(copy.begin(), copy.end(), cmp);
		temp = copy[0];
		for(int i=1; i<copy.size(); ++i) {
			if(temp.end >= copy[i].start) {
				if(temp.end < copy[i].end)
					temp.end = copy[i].end;
			}
			else {
				result.push_back(temp);
				temp = copy[i];
			}
		}
		result.push_back(temp);
		return result;
	}
};

int main() {
	Interval a(1,3),b(2,6),c(8,10),d(15,18);
	vector<Interval> input;
	vector<Interval> result;
	Solution solu;

	input.push_back(a);
	input.push_back(b);
	input.push_back(c);
	input.push_back(d);

	result = solu.merge(input);
	for(int i=0; i<result.size(); ++i) {
		cout<<result[i].start<<" "<<result[i].end<<endl;
	}
	return 0;
}
