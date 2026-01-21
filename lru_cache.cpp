#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;

    // Sentinel nodes
    Node* head; // Most Recently Used side
    Node* tail; // Least Recently Used side

    // Remove node from list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node right after head (MRU position)
    void insertToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        Node* node = it->second;
        remove(node);
        insertToFront(node);
        return node->value;
    }

    void set(int key, int value) {
        auto it = cache.find(key);

        // Key already exists
        if (it != cache.end()) {
            Node* node = it->second;
            node->value = value;
            remove(node);
            insertToFront(node);
            return;
        }

        // Capacity full → evict LRU
        if ((int)cache.size() == capacity) {
            Node* lru = tail->prev;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }

        Node* node = new Node(key, value);
        insertToFront(node);
        cache[key] = node;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

// -------- Driver --------
int main() {
    LRUCache cache(2);

    cache.set(1, 10);
    cache.set(2, 20);
    cout << cache.get(1) << endl; // 10

    cache.set(3, 30);             // evicts key 2
    cout << cache.get(2) << endl; // -1

    cache.set(1, 40);             // overwrite
    cout << cache.get(1) << endl; // 40

    return 0;
}
