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
    int binary_search(vector<int> &nums, int target, int left, int right)
    {
        if(left > right) return -1;
        int mid = (right + left) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            return binary_search(nums, target, mid + 1, right);
        }
        else{
            return binary_search(nums, target, left, mid - 1);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       return binary_search(nums, target, 0, nums.size() - 1); 
    }
};