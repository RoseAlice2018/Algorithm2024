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
    ListNode* reverse(ListNode *head, ListNode *tail)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while(cur != tail)
        {
            ListNode *next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *cur = head;
        ListNode *tail = head;

        for(int i = 0; i < k; i++)
        {
            // less than k nodes, don't reverse
            if(tail == nullptr) return head;
            tail = tail->next;
        }

        //reveser K
        ListNode * cur_head = reverse(cur, tail);
        cur->next = reverseKGroup(tail, k);

        return cur_head;
    }
};