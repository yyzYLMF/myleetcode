/*
 * @yang 2015/4/4
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>
using namespace std;

//This method is not the best
class Solution {
    public:
    void push(int x) {
        vstack.push_back(x);
        smap[x]++;
        return;
    }

    void pop() {
        int len=vstack.size(),temp;
        if(len > 0) {
            temp = vstack[len-1];
            vstack.pop_back();
            if(smap[temp] <= 1)
                smap.erase(temp);
            else
                smap[temp]--;
        }
        else
            exit(0);
    }

    int top() {
        int len=vstack.size();
        if(len > 0)
            return vstack[len-1];
        else
            exit(0);
    }

    int getMin() {
        map<int,int>::iterator pos=smap.begin();
        if(pos!=smap.end())
            return pos->first;
        else
            exit(0);
    }
    private:
    vector<int> vstack;
    map<int,int> smap;
};

//This method is better
class Solution2 {
    public:
    void push(int x) {
        st.push(x);
        if (stm.empty() || stm.top() >= x) stm.push(x);
    }

    void pop() {
        int top = st.top(); st.pop();
        if (top <= stm.top()) stm.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return stm.top();
    }
    private:
    stack<int> st;
    stack<int> stm;
};


int main() {
    Solution solu;
    return 0;
}
