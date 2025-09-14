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
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(m == 0 || n == 0) return n+m;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }

        for(int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                int left = dp[i-1][j] + 1;
                int right = dp[i][j-1] + 1;
                int replace = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) replace++;

                dp[i][j] = min(left, min(right, replace));
            }
        }

        return dp[m][n];
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
    struct Status{
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const{
            return val > rhs.val;
        };
    };
    priority_queue<Status> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node: lists){
            if(node) q.push({node->val, node});
        }

        ListNode head;
        ListNode *tail = &head;
        
        while(!q.empty())
        {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if(f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }

        return head.next;
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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if(head == nullptr)
        {
            return head;
        }
        if(head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != tail)
        {
            if(fast->next == tail)
                break;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode *merge(ListNode *A, ListNode *B)
    {
        ListNode *dummy_head = new ListNode(-1);
        ListNode *cur = dummy_head;
        ListNode *temp1 = A, *temp2 = B;
        while(temp1!= nullptr && temp2 != nullptr)
        {
            if(temp1->val < temp2->val)
            {
                cur->next = temp1;
                cur = cur->next;
                temp1 = temp1->next;
            }
            else{
                cur->next = temp2;
                cur = cur->next;
                temp2 = temp2->next;
            }
        }

        while(temp1)
        {
            cur->next = temp1;
            cur = cur->next;
            temp1 = temp1->next;
        }

        while(temp2)
        {
            cur->next = temp2;
            cur = cur->next;
            temp2 = temp2->next;
        }

        return dummy_head->next;
    }
};