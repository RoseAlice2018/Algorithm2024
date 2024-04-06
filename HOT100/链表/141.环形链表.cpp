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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow != nullptr && fast != nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr) return false;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }
        
        return false;
    }
};