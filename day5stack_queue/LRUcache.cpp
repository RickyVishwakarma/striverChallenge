#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity_;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        capacity_ = capacity;
        mpp.clear();

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* currAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currAfterHead;
        currAfterHead->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {

        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
    
            if (mpp.size() == capacity_) {
                Node* lru = tail->prev;
                mpp.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);              
    cout << obj->get(2) << endl; 
    obj->put(4, 4);              
    cout << obj->get(1) << endl; 
    cout << obj->get(3) << endl; 
    cout << obj->get(4) << endl; 
        delete obj;



    return 0;
}