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
    std::pair<ListNode*, ListNode*> reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {pre, head};
    }

    std::pair<ListNode*, ListNode*> _reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        for(int i = 0; i < k; i++)
        {
            if(cur)
            {
                pre = cur;
                cur = cur->next;
            }
            else{
                return {head, pre};
            }
        }
        pre->next = nullptr;
        std::pair<ListNode*, ListNode*> ret = reverseList(head);
        std::pair<ListNode*, ListNode*> next = _reverseKGroup(cur, k);
        ret.second->next = next.first;
        return {ret.first, next.second};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 or head == nullptr)
            return head;
        std::pair<ListNode*, ListNode*> ret = _reverseKGroup(head, k);
        return ret.first;
    }
};