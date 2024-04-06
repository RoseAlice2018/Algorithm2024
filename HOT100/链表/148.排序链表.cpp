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

// 超时
class Solution {
public:
    ListNode *insertOneNode(ListNode *A, ListNode *head)
    {
        if(A->val <= head->val)
        {
            A->next = head;
            return A;
        }
        ListNode *cur = head->next;
        ListNode *pre = head;
        while(cur != nullptr && cur->val < A->val)
        {
            pre = cur;
            cur = cur->next;
        }

        pre->next = A;
        A->next = cur;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *tmp = sortList(head->next);

        return insertOneNode(head, tmp);
    }
};
