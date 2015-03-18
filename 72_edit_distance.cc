/*
 * @yang 2015/3/18
 *
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
	public:
	int minDistance(string word1, string word2) {
		int **dis;
		int m,n,i,j;
		
		m=word1.size();
		n=word2.size();
		if(m==0)
			return n;
		else if(n==0)
			return m;

		dis = new int*[m+1];
		for(i=0; i<=m; ++i)
			dis[i] = new int[n+1];
		for(i=0; i<=m; ++i)
			dis[i][0] = i;
		for(j=0; j<=n; ++j)
			dis[0][j] = j;
		for(i=1;i<=m;++i) {
			for(j=1;j<=n;++j) {
				if(word1[i-1] == word2[j-1])
					dis[i][j] = dis[i-1][j-1];
				else {
					dis[i][j] = min(dis[i-1][j],dis[i][j-1])+1;
					if(dis[i-1][j-1]+1 < dis[i][j])
						dis[i][j] = dis[i-1][j-1]+1;
				}
			}
		}
		return dis[m][n];
	}
};

int main() {
	string s1,s2;
	Solution solu;

	while(cin>>s1>>s2) {
		cout<<solu.minDistance(s1,s2)<<endl;
	}
	return 0;
}
