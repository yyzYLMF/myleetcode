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

// BEST method
class Solution {
    public:
    class Node {
        public:
        int min;
        int max;
        bool sign;
        Node():min(INT_MAX),max(INT_MIN),sign(false){}
    };
    int maximumGap(vector<int> &num) {
        int all_min,all_max;
        Node *tmp;
        int i,ret;
        double dis;
        if(num.size() <= 1)
            return 0;
        all_min = num[0];
        all_max = num[0];
        for(i=1;i<num.size();++i) {
            if(num[i] < all_min)
                all_min = num[i];
            else if(num[i] > all_max)
                all_max = num[i];
        }
        dis = (all_max - all_min)*1.0/((double)num.size());
        tmp = new Node[num.size()+1];
        for(i=0;i<num.size();++i) {
            int pos = (num[i]-all_min)*1.0/dis;
            if(tmp[pos].sign == false) {
                tmp[pos].min = num[i];
                tmp[pos].max = num[i];
                tmp[pos].sign = true;
            }
            else {
                if(num[i] > tmp[pos].max)
                    tmp[pos].max = num[i];
                else if(num[i] < tmp[pos].min)
                    tmp[pos].min = num[i];
            }
        }
        int last = tmp[0].max;
        ret = 0;
        for(i=1;i<=num.size();++i) {
            if(tmp[i].sign == true) {
                ret = max(ret,tmp[i].min - last);
                last = tmp[i].max;
            }
        }
        return ret;
    }
};

//with map, Not best
class Solution3 {
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

//without map Not best
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
    Solution solu;
    vector<int> input;
    input.push_back(1);
    input.push_back(1000000);
    cout<<solu.maximumGap(input)<<endl;
    return 0;
}
