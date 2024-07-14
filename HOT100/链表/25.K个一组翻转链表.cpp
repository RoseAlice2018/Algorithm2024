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
    pair<ListNode*, ListNode*> helper_reverse(ListNode *head, ListNode *tail)
    {
        if(head == tail) return {head, head};
        // reverse from head -> tail
        pair<ListNode*, ListNode*> newList = helper_reverse(head->next, tail);
        newList.second->next = head;
        head->next = nullptr;
        return {newList.first, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(k > 0)
        {
            k--;
            if(k > 0 && fast != nullptr)
            {
                fast = fast->next;
            }
            else if( k == 0 && fast != nullptr)
            {
                // find tail
                break;
            }
            else if(fast == nullptr)
            {
                // 不足k个 不需要翻转
                return head;
            }
        }
        ListNode *nextList = reverseKGroup(fast->next, k);
        pair<ListNode*, ListNode*> preList = helper_reverse(head, fast);
        preList.second->next = nextList;
        return preList.first;
    }
};

class Solution {
public:
    pair<ListNode*, ListNode*> helper_reverse(ListNode *head, ListNode *tail)
    {
        if(head == tail) return {head, head};
        // reverse from head -> tail
        pair<ListNode*, ListNode*> newList = helper_reverse(head->next, tail);
        newList.second->next = head;
        head->next = nullptr;
        return {newList.first, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1) return head;
        int k_save = k;
        ListNode *fast = head;
        while(k > 0)
        {
            k--;
            if(k > 0 && fast != nullptr)
            {
                fast = fast->next;
            }
            else if( k == 0 && fast != nullptr)
            {
                // find tail
                break;
            }
            else if(fast == nullptr)
            {
                // 不足k个 不需要翻转
                return head;
            }
        }
        ListNode *nextList = reverseKGroup(fast->next, k_save);
        pair<ListNode*, ListNode*> preList = helper_reverse(head, fast);
        preList.second->next = nextList;
        return preList.first;
    }
};