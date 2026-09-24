#include <unordered_map>

using namespace std;


class LRUCache {
private:
    class Node {
        public:
            Node* next;
            Node* pre;
            int key;
            int val;
            Node(int k, int v):next(nullptr), pre(nullptr), key(k), val(v) {}
            Node():next(nullptr), pre(nullptr) {}
    };
    unordered_map<int, Node*> cache;
    int size;
    int limit;
    Node* historyHead;
    Node* historyTail;
    void addToHistory(Node* newNode) {
        if (historyHead->next == nullptr) {
            historyHead->next = newNode;
            newNode->pre = historyHead;
            newNode->next = historyTail;
            historyTail->pre = newNode;
        } else {
            Node* preTail = historyTail->pre;
            preTail->next = newNode;
            newNode->pre = preTail;
            newNode->next = historyTail;
            historyTail->pre = newNode;
        }
    }
    void moveToFront(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        addToHistory(node);
    }
    void resize() {
        Node* longestNode = historyHead->next;
        historyHead->next = longestNode->next;
        longestNode->next->pre = historyHead;
        size -= 1;
        cache.erase(longestNode->key);
        delete longestNode;
    }
public:
    LRUCache(int capacity) {
        limit = capacity;
        size = 0;
        historyHead = new Node();
        historyTail = new Node();
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            moveToFront(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            moveToFront(cache[key]);
        } else {
            cache[key] = new Node(key, value);
            addToHistory(cache[key]);
            size += 1;
            if (size > limit) {
                resize();
            }
        }
    }
};