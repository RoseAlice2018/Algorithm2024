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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dic;
        for(int num : nums)
            dic.insert(num);
        
        int ret = 0;
        for(int num : nums)
        {
            if(!dic.count(num - 1))
            {
                int current = 1;

                int begin = num + 1;
                while(dic.count(begin))
                {
                    begin++;
                    current++;
                }

                if(current > ret)
                    ret = current;
            }
        }
        return ret;
    }
};