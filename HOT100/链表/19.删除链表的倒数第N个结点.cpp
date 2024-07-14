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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};






class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *slow_pre = new ListNode();
        ListNode *slow = head;
        slow_pre->next = head;
        ListNode *fast = head;

        ListNode *pre = slow_pre;
        while(n > 0)
        {
            fast = fast->next;
            n--;
        }
        while(fast)
        {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next;
        }

        pre->next = slow->next;
        return slow_pre->next;
    }
};



















