#include <unordered_map>
#include <iostream>

class LRUCache {
public:
    // need to implement a double linked list to satisfy time requirement
    // because we need to move a node from middle to front
    struct ListNode {
        int key, value;
        ListNode *prev, *next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
        ListNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    };

    int cap = 0;
    int size = 0;
    ListNode *dummyhead = nullptr;
    ListNode *dummytail = nullptr;
    std::unordered_map<int, ListNode*> keymap;

    LRUCache(int capacity) : cap(capacity) {
        dummyhead = new ListNode();
        dummytail = new ListNode();
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
        // dummyhead -> dummytail
    }
    
    // use the map to get value in O(1)
    int get(int key) {
        // when a key does not exist
        if(keymap.find(key) == keymap.end())
            return -1;

        // if exists, update list first
        // since this key is used, move to front of list
        if(keymap[key] != dummyhead->next) {
            keymap[key]->prev->next = keymap[key]->next;
            keymap[key]->next->prev = keymap[key]->prev;

            ListNode *tempheadnext = dummyhead->next;
            dummyhead->next = keymap[key];
            keymap[key]->prev = dummyhead;
            keymap[key]->next = tempheadnext;
            tempheadnext->prev = keymap[key];
        } // else meaning already at front of list. no change
        // then return value
        return keymap[key]->value;
    }
    
    // if exceeds cap, remove tail node
    void put(int key, int value) {
        if(keymap.find(key) != keymap.end()) {
            // key exists. delete it for now. Will be inserted to front
            keymap[key]->prev->next = keymap[key]->next;
            keymap[key]->next->prev = keymap[key]->prev;
            keymap.erase(key);
            size--;
        } else if(size == cap) {
            // can holds no more items, remove tail from list
            keymap.erase(dummytail->prev->key);

            ListNode *temptailprev = dummytail->prev;
            if(temptailprev != dummyhead) {
                temptailprev->prev->next = dummytail;
                dummytail->prev = temptailprev->prev;
                size--;
            } // else meaning empty list
        }
        // append the new node to front of list
        ListNode *tempheadnext = dummyhead->next;
        dummyhead->next = new ListNode(key, value);
        dummyhead->next->prev = dummyhead;
        dummyhead->next->next = tempheadnext;
        tempheadnext->prev = dummyhead->next;

        keymap[key] = dummyhead->next;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LRUCache* obj = new LRUCache(2);

    obj->put(1,1);
    obj->put(2,2);
    std::cout << obj->get(1) << std::endl;
    obj->put(3,3);
    std::cout << obj->get(2) << std::endl;
    obj->put(4,4);
    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(3) << std::endl;
    std::cout << obj->get(4) << std::endl;
}
