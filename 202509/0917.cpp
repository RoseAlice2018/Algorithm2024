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
    int binarysearch(vector<int>& nums, int left, int right)
    {
        if(left > right) return -1;
        int mid = (left + right) / 2;
        
        if(mid == 0 && nums[mid] > nums[mid+1])
            return mid;
        else if(mid == 0)
            return binarysearch(nums, mid + 1, right);
        if(mid == nums.size()-1 && nums[mid] > nums[mid - 1])
            return mid;
        else if(mid == nums.size() - 1)
            return binarysearch(nums, left, mid-1);
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        if(nums[mid-1] <= nums[mid] && nums[mid] <= nums[mid+1])
        {
            return binarysearch(nums, mid+1, right);
        }
        else{
            return binarysearch(nums, left, mid-1);
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int ret = binarysearch(nums, 0, nums.size()-1);
        return ret;
    }
};










