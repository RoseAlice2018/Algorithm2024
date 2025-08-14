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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       queue<TreeNode*> layer;
       if(root == nullptr) return 0;
       layer.push(root);
       int max_node = 1;
       while(!layer.empty())
       {
            int size = layer.size();
            int first_node = -1, second_node = -1;
            for(int i = 0; i < size; i++)
            {
                TreeNode *node = layer.front();
                layer.pop();
                if(node != nullptr)
                {
                    if(first_node == -1)
                        first_node = i;
                    else 
                    {
                        second_node = i;
                        int diff = second_node - first_node + 1;
                        max_node = max(max_node, diff);
                    }
                    if(node->left) { layer.push(node->left);}
                    else {layer.push(nullptr);}
                    if(node->right)
                    {
                        layer.push(node->right);
                    }
                    else
                    {
                        layer.push(nullptr);
                    }
                }
                else{
                    layer.push(nullptr);
                    layer.push(nullptr);
                }
            }
            if(first_node == -1)
                break;
       } 
       return max_node;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.emplace_back(root, 1L);
        while(!arr.empty())
        {
            vector<pair<TreeNode *, unsigned long long>> tmp;
            for(auto &[node, index] : arr)
            {
                if(node->left){
                    tmp.emplace_back(node->left, index * 2);
                }
                if(node->right)
                {
                    tmp.emplace_back(node->right, index * 2 + 1);
                }
            }
            res = max(res, arr.back().second - arr[0].second + 1);
            arr = std::move(tmp);
        }
        return res;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
        // 方便处理 nums[-1] 以及 nums[n] 的边界情况
        auto get = [&](int i) -> pair<int, int> {
            if (i == -1 || i == n) {
                return {0, 0};
            }
            return {1, nums[i]};
        };

        int left = 0, right = n - 1, ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1)) {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/find-peak-element/solutions/998152/xun-zhao-feng-zhi-by-leetcode-solution-96sj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &ret)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            // leaf
            if(root->val == targetSum)
            {
                path.push_back(root->val);
                ret.push_back(path);
                path.pop_back();
                return;
            }
            return;
        }
        //left
        if(root->left)
        {
            path.push_back(root->val);
            dfs(root->left, targetSum - root->val,path, ret);
            path.pop_back();
        }
        if(root->right)
        {
            path.push_back(root->val);
            dfs(root->right, targetSum - root->val,path, ret);
            path.pop_back();   
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ret;
        if(root == nullptr) return ret;
        dfs(root, targetSum, path, ret);
        return ret;
    }
};