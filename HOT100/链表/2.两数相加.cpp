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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode();
        ListNode *cur = head;

        while(l1 != nullptr && l2 != nullptr)
        {
            ListNode *tmp = new ListNode();
            int sum = l1->val + l2->val + carry;
            if(sum >= 10)
            {
                carry = 1;
                sum = sum - 10;
            }
            else 
                carry = 0;

            tmp->val = sum;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            ListNode *tmp = new ListNode();
            int sum = l1->val + carry;
            if(sum >= 10)
            {
                carry = 1;
                sum = sum - 10;
            }
            else 
                carry = 0;
            tmp->val = sum;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }

        while(l2)
        {
            ListNode *tmp = new ListNode();
            int sum = l2->val + carry;
            if(sum >= 10)
            {
                carry = 1;
                sum = sum - 10;
            }
            else 
                carry = 0;
            tmp->val = sum;
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }      

        if(carry)
        {
            ListNode *tmp = new ListNode();
            tmp->val = 1;
            cur->next = tmp;
        }

        return head->next;
    }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *pre = new ListNode();
       ListNode *cur = pre;

       int flag = 0;
       while(l1 != nullptr && l2 != nullptr)
       {
            int sum = l1->val + l2->val + flag;
            flag = sum/10;
            l1->val = sum % 10;
            cur->next = l1;
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
       }

       while(l1)
       {
            int sum = l1->val + flag;
            flag = sum/10;
            l1->val = sum % 10;
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;   
       }

       while(l2)
       {
            int sum = l2->val + flag;
            flag = sum/10;
            l2->val = sum % 10;
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;    
       }

       if(flag)
       {
            ListNode *next_pre = new ListNode(flag);
            cur->next = next_pre;
       }

       return pre->next;
    }
};


























