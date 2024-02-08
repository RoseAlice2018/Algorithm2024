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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dump1 = new ListNode(0); // 存放>= x的节点
        ListNode *dump2 = new ListNode(0); // 存放 < x的节点
        ListNode *p1 = dump1;
        ListNode *p2 = dump2;

        ListNode *cur = head;
        while(cur != nullptr)
        {
            if(cur->val >=  x)
            {
                p1->next = cur;
                p1 = p1->next;
            }
            else if(cur->val < x)
            {
                p2->next = cur;
                p2 = p2->next;
            }

            //注意这里要断开原链表的节点，不然最后的节点会形成环 参考：https://labuladong.online/algo/di-yi-zhan-da78c/shou-ba-sh-8f30d/shuang-zhi-0f7cc/#%E5%8D%95%E9%93%BE%E8%A1%A8%E7%9A%84%E5%88%86%E8%A7%A3
            ListNode *temp = cur->next;
            cur->next = nullptr;
            cur = temp;
        }
        
        p2->next = dump1->next;
        return dump2->next;
    }
};