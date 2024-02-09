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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(true)
        {
            if((fast == nullptr) || (fast->next == nullptr))
                return nullptr;
            
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) //meet
                break;
        }

        fast = head;
        while(slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};