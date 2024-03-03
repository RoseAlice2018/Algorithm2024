#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):val(x), next(next){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};


class MyStack {
public:
    queue<int> _queue;
    MyStack() {
    
    }
    
    void push(int x) {
        int size = _queue.size();
        _queue.push(x);
        for(int i = 0; i < size; i++)
        {
            int first = _queue.front();
            _queue.pop();
            _queue.push(first);
        }
    }
    
    int pop() {
        int first = _queue.front();
        _queue.pop();
        return first;
    }
    
    int top() {
        return _queue.front();
    }
    
    bool empty() {
        return _queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */