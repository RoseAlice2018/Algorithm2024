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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> layer;
        layer.push(root);
        layer.push(nullptr);
        vector<int> layer_ans;
        while(!layer.empty())
        {
            TreeNode *first = layer.front();
            layer.pop();
            if(first)
            {
                if(first->left)
                    layer.push(first->left);
                if(first->right)
                    layer.push(first->right);
                layer_ans.push_back(first->val);
            }
            else 
            {
                ans.push_back(layer_ans);
                layer_ans.clear();
                if(!layer.empty())
                    layer.push(nullptr);
            }
        }
        return ans;
    }
};

// 更快的解法 核心在于减少拷贝的消耗
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> layer;
        layer.push(root);

        while(!layer.empty())
        {
            int size = layer.size();
            vector<int> layer_ans;
            layer_ans.reserve(size);

            for(int i = 0; i < size; i++)
            {
                TreeNode *f = layer.front();
                layer.pop();
                layer_ans.emplace_back(f->val);
                if(f->left)
                    layer.push(f->left);
                if(f->right)
                    layer.push(f->right);
            }
            ans.emplace_back(std::move(layer_ans));
        }
        return ans;
    }
};


class Solution {
public:
    int deepsearch(vector<int>& nums, int target, int left, int right)
    {
        std::cout<<left<<" "<<right<<std::endl;
        if(left >= right)
        {
            if(nums[left] == target)
            {
                return left;
            }
            return -1;
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;

        if(target < nums[mid])
        {
            if(nums[mid] > nums[right]){
                return deepsearch(nums, target, mid + 1, right);
            }
            else{
                return deepsearch(nums, target, left, mid - 1);
            }
        } 
        else{
            if(target > nums[right])
            {
                if(nums[mid] >= nums[left])
                    return deepsearch(nums, target, mid + 1, right);
                else{
                    return deepsearch(nums, target, left, mid - 1);
                }
            }
            else {
                return deepsearch(nums, target, mid + 1, right);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return deepsearch(nums, target, 0, nums.size() - 1);
    }
};