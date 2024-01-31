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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> sufix;
        unordered_set<int> prefix;
        vector<int> sufix_count(nums.size() + 1);
        sufix_count[nums.size()] = 0;
        for(int i = nums.size() - 1; i >=0 ; --i)
        {
            sufix.insert(nums[i]);
            sufix_count[i] = sufix.size();
        }
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
            prefix.insert(nums[i]);
            res[i] = prefix.size() - sufix_count[i + 1];
        }

        return res;
    }
}; 