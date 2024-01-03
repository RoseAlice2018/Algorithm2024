#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;
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
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x) , next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode *child = removeNodes(head->next);
        if(child == nullptr)
            return head;
        else 
        {
            if(child->val > head->val)
            {
                return child;
            }
            else 
            {
                head->next = child;
                return head;
            }
        }
        return nullptr;
    }

};