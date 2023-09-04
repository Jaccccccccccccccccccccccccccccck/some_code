/*
实现一个简单的hashmap
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashMap {
private:
    int capacity;
    vector<vector<pair<int,int>>> table;
public:
    HashMap(int c) {
        capacity = c;
        table.resize(c);
    }
    int hash(int k) {
        return k % capacity;
    }
    void set(int k, int v) {
        int index = hash(k);
        bool found = false;
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(it->first == k) {
                it->second = v;
                found = true;
                break;
            }
        }
        if(!found) {
            table[index].push_back({k, v});
        }
    }

    int get(int k) {
        int index = hash(k);
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(it->first == k) {
                return it->second;
            }
        }
        return -1;
    }

    void remove(int k) {
        int index = hash(k);
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(it->first == k) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    HashMap map(10);

    map.set(1, 10);
    map.set(2, 20);
    map.set(11, 30);

    std::cout << "Value for key 1: " << map.get(1) << std::endl;
    std::cout << "Value for key 2: " << map.get(2) << std::endl;
    std::cout << "Value for key 11: " << map.get(11) << std::endl;

    map.remove(2);

    std::cout << "Value for key 2 after removal: " << map.get(2) << std::endl;

    map.set(1, 11);
    std::cout << "Value for key 1 after update: " << map.get(1) << std::endl;

    return 0;
}
