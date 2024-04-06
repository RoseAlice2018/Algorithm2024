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