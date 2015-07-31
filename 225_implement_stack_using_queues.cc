/*
 * @yang 2015/7/31 
 */

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

class Stack {
    public:
    void push(int x) {
        if(qint1.empty()) {
            qint2.push(x);
        }
        else {
            qint1.push(x);
        }
    }
    void pop() {
       int last;
       if(!qint1.empty()) {
           while(!qint1.empty()) {
               last = qint1.front();
               qint1.pop();
               if(!qint1.empty()) {
                   qint2.push(last);
               }
           }
       }
       else {
           while(!qint2.empty()) {
               last = qint2.front();
               qint2.pop();
               if(!qint2.empty()) {
                   qint1.push(last);
               }
           }
       }
       return;
    }
    int top() {
        int last;
        if(!qint1.empty()) {
            while(!qint1.empty()) {
                last = qint1.front();
                qint1.pop();
                qint2.push(last);
            }
            return last;
        }
        else {
            while(!qint2.empty()) {
                last = qint2.front();
                qint2.pop();
                qint1.push(last);
            }
            return last;
        }        
    }
    bool empty() {
        if(qint1.empty() && qint2.empty())
            return true;
        else
            return false;
    }
    private:
    queue<int> qint1;
    queue<int> qint2;
};

int main() {
    Stack mys;
    return 0;
}
