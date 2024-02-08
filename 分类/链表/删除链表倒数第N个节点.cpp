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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dumpy = new ListNode();
        dumpy->next = head;
        ListNode *fast = dumpy;
        ListNode *slow = dumpy;
        
        int idx = 0;
        while(idx < n)
        {
            fast = fast->next;
            idx++;
        }
        
        ListNode *slow_pre = new ListNode();
        slow_pre->next = slow;
        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
            slow_pre =  slow_pre->next;
        }
        //delete slow
        slow_pre->next = slow->next;
        slow = nullptr;
        return dumpy->next;
    }
};