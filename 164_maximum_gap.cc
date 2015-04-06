/*
 * @yang 2015/4/5
 *
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <climits>
using namespace std;

//with map
class Solution {
    public:
    int maximumGap(vector<int> &num) {
        map<int,int> store;
        map<int,int>::iterator pos;
        int gap,temp;
        if(num.size()<2)
            return 0;
        for(int i=0;i<num.size();++i)
            store[num[i]]++;
        pos = store.begin();
        gap = 0;
        while(pos!=store.end()) {
            temp = pos->first;
            pos++;
            if(pos == store.end())
                break;
            if(pos->first-temp > gap)
                gap = pos->first - temp;
        }
        return gap;
    }
};

//without map
class Solution2 {
    public:
    class Node {
        public:
        int val;
        Node *next;
        Node(int x): val(x),next(NULL) {}
    };
    void pushBucket(vector<Node*> &bucket,int n, int val) {
        Node *temp, *last;
        temp = bucket[n];
        if(temp == NULL) {
           bucket[n] = new Node(val);
        }
        else {
            last = NULL;
            while(temp && temp->val < val) {
                last = temp;
                temp = temp->next;
            }
            Node *newOne = new Node(val);
            if(last==NULL) {
                newOne->next = bucket[n];
                bucket[n] = newOne;
            }
            else {
                newOne->next = temp;
                last->next = newOne;
            }
        }
        return;
    }
    int maximumGap(vector<int> &num) {
        vector<Node*> bucket;
        Node* temp=NULL;
        int i,len=num.size(),pos,lastone=-1,gapmax;
        int minval=INT_MAX,maxval=-1;
        if(len<2)
            return 0;
        for(i=0;i<len;++i)
            bucket.push_back(temp);
        for(i=0;i<len;++i) {
            if(num[i] > maxval) 
                maxval = num[i];
            if(num[i] < minval)
                minval = num[i];
        }
        for(i=0;i<len;++i) {
            pos=(int)(((num[i]-minval)*1.0/(maxval-minval))*(len-1));
            pushBucket(bucket,pos,num[i]);
        }
        gapmax = 0;
        for(i=0;i<len;++i) {
            temp = bucket[i];
            while(temp!=NULL) {
                if(lastone==-1)
                    lastone = temp->val;
                else {
                    if(temp->val - lastone > gapmax)
                        gapmax = temp->val - lastone;
                    lastone = temp->val;
                }
                temp = temp->next;
            }
        }
        return gapmax;
    }
};

int main() {
    Solution2 solu;
    return 0;
}
