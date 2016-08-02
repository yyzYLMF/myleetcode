#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

int store[80][80];
int ret,n,m;

int mydeal(int n1,int n2,int n3,int m1, int m2, int m3) {
	int ret=INT_MAX,i,j;
	for(j=0;j<m;++j) {
		for(i=n1-1;i>0;--i) {
			store[i-1][j] += store[i][j];
			store[i][j] = 0;
		}
		for(i=n2-1;i>n1;--i) {
			store[i-1][j] += store[i][j];
			store[i][j] = 0;
		}
		for(i=n3-1;i>n2;--i) {
			store[i-1][j] += store[i][j];
			store[i][j] = 0;
		}
		for(i=n-1;i>n3;--i) {
			store[i-1][j] += store[i][j];
			store[i][j] = 0;
		}
	}
	for(j=m1-1;j>0;--j) {
		store[0][j-1] = store[0][j];
		store[0][j] = 0;
		store[n1][j-1] = store[n1][j];
		store[n1][j] = 0;
		store[n2][j-1] = store[n2][j];
		store[n2][j] = 0;
		store[n3][j-1] = store[n3][j];
		store[n3][j] = 0;
	}
	for(i=0;i<n;++i) {
		for(j=0;j<m;++j) {
			if(store[i][j] == 0)
				continue;
			else {
				if(ret > store[i][j])
					ret = store[i][j];
			}
		}
	}
	return ret;
}

int main() {
	int i,j,temp;
	
	while(cin>>n) {
		cin>>m;
		ret = 10;
		for(i=0;i<n;++i) {
			for(j=0;j<m;++j) {
				cin>>temp;
				store[i][j] = temp;
				if(temp < ret)
					ret = temp;
			}
		}
		for(int n1=0;n1<n-3;++n1) {
			for(int n2=n1+1;n2<n-2;++n2) {
				for(int n3=n2+1;n3<n-1;++n3) {
					for(int m1=0;m1<m-3;++m1) {
						for(int m2=m1+1;m2<m-2;++m2) {
							for(int m3=m2+1;m3<m-1;++m3) {
								temp = mydeal(n1,n2,n3,m1,m2,m3);
								if(temp > ret)
									ret = temp;
							}
						}
					}
				}
			}
		}
		cout<<ret<<endl;
	}
}
