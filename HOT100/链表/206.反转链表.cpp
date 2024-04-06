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
    ListNode * reverse(ListNode *pre, ListNode *cur)
    {
        if(cur == nullptr) return nullptr;
        ListNode *next = cur->next;
        cur->next = pre;
        if(next == nullptr) return cur;
        pre = cur;
        cur = next;
        return reverse(pre, cur);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *dump  = nullptr;
        return reverse(dump, head);
    }
};