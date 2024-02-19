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
    bool isDup(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(((root1 == nullptr) && !(root2 == nullptr)) ||  (!(root1 == nullptr) && (root2 == nullptr)))
            return false;

        if(root1->val == root2->val)
        {
            return isDup(root1->left, root2->left) && isDup(root1->right, root2->right);
        }

        return false;
    }

    vector<TreeNode*> ret;
    void helper(TreeNode *root)
    {
        if(root == nullptr) return;

        if(isDup(root->left, root->right) && root->left != nullptr)
        {
            ret.push_back(root->left);
        }
        helper(root->left);
        helper(root->right);
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return ret;
    }
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {ret.begin(), ret.end()};
    }

    string dfs(TreeNode *root)
    {
        if(root == nullptr)
            return "";
        
        string ans = to_string(root->val) + "(" + dfs(root->left) + ")" + "(" + dfs(root->right) + ")";

        auto iter = dic.find(ans);
        if(iter != dic.end())
        {
            ret.insert(iter->second);
        }
        else 
            dic[ans] = root;

        return ans;
    }

    unordered_map<string, TreeNode*> dic;
    unordered_set<TreeNode*> ret;
};


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        auto tri = tuple{node->val, dfs(node->left), dfs(node->right)};
        if (auto it = seen.find(tri); it != seen.end()) {
            repeat.insert(it->second.first);
            return it->second.second;
        }
        else {
            seen[tri] = {node, ++idx};
            return idx;
        }
    }

private:
    static constexpr auto tri_hash = [fn = hash<int>()](const tuple<int, int, int>& o) -> size_t {
        auto&& [x, y, z] = o;
        return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
    };

    unordered_map<tuple<int, int, int>, pair<TreeNode*, int>, decltype(tri_hash)> seen{0, tri_hash};
    unordered_set<TreeNode*> repeat;
    int idx = 0;
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/find-duplicate-subtrees/solutions/1798953/xun-zhao-zhong-fu-de-zi-shu-by-leetcode-zoncw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。