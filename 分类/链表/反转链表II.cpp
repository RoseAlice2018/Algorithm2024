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
//迭代

class Solution {
public:
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


// 递归写法

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

    ListNode * suffix;
    ListNode* reverseN(ListNode *head, int n)
    {
        if(n == 1)
        {
            suffix = head->next;
            return head;
        }

        ListNode *_next = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = suffix;

        return _next;
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == 1)
        {
            return reverseN(head, right);
        }

        ListNode *reverse_tree =  reverseBetween(head->next, left - 1, right - 1);
        head->next = reverse_tree;

        return head;
    }
};