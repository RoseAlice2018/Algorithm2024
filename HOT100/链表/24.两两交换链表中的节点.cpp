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


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode * next = head->next->next;
        ListNode* first = head;
        ListNode* second = head->next;
        second->next = head;
        first->next = swapPairs(next);
        return second;
    }
};






class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *next = head->next->next;
        //switch 2
        cur->next = pre;
        pre->next = swapPairs(next);
        return cur;
    }
};
