/*
 * @yang 2015/3/19
 *
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
 */
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
	public:
	void myfun(vector<vector<int> > &result, vector<int> temp, int head, int n, int remian) {
		int i;
		if(n-head+1 == remian) {
			for(i=head; i<=n; ++i)
				temp.push_back(i);
			result.push_back(temp);
			return;
		}
		if(remian == 0) {
			result.push_back(temp);
			return;
		}
		for(i=head; i<=n-remian+1; ++i) {
			temp.push_back(i);
			myfun(result,temp,i+1,n,remian-1);
			temp.pop_back();
		}
		return;
	}

	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> temp;
		
		if(n<k || n==0 || k==0)
			return result;
		for(int i=1; i<=n-k+1; ++i) {
			temp.push_back(i);
			myfun(result, temp, i+1, n, k-1);
			temp.pop_back();
		}
		return result;
	}
};

int main() {
	int n,k;
	Solution solu;
	vector<vector<int> > result;

	while(cin>>n>>k) {
		result = solu.combine(n,k);
		for(int i=0; i<result.size(); ++i) {
			for(int j=0; j<result[i].size(); ++j) {
				cout<<result[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
