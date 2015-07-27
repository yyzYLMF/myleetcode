/*
 * @yang 2015/7/27
 *
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 */
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

class Solution {
    public:
    void push(int x) {
        in.push(x);
    }

    void pop(void) {
        int temp;
        if(out.empty()) {
            while(!in.empty()) {
                temp = in.top();
                in.pop();
                out.push(temp);
            }
            out.pop();
        }
        else {
            out.pop();
        }
    }

    int peek(void) {
        int temp;
        if(out.empty()) {
            while(!in.empty()) {
                temp = in.top();
                in.pop();
                out.push(temp);
            }
            temp = out.top();
        }
        else 
            temp = out.top();
        return temp;
    }

    bool empty(void) {
        if(in.empty() && out.empty())
            return true;
        else 
            return false;
    }
    private:
    stack<int> in;
    stack<int> out;
};

int main() {
    Solution solu;
    return 0;
}
