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
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
            if (vals[i] != vals[j]) {
                return false;
            }
        }
        return true;
    }
};




class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head || !head->next) return head;
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        if(!head->next) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *compare;
        if(fast == nullptr) compare = reverseList(slow);
        else compare = reverseList(slow->next);

        while(head && compare)
        {
            if(head->val != compare->val)
                return false;
            head = head->next;
            compare = compare->next;
        }
        return true;
    }
};