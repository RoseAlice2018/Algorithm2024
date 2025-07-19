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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        ListNode *pre = new ListNode(0);
        ListNode *head = pre;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                pre->next = list1;
                list1 = list1->next;
            }
            else 
            {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        while(list1)
        {
            pre->next = list1;
            list1 = list1->next;
            pre = pre->next;
        }
        while(list2)
        {
            pre->next = list2;
            list2 = list2->next;
            pre = pre->next;
        }
        return head->next;
    }
};