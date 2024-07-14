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
    ListNode * reverse(ListNode *pre, ListNode *cur)
    {
        if(cur == nullptr) return nullptr;
        ListNode *next = cur->next;
        cur->next = pre;
        if(next == nullptr) return cur;
        pre = cur;
        cur = next;
        return reverse(pre, cur);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *dump  = nullptr;
        return reverse(dump, head);
    }
};









class Solution {
public:
    pair<ListNode*, ListNode*> helper(ListNode *head)
    {
        if(head->next == nullptr) return {head, head};
        pair<ListNode*, ListNode*> ret = helper(head->next);
        ret.second->next = head;
        return {ret.first, head};
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        pair<ListNode*, ListNode*> ret = helper(head->next);
        ret.second->next = head;
        return ret.first;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next) return head;
       ListNode *newHead = reverseList(head->next);
       head->next->next = head;
       head->next = nullptr;
       return newHead; 
    }
};












































