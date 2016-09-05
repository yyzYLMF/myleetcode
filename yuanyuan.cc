#include <iostream>
#include <cstdlib>
#include <math>
using namespace std;

int main() {
	int n,m,max,day,value,lastd,lastv;
	while(cin>>n>>m) {
		for(int i=0;i<m;++i) {
			cin>>day>>value;
			if(i==0) {
				lastd=day;
				lastv=value;
				max = day-1+value;
			}
			int tmp = abs(value-lastv)+(day-lastd)/2;
			if(tmp>max)
				max = tmp;
			lastd = day;
			lastv = value;
		} 
		int tmp = lastv + (n-lastd);
		if(tmp > max) {
			max = tmp;
		}
		cout<<max<<endl;
	}
}
