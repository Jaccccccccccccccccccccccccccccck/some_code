#include<iostream>
#include<unordered_map>

using namespace std;

struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(): key(-1), val(-1), prev(nullptr), next(nullptr) {}
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int size;
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
public:
    LRUCache(int cap) {
        capacity = cap;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(!map.count(key)) {
            return -1;
        }
        Node* node = map[key];
        remove_node(node);
        add_to_head(node);
        return node->val;
    }

    void put(int key, int val) {
        if(map.count(key)) { // 在里面
            Node* node = map[key];
            node->val = val;
            remove_node(node);
            add_to_head(node);
        } else {
            Node* new_node = new Node(key, val);
            map[key] = new_node;
            add_to_head(new_node);
            size++;
            if(size > capacity) {
                Node* removed = tail->prev;
                remove_node(removed);
                map.erase(removed->key);
                delete removed;
                size--;
            }
        }
    }

    void remove_node(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add_to_head(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
};

int main() {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4
    return 0;
}