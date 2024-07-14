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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(true)
        {
            if(fast == nullptr || fast->next == nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }    
        while(slow != head)
        {
            head = head->next;
            slow = slow->next;
        }
        return slow;
    }
};














class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode *slow = head; 
        ListNode *fast = head;
        while(fast != nullptr || fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(fast == nullptr || fast->next == nullptr) return nullptr;
        ListNode *t = head;
        while(t != slow)
        {
            t = t->next;
            slow = slow->next;
        }
        return t;
    }
};




















