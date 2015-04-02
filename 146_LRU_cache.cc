/*
 * @yang 2015/4/2
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */
#include <iostream>
#include <cstdlib>
#include <list>
#include <utility>
#include <map>
using namespace std;

class LRUCache {
    public:
    typedef list<pair<int,int> >::iterator index;
    LRUCache(int capacity) {
        cache.clear();
        cmap.clear();
        cap = capacity;
    }

    int get(int key) {
        index pos;
        int temp;
        map<int,index>::iterator map_pos;
        map_pos = cmap.find(key);
        if(map_pos == cmap.end())
            return -1;
        else {
            pos = map_pos->second;
            temp = pos->second;
            cache.erase(pos);
            cmap[key] = cache.insert(cache.end(),make_pair(key,temp));
            return temp;
        }
    }

    void set(int key, int value) {
        map<int,index>::iterator map_pos;
        index pos;
        int temp;
        map_pos = cmap.find(key);
        if(map_pos != cmap.end()) {
            pos = map_pos->second;
            cache.erase(pos);
            cmap[key] = cache.insert(cache.end(),make_pair(key,value));
        }
        else {
            if(cache.size() >= cap) {
                temp = cache.front().first;
                cache.pop_front();
                cmap.erase(temp);
                cmap[key] = cache.insert(cache.end(),make_pair(key,value));
            }
            else 
                cmap[key] = cache.insert(cache.end(),make_pair(key,value)); 
        }
        return;
    }

    private:
    int cap;
    list<pair<int,int> > cache;
    map<int,index> cmap;
};

int main() {
    LRUCache c(10);
    return 0;
}
