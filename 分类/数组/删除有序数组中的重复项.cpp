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
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != nums[slow])
            {
                slow++;
                nums[slow] = nums[i];
            }
        }

        return slow + 1;
    }
};