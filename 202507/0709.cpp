#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// struct DListNode{
//     int val;
//     DListNode *next;
//     DListNode() : val(0), next(nullptr) {}
//     DListNode(int x):val(x), next(nullptr) {}
//     DListNode(int x, DListNode *next):val(x), next(next){}
// };

struct DListNode{
    int key;
    int value;
    DListNode *left;
    DListNode *right;
    DListNode():key(0), value(0), left(nullptr), right(nullptr){}
    DListNode(int key, int value):key(key), value(value), left(nullptr), right(nullptr){}
    DListNode(int key, int value, DListNode *left, DListNode *right):key(key), value(value), left(left), right(right){}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        DListNode* realhead = new DListNode(0, 0);
        _head = realhead;
        DListNode* realtail = new DListNode(0, 0);
        _tail = realtail;
        realhead->right = realtail;
    }
    
    void addNodeToHead(DListNode* node)
    {
        DListNode* next_head = _head->right;
        _head->right = node;
        node->left = _head;
        node->right = next_head;
        next_head->left = node;   
    }

    void removeNode(DListNode* node)
    { 
        DListNode* pre = node->left;
        DListNode* next = node->right;
        pre->right = next;
        next->left = pre;
    }

    int get(int key) {
        if(_map.find(key) == _map.end())
        {
            return -1;
        }
        DListNode* node = _map[key];
        removeNode(node);
        addNodeToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(_map.find(key) != _map.end())
        {
            DListNode* node = _map[key];
            node->value = value;
            removeNode(node);
            addNodeToHead(node);
        }
        else
        {
            if(_map.size() == _capacity)
            {
                DListNode* beforetail = _tail->left;
                _map.erase(beforetail->key);
                removeNode(beforetail);
                delete beforetail;
            }
            DListNode* node = new DListNode(key, value);
            addNodeToHead(node);
            _map[key] = node;
        }
    }
private:
    int _capacity = 0;
    unordered_map<int, DListNode*> _map;
    DListNode* _head = nullptr;
    DListNode* _tail = nullptr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */