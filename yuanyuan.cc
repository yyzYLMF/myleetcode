#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int dp[50][50];

bool func(string ss, int s, int e) {
	int i,j;
	if((e-s)%2==0) {
		return false;
	}
	i=s;
	j= ceil(((double)(s+e))/2.0);
	for(;j<=e;++i,++j) {
		if(ss[i] != ss[j]) {
			break;
		}
	}
	if(j<=e)
		return false;
	else 
		return true;
}

int main() {
	int i,j;
	string ss;
	set<string> mset;
	cin>>ss;
	if(ss.size() <= 1) {
		cout<<0<<endl;
		return 0;
	}
	for(i=0;i<50;++i) {
		for(j=0;j<50;++j) {
			dp[i][j] = 0;
		}
	}
	int ret = 0;
	for(i=0;i<ss.size();++i) {
		for(j=i+1;j<ss.size();++j) {
			
			if(i!=0 && dp[i-1][j]==1) {
				continue;
			}
			if(dp[i][j-1]==1) {
				continue;
			}
			//cout<<i<<" "<<j<<endl;
			if(func(ss,i,j)) {
				//cout<<i<<" true "<<j<<endl;
				dp[i][j] = 1;
				string tmp =ss.substr(i,j-i+1);
				if(mset.count(tmp) == 0) {
					ret++;
					mset.insert(tmp);
				}
			}
		}
	}
	cout<<ret<<endl;
	return 0;
}
