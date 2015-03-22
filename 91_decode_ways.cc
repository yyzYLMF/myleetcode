/*
 * @yang 2015/3/22
 *
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

class Solution {
	public:
	int myfun(string s, int *dp, int *possible, int m, int n) {
		int i,sum=0;
		if(m > n)
			return 1;
		if(dp[m] != 0)
			return dp[m];
		if(possible[m]==0)
			return 0;
		else if(possible[m]==-1) {
			for(i=m;i<=n;++i) {
				if(s[i]=='0') {
					if(i-1<m || (s[i-1]!='1' && s[i-1]!='2'))
						break;
				}
			}
			if(i<=n) {
				possible[m] = 0;
				return 0;
			}
			else
				possible[m] = 1;
		}
		for(i=m;i<=n;++i) {
			if(s[i]=='1' && i+1<=n) {
				if(s[i+1]=='0')
					sum+=myfun(s,dp,possible,i+2,n);
				else {
					sum+=myfun(s,dp,possible,i+1,n);
					sum+=myfun(s,dp,possible,i+2,n);
				}
				break;
			}
			else if(s[i]=='2' && i+1<=n && s[i+1]<='6') {
				if(s[i+1]=='0')
					sum+=myfun(s,dp,possible,i+2,n);
				else {
					sum+=myfun(s,dp,possible,i+1,n);
					sum+=myfun(s,dp,possible,i+2,n);
				}
				break;
			}
		}
		if(sum==0)
			dp[m]=1;
		else
			dp[m]=sum;
		return dp[m];
	}
	int numDecodings(string s) {
		int *dp,*possible;
		int len,i;
		if(s.size()==0)
			return 0;
		len=s.size();
		dp=new int[len];
		possible=new int[len];
		memset(dp,0,len*sizeof(int));
		memset(possible,-1,len*sizeof(int));
		for(i=0;i<len;++i) {
			if(s[i]=='0') {
				if(i-1<0 || (s[i-1]!='1' && s[i-1]!='2'))
					break;
			}
		}
		if(i<len)
			return 0;
		return myfun(s,dp,possible,0,len-1);
	}
};

int main() {
	Solution solu;
	string s;
	while(cin>>s)
		cout<<solu.numDecodings(s)<<endl;
	return 0;
}
