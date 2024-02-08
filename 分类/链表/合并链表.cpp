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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *cur  = head;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            }
            else if(list1->val > list2->val)
            {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }

        while(list2 != nullptr)
        {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }

        while(list1 != nullptr)
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }

        return head->next;
    }
};

// 递归解法

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        
        if(list2 == nullptr)
            return list1;
        
        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        else 
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
        return list1;
    }
};