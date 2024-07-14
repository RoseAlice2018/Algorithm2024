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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
                continue;
            }
            else 
            {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
                continue;
            }
        }   

        while(list1)
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }

        while(list2)
        {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }

        return head->next;
    }
};






class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                cur->next = list1;
                //list1 ->
                list1 = list1->next;
            }
            else if(list1->val > list2->val)
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        while(list1)
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }

        while(list2)
        {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }

        return head->next;
    }
};

























