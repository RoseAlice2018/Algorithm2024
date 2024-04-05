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
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dic;
        if(s.size() == 0) return 0;

        int left = 0, right = 0;
        dic.insert(s[left]); 
        right++;

        int ret = 1;
        while(right < s.size())
        {
            while(dic.count(s[right]))
            {
                dic.erase(s[left]);
                left++;
            }

            dic.insert(s[right]);
            ret = right - left + 1 > ret ? right - left + 1 : ret;
            right++;
        }

        return ret;
    }
};