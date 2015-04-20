/*
 * @yang 2015/4/20
 *
 * Design and implement a TwoSum class. It should support the following operations: add and find.
 *
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.
 */
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class TwoSum {
    public:
    void add(int x) {
        store[x]++;
    }
    bool find(int target){
        int temp;
        map<int,int>::iterator start,end;
        start=store.begin();
        end=(store.end()--);
        while(start->first < end->first) {
            temp = start->first+end->first;
            if(temp==target)
                return true;
            else if(temp>target) 
                end--;
            else
                start++;
        }
        temp=start->first*2;
        if(temp==target && start->second>=2) {
            return true;
        }
        return false;
    }
    private:
    map<int,int> store;
}; 

int main() {
    TwoSum store;
    
    store.add(1);
    store.add(2);
    store.add(4);
    store.add(4);
    store.add(-1);
    store.add(5);
    cout<<store.find(10)<<endl;
    return 0;
}
