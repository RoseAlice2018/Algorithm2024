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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dumpy = new ListNode();
        ListNode *cur = dumpy;

        priority_queue<ListNode*, vector<ListNode*>, std::function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode *a, ListNode *b)->bool{ return a->val > b->val; });

        for(auto head : lists)
        {
            if(head !=  nullptr)
                pq.push(head);
        }

        while(!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if(top->next != nullptr)
                pq.push(top->next);
        }

        return dumpy->next;

    }
};