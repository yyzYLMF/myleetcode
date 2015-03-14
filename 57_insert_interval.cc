/*
 * @yang 2015/3/14
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
		vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
			vector<Interval> result;
			int i;
			
			if(intervals.empty()) {
				result.push_back(newInterval);
				return result;
			}
			i=0;
			while(i<intervals.size()) {
				if(intervals[i].end < newInterval.start) {
					result.push_back(intervals[i]);
					i++;
				}
				else {
					if(intervals[i].start > newInterval.end) {
						result.push_back(newInterval);
						break;
					}
					if(intervals[i].end >= newInterval.end) {
						intervals[i].start = min(intervals[i].start, newInterval.start);
						break;
					}
					newInterval.start = min(intervals[i].start, newInterval.start);
					i++;
				}
			}
			if(i==intervals.size())
				result.push_back(newInterval);
			else
				for(;i<intervals.size(); ++i)
					result.push_back(intervals[i]);
			return result;
		}
};

int main() {
	Interval a1(1,2);
	Interval a2(3,5);
	Interval a3(6,7);
	Interval a4(8,10);
	Interval a5(12,16);
	Interval newone(2,3);
	Solution solu;
	vector<Interval> input;
	vector<Interval> result;

	input.push_back(a1);
	input.push_back(a2);
	input.push_back(a3);
	input.push_back(a4);
	input.push_back(a5);
	result = solu.insert(input, newone);
	for(int i=0; i<result.size(); ++i) {
		cout<<result[i].start<<" "<<result[i].end<<endl;
	}
	return 0;
}
