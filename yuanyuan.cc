#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int input,low,high,mid,limit;
    string str = "";
    cin>>input;
    low = -90;
    high = 90;
    limit = 6;
    for(int i=0;i<limit;++i) {
        mid = (low+high)/2;
        if(input >= mid) {
            str.insert(str.end(),'1');
            low = mid;
        } else {
            str.insert(str.end(),'0');
            high = mid;
        }
    }
    cout<<str<<endl;
    return 0;
}
