/*
@yang 2015/3/2

Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

//This solution is Time limit exceeded
class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			vector<int> result;
			vector<int>::size_type i,j;
			int temp, index1, index2;

			for(i=0,index1=1; i<numbers.size(); ++i,++index1) {
				temp = target - numbers[i];
				vector<int>::const_iterator fresult = find(numbers.begin()+index1, numbers.end(), temp);
				if(fresult != numbers.end()) {
					for(j=i+1,index2=index1+1; j<numbers.size(); ++j,++index2) {
						if(numbers[j] == temp)
							break;
					}
					result.push_back(index1);
					result.push_back(index2);
					return result;
				}
			}
			cout<<"oops not find"<<endl;
			return result;
		}
};

//Accepted
class Solution2 {
	public:
	
	class mynode {
		public:
		int value;
		int pos;
	};

	static bool cmp(const mynode &n1, const mynode &n2) {
		return n1.value < n2.value;
	}

	vector<int> twoSum(vector<int> &numbers, int target) {

		mynode node;
		vector<mynode> copy;
		vector<int> result;
		vector<int>::size_type i;
		int temp_sum;

		for(i=0; i<numbers.size(); ++i) {
			node.pos = i+1;
			node.value = numbers[i];
			copy.push_back(node);
		}
		sort(copy.begin(), copy.end(), cmp);
		vector<mynode>::iterator head,tail;
		head = copy.begin();
		tail = copy.end() - 1;
		while(head < tail) {
			temp_sum = head->value + tail->value;
			if(temp_sum == target)
				break;
			else if(temp_sum < target)
				head++;
			else if(temp_sum > target)
				tail--;
		}
		if(head < tail) {
			if(head->pos < tail->pos) {
				result.push_back(head->pos);
				result.push_back(tail->pos);
			}
			else if(head->pos > tail->pos) {
				result.push_back(tail->pos);
				result.push_back(head->pos);
			}
		}
		return result;
	}
	
	
};


int main()
{
	vector<int> input,result;
	//Solution solu;
	Solution2 solu;
	int target=9;

	input.push_back(2);
	input.push_back(7);
	input.push_back(11);
	input.push_back(15);

	result=solu.twoSum(input,target);
	cout<<"result: "<<result[0]<<" "<<result[1]<<endl;
	return 0;
}
