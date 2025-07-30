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
private:
    static constexpr int SEG_COUNT = 4;

private:
    vector<string> ans;
    vector<int> segments;

public:
    void dfs(const string& s, int segId, int segStart) {
        // 如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
        if (segId == SEG_COUNT) {
            if (segStart == s.size()) {
                string ipAddr;
                for (int i = 0; i < SEG_COUNT; ++i) {
                    ipAddr += to_string(segments[i]);
                    if (i != SEG_COUNT - 1) {
                        ipAddr += ".";
                    }
                }
                ans.push_back(move(ipAddr));
            }
            return;
        }

        // 如果还没有找到 4 段 IP 地址就已经遍历完了字符串，那么提前回溯
        if (segStart == s.size()) {
            return;
        }

        // 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
        if (s[segStart] == '0') {
            segments[segId] = 0;
            dfs(s, segId + 1, segStart + 1);
            return;
        }

        // 一般情况，枚举每一种可能性并递归
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segments[segId] = addr;
                dfs(s, segId + 1, segEnd + 1);
            } else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head == NULL || fast == NULL) return head;
        while(true)
        {
            slow = slow->next;
            if(slow == NULL)
                return slow;
            if(fast == NULL || fast->next == NULL)
                return NULL;
            fast = fast->next->next;
            if(fast == slow)
                break;
        }
        ListNode *begin = head;
        while(slow != begin)
        {
            slow = slow->next;
            begin = begin->next;
        }
        return slow;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1000);
        dummy->next = head;
        if(!head || !head->next)
            return head;
        ListNode *pre = dummy;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *_next = cur->next;
            if(!_next) 
                break;
            if(cur->val == _next->val)
            {
                while(_next->val == cur->val)
                {
                    _next = _next->next;
                    if(!_next)
                        break;
                }
                pre->next = _next;
                cur = _next;
            }
            else{
                pre = cur;
                cur = _next;
            }
        }
        return dummy->next;
    }
};