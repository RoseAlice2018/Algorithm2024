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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if((headA == nullptr)||(headB == nullptr))
            return nullptr;
        ListNode *beginA = headA;
        ListNode *beginB = headB;

        while(beginA != beginB)
        {
            if(beginA == nullptr )
            {
                beginA = headB;
            }
            else 
                beginA = beginA->next;

            if(beginB == nullptr )
            {
                beginB = headA;
            }
            else 
                beginB = beginB->next;
        }

        return beginA;
    }
};