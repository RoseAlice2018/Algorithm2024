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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail)
    {
        pair<ListNode*, ListNode*> ret;
        ListNode *cur = head;
        ListNode * prev = nullptr;
        while(cur != tail)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur  = next;
        }
        ret.first = tail;
        ret.second = head;
        return ret;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( left == right)
            return head;
        
        // find left && right
        ListNode *node_left;
        ListNode *node_right;
        ListNode *pre_left = new ListNode();
        pre_left->next = head;
        ListNode *cur = pre_left;
        int cnt = 1;
        while(cnt < left )
        {
            cur = cur->next;
            cnt++;
        }
        // find left 
        node_left = cur->next;
        pre_left  = cur;

        while(cnt < right)
        {
            cur = cur->next;
            cnt++;
        }
        node_right = cur;
        ListNode *after_right = cur->next;

        pair<ListNode*, ListNode*> ret = reverse(node_left, node_right);

        pre_left->next = ret.first;
        ret.second->next = after_right;

        
    }
};