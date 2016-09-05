#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n,m,tmp,min,max;
	string stmp;
	vector<int> value;
	vector<int> num;
	map<string,int> mt;
	
	while(cin>>n>>m) {
		value.clear();
		num.clear();
		mt.clear();
		for(int i=0;i<n;++i) {
			cin>>tmp;
			value.push_back(tmp);
		}
		for(int i=0;i<m;++i) {
			cin>>stmp;
			mt[stmp]++;
		}
		map<string,int>::iterator it = mt.begin();
		while(it != mt.end()) {
			tmp = it->second;
			num.push_back(tmp);
			++it;
		}
		sort(value.begin(),value.end());
		sort(num.begin(),num.end());
		min = 0;
		max = 0;
		for(int i=num.size()-1,j=0; i>=0; --i,++j) {
			min += num[i]*value[j];
		}
		for(int i=num.size()-1,j=value.size()-1; i>=0; --i,--j) {
			max += num[i]*value[j];
		}
		cout<<min<<" "<<max<<endl;
	}
}
