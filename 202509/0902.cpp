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
    int removeDuplicates(vector<int>& nums) {
        int num_size = nums.size();
        if(num_size <= 1) return num_size;
        int valid_index = 1;
        int pre_index = 0;
        for(int i = 1; i < num_size; i++)
        {
            if(nums[i] == nums[pre_index])
            {
                continue;
            }
            else{
                swap(nums[i], nums[valid_index]);
                valid_index++;
                pre_index++;
            }
        }
        return valid_index;
    }
};